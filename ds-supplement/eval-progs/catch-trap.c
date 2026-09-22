#include "CH56x_common.h"
#include "CH56x_sys.h"

#define  FREQ_SYS   80000000

volatile UINT8 cp;

static void tohex(UINT8 v, char *out, const bool cap)
{
	UINT8 n;
	UINT8 m[2] = { 0xF0, 0x0F };
	UINT8 s[2] = { 4, 0 };
	const char letter = cap ? 'F' : 'f';

	for (int i = 0; i < 2; i++) {
		n = (v & m[i]) >> s[i];

		if (n <= 0x09)
			*out = '0' + n;
		else
			*out = letter - (0x0F - n);
		out++;
	}
}

static char *putstr(const char *s, char *out)
{
	while (*s != 0)
		*(out++) = *(s++);

	return out;
}

static char *putword(UINT32 v, char *out, const bool cap)
{
	tohex((UINT8)((v & 0xFF000000) >> 24), out, cap);
	out += 2;
	tohex((UINT8)((v & 0x00FF0000) >> 16), out, cap);
	out += 2;
	tohex((UINT8)((v & 0x0000FF00) >>  8), out, cap);
	out += 2;
	tohex((UINT8)((v & 0x000000FF) >>  0), out, cap);
	out += 2;

	return out;
}

__attribute__((interrupt("machine")))
void HardFault_Handler(void)
{
	static char buf[256];
	char *ptr = buf;
	size_t len;

	memset(buf, '@', sizeof(buf));

	ptr = putstr("fault:\n", ptr);
	ptr = putstr("mepc: ", ptr);
	ptr = putword(__get_MEPC(), ptr, true);
	ptr = putstr("\n", ptr);
	ptr = putstr("cause: ", ptr);
	ptr = putword(__get_MCAUSE(), ptr, true);
	ptr = putstr("\n", ptr);
	ptr = putstr("mtval: ", ptr);
	ptr = putword(__get_MTVAL(), ptr, true);
	ptr = putstr("\n\n", ptr);

	GPIOB_ModeCfg(GPIO_Pin_22, GPIO_ModeOut_OP_8mA);
	GPIOB_ModeCfg(GPIO_Pin_23, GPIO_ModeOut_OP_8mA);
	GPIOB_ModeCfg(GPIO_Pin_24, GPIO_ModeOut_OP_8mA);
	GPIOB_SetBits(GPIO_Pin_22);
	GPIOB_SetBits(GPIO_Pin_23);
	GPIOB_SetBits(GPIO_Pin_24);

	for (UINT8 i = 0; i < 3; i++) {
		if (cp & 1)
			GPIOB_ResetBits(GPIO_Pin_22 << i);
		cp >>= 1;
	}

	len = ptr - buf;
	if (0 < len && len < sizeof(buf)) {
		for (size_t i = 0; i < len; i++) {
			while (R8_UART1_TFC == UART_FIFO_SIZE);
			R8_UART1_THR = buf[i];
		}

		while (R8_UART1_TFC > 0); /* wait for FIFO flush */
	}

	mDelaymS(10);

	for(;;)
		LowPower_Halt_WFE();
}

static void init_stdio_metal(void)
{
#if defined(DEBUG) && DEBUG >= 0
	static const struct ch56x_stdio_desc desc[3] = {
		{ },
		{115200, DEBUG, 1, 1},
		{115200, DEBUG, 1, 1}
	};

	ch56x_stdio_open(desc, FREQ_SYS);
#endif
}

struct s {
	long a;
};

/*
 * If you make this function static, the compiler will optimise in byte-by-byte
 * loads. Currently(GCC version 16.1.0), -mno-strict-align has no effect on this
 * function and -munaligned-access is not implemented for RISC-V.
 *
 * This is an inherent design error in the RISC-V specs.
 */
__attribute__((noinline))
/* static */ void test_unaligned_access(volatile struct s *ptr, volatile const uint8_t *buf)
{
	printf("The processor supports unaligned loads?\n");
	ptr->a = 123;
	printf("yes: %ld at %zx (%02x %02x %02x %02x %02x)\n",
			ptr->a, (uintptr_t)ptr, buf[0], buf[1], buf[2], buf[3], buf[4]);
}

int main()
{
	unsigned int a = 0;

	SystemInit(FREQ_SYS);
	Delay_Init(FREQ_SYS);
	init_stdio_metal();

	cp = 0;

	GPIOB_ModeCfg(GPIO_Pin_22, GPIO_ModeOut_OP_8mA);
	GPIOB_ModeCfg(GPIO_Pin_23, GPIO_ModeOut_OP_8mA);
	GPIOB_ModeCfg(GPIO_Pin_24, GPIO_ModeOut_OP_8mA);
	GPIOB_SetBits(GPIO_Pin_22);
	GPIOB_SetBits(GPIO_Pin_23);
	GPIOB_SetBits(GPIO_Pin_24);

	/* Check traps from stdio functions */
	PRINT("hello, world!\n");

	cp++;

	if (false) {
		static volatile uint8_t buf[sizeof(struct s) + 1];

		test_unaligned_access((volatile void*)(buf + 1), buf);
	}

	cp++;

	if (true) {
		/* Dump bss to check if it's initialised to zeros */
		static uint8_t buf[64];
		bool newline = false;

		for (size_t i = 0; i < sizeof(buf); i++) {
			printf("%02x ", buf[i]);
			if ((i + 1) % 24 == 0) {
				newline = true;
				printf("\n");
			} else
				newline = false;
		}
		if (!newline)
			printf("\n");
	}

	cp++;

	for (;;) {
		switch (a) {
		case 0:
			GPIOB_ResetBits(GPIO_Pin_22);
			GPIOB_SetBits(GPIO_Pin_23);
			GPIOB_SetBits(GPIO_Pin_24);

			break;
		case 1:
			GPIOB_SetBits(GPIO_Pin_22);
			GPIOB_ResetBits(GPIO_Pin_23);
			GPIOB_SetBits(GPIO_Pin_24);
			break;
		case 2:
			GPIOB_SetBits(GPIO_Pin_22);
			GPIOB_SetBits(GPIO_Pin_23);
			GPIOB_ResetBits(GPIO_Pin_24);
			break;
		}

		a = (a + 1) % 3;

		mDelaymS(250);
	}
}
