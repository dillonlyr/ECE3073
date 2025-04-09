/******************************************************************************
* Skeleton code for assembly.
******************************************************************************/

.text 							# executable code follows
.global		main
main:

movia r3, 0x5000
movia r4, 0xFF

loop:
stwio r4, 0(r3)
br loop
