/*****************************************************************
*************
* Skeleton code for assembly.
******************************************************************
************/
.text # executable code follows
.global main
main:

movia r3, 0x5010
movia r4, 0x5000
movia r5, 0xFF
movia r6, 0x01

loop:
stwio r6, 0(r4)
stwio r5, 0(r3)
stwio r0, 0(r4)
br loop
