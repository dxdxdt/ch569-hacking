# CH56x Hacking Notes

CH565 and CH565 are RISC-V based microcontrollers made by WCH. They
feature USBSS(3.0) and many other peripheral blocks.

**!! DO NOT buy this board !!**

I'm not saying this because I've had bad experience with the uc or the
manufacturer or anything. It's because a newer lineup, **CH32H41x**,
which features higher spec and lower unit price, is already on the
market(from May 2026). Unless there's a supply shortage or a special use
case, there's absolutely no reason to prototype a new product with CH56x
in 2026.

You have been warned.

If you still think you need to use CH56x in 2026 and you bought the
evaluation board anyways, here are the materials and resources.

| WHAT | LINK |
|-|-|
| Buy | https://aliexpress.com/item/1005005566535207.html |
| Datasheet | https://www.wch-ic.com/downloads/CH569DS1_PDF.html |
| EVB toolkit | https://www.wch.cn/downloads/CH569EVT_ZIP.html |
| MounRiver Studio | https://www.mounriver.com/download |
| Standalone ISP tool(optional) | https://www.wch-ic.com/downloads/WCHISPTool_CMD_ZIP.html |

Don't be intimidated by all the Chinese writings. The zip file should
also contain English docs.

As I've found that these materials are not sufficient, I've started this
repo to document what I've learned and help other devs crash course in
hacking the board.

## INDEX

I'll try to streamline the docs as a linked-list so you can walk through
them. Here's the list of docs in case you got lost.

  1. [Basics](00-basics/README.md)
  2. [Your First Blinker Program](01-blink-program/README.md)

## MORE

[Basics](00-basics/README.md) →
