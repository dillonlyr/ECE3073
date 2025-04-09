.include    "address_map_nios2.s"

/******************************************************************************
 * This program demonstrates use of parallel ports
 *
 * It performs the following:
 * 	1. displays a rotating pattern on the LEDs
 * 	2. if any KEY is pressed, the SW switches are used as the rotating pattern
 ******************************************************************************/

.text                           # executable code follows
.global     main
main:
		NOP
/* initialize base addresses of parallel ports */
        movia   r15, SW_BASE        # SW slider switch base address
        movia   r16, LED_BASE       # LED base address
        movia   r17, KEY_BASE       # pushbutton KEY base address
        movia   r18, LED_bits       
        ldwio   r6, 0(r18)          # load pattern for LED lights

DO_DISPLAY:                         
        ldwio   r4, 0(r15)          # load slider switches

        ldwio   r5, 0(r17)          # load pushbuttons
        beq     r5, r0, NO_BUTTON   
        mov     r6, r4              # copy SW switch values onto LEDs
        roli    r4, r4, 8           # the SW values are copied into the upper three
                                    # bytes of the pattern register
        or      r6, r6, r4          # needed to make pattern consistent as all
                                    # 32-bits of a register are rotated
        roli    r4, r4, 8           # but only the lowest 8-bits are displayed on
                                    # LEDs
        or      r6, r6, r4          
        roli    r4, r4, 8           
        or      r6, r6, r4          
WAIT:                               
        ldwio   r5, 0(r17)          # load pushbuttons
        bne     r5, r0, WAIT        # wait for button release

NO_BUTTON:                          
        stwio   r6, 0(r16)          # store to LED
        roli    r6, r6, 1           # rotate the displayed pattern

        movia   r7, 1500000         # delay counter
DELAY:                              
        subi    r7, r7, 1           
        bne     r7, r0, DELAY       

        br      DO_DISPLAY

EXTRA:
		nop
		nop
		nop
		nop
		nop

/******************************************************************************/
.data                           # data follows

LED_bits:                           
.word       0x0F0F0F0F          

.end                            
