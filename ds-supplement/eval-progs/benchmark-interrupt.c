/* SPDX-License-Identifier: Apache License 2.0 */
/*
 * Copyright 2026 David Timber
 */
/*
 * Benchmark interrupts on CH56x processor
 *
 *  1. Reset the SysTick and start it
 *  2. Intentional cause interrupt
 *  3. In the ISR(interrupt service routine), measure the ticks elapsed
 *     and before returning, restart the ticker
 *  4. When the ISR returns, measure the ticks elapsed
 */
#include <CH56x_common.h>
#include <CH56x_sys.h>
#include <stdbool.h>

#define USE_WCH_FPIC_HACK 0

#if USE_WCH_FPIC_HACK == 1
/* Set to 1: use the hack */

#define IMPL_WCH_ISR_STR(a) #a
#define IMPL_WCH_ISR_XSTR(a) IMPL_WCH_ISR_STR(a)
#define IMPL_WCH_ISR_CONCAT(a, b) a##b
#define IMPL_WCH_ISR(__name) \
	__attribute__((naked)) \
	__attribute__((noreturn)) \
	void __name(void) \
	{\
		asm volatile ("call " \
			IMPL_WCH_ISR_XSTR(IMPL_WCH_ISR_CONCAT(__name, _inner)));\
		asm volatile ("mret");\
	}\
	__attribute__((noinline))\
	void IMPL_WCH_ISR_CONCAT(__name, _inner)(void)\

#elif USE_WCH_FPIC_HACK == 2
/* Set to 2: use "WCH-Interrupt-fast"(compat with WCH's GCC) */

#define IMPL_WCH_ISR(__name)\
	__attribute__((interrupt("WCH-Interrupt-fast"))) void __name(void)

#elif USE_WCH_FPIC_HACK == 0
/* Set to 0: use GCC's standard RISC-V ISR  */

#define IMPL_WCH_ISR(__name)\
	__attribute__((interrupt)) void __name(void)

#else

#error "Check USE_WCH_FPIC_HACK"

#endif

void DebugInit(UINT32 t, UINT32 baudrate)
{
	UINT32 x;

	x = 10 * t * 2 / 16 / baudrate;
	x = ( x + 5 ) / 10;
	R8_UART1_DIV = 1;
	R16_UART1_DL = x;
	R8_UART1_FCR = RB_FCR_FIFO_TRIG | RB_FCR_TX_FIFO_CLR | RB_FCR_RX_FIFO_CLR | RB_FCR_FIFO_EN;
	R8_UART1_LCR = RB_LCR_WORD_SZ;
	R8_UART1_IER = RB_IER_TXD_EN;
	R32_PA_SMT |= (1<<8) |(1<<7);
	R32_PA_DIR |= (1<<8);
}
__attribute__((always_inline))
static inline void start_ticker(void)
{
	/* The intermediate register */
	SysTick->CMP = UINT64_MAX;
	/*
	 * 8: Load the counter with the new value
	 * 1: use HCLK(SYSFREQ)
	 * 0: enable
	 */
	SysTick->CTLR = (1 << 8) | (1 << 2) | (1 << 0);
}

__attribute__((always_inline))
static inline uint64_t stop_ticker(void)
{
	SysTick->CTLR = 0;
	return UINT64_MAX - SysTick->CNT;
}

volatile bool handled;

__attribute__((always_inline))
static inline void on_interrupt(const char *what)
{
	printf("%s: %10u ", what, (unsigned)stop_ticker());
	handled = true;
}

__attribute__((always_inline))
static inline void do_interrupt_test(PUINT32V trigger32,
		const uint32_t bits32, PUINT8V trigger8, const uint8_t bits8)
{
	handled = false;

	start_ticker();
	if (trigger32 != NULL)
		*trigger32 |= bits32;
	if (trigger8 != NULL)
		*trigger8 |= bits8;

	while (!handled);

	printf("%10u\n", (unsigned)stop_ticker());
}

IMPL_WCH_ISR(SW_Handler)
{
	on_interrupt("SW  ");
	SysTick->CNTFG = 0;
	start_ticker();
}

IMPL_WCH_ISR(TMR0_IRQHandler)
{
	on_interrupt("TMR0");
	R8_TMR0_INTER_EN = 0;
	R8_TMR0_CTRL_MOD = RB_TMR_ALL_CLEAR;
	start_ticker();
}

IMPL_WCH_ISR(TMR1_IRQHandler)
{
	on_interrupt("TMR1");
	R8_TMR1_INTER_EN = 0;
	R8_TMR1_CTRL_MOD = RB_TMR_ALL_CLEAR;
	start_ticker();
}

IMPL_WCH_ISR(TMR2_IRQHandler)
{
	on_interrupt("TMR2");
	R8_TMR2_INTER_EN = 0;
	R8_TMR2_CTRL_MOD = RB_TMR_ALL_CLEAR;
	start_ticker();
}

__attribute__((noinline))
static void do_test_at(unsigned int freq)
{
	SystemInit(freq);
	Delay_Init(freq);
	DebugInit(freq, 115200);
	fprintf(stderr, "Interrupt benchmark @%uHz:\n", freq);

	/* Setting the second bit of SysTick->CNTFG triggers sw int */
	do_interrupt_test(&SysTick->CNTFG, 1, NULL, 0);

	/* The initialisation order matters */

	R32_TMR0_CNT_END = 100;
	R8_TMR0_CTRL_MOD = 0;
	R8_TMR0_INTER_EN = RB_TMR_IE_CYC_END;
	do_interrupt_test(NULL, 0, &R8_TMR0_CTRL_MOD, RB_TMR_COUNT_EN);
	R8_TMR0_CTRL_MOD = RB_TMR_ALL_CLEAR;

	R32_TMR1_CNT_END = 200;
	R8_TMR1_CTRL_MOD = 0;
	R8_TMR1_INTER_EN = RB_TMR_IE_CYC_END;
	do_interrupt_test(NULL, 0, &R8_TMR1_CTRL_MOD, RB_TMR_COUNT_EN);
	R8_TMR1_CTRL_MOD = RB_TMR_ALL_CLEAR;

	R32_TMR2_CNT_END = 300;
	R8_TMR2_CTRL_MOD = 0;
	R8_TMR2_INTER_EN = RB_TMR_IE_CYC_END;
	do_interrupt_test(NULL, 0, &R8_TMR2_CTRL_MOD, RB_TMR_COUNT_EN);
	R8_TMR2_CTRL_MOD = RB_TMR_ALL_CLEAR;

	fflush(stdout);
	fflush(stderr);
	mDelaymS(50);
}

#define START_SYSFREQ (15000000)

__attribute__((noreturn))
int main(void)
{
	PFIC_EnableIRQ(SWI_IRQn);
	PFIC_EnableIRQ(TMR0_IRQn);
	PFIC_EnableIRQ(TMR1_IRQn);
	PFIC_EnableIRQ(TMR2_IRQn);

	SystemInit(START_SYSFREQ);
	Delay_Init(START_SYSFREQ);
	DebugInit(START_SYSFREQ, 115200);

	fprintf(stderr, "USE_WCH_FPIC_HACK: %d\n", USE_WCH_FPIC_HACK);
	fflush(stdout);
	fflush(stderr);
	mDelaymS(100);

	do_test_at(120000000);
	do_test_at(96000000);
	do_test_at(80000000);
	do_test_at(60000000);
	do_test_at(30000000);
	do_test_at(15000000);

	printf("\n");
	fflush(stdout);
	fflush(stderr);
	mDelaymS(100);

	for(;;)
		LowPower_Halt_WFE();
}
