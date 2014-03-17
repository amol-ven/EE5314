.include "p33FJ128MC802.inc"

.global __delay_us
.global __delay_ms

;Delay routines for Fcy = 40MHz
.text
__delay_us:
            repeat #29
            nop
loop_us:    dec W0, W0
            bra z, end_ms
            repeat #34
            nop
            bra loop_us
end_ms:        return




__delay_ms:
            mov W0, W1
loop_ms:    mov #1000, W0
            call __delay_us
            dec W1, W1
            bra nz, loop_ms
            return;
.end