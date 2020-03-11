#include <clock.h>

.global system_clock_init
system_clock_init:
    push {lr}

    /*PLL REFER*/
    ldr r0, =APLL_CON1
    ldr r1, =0x00803800
    str r1, [r0]
    ldr r0, =APLL_CON0
    ldr r1, =(1<<31 | APLL_MDIV << 16 | APLL_PDIV << 8 | APLL_SDIV << 0x0)
    str r1, [r0]

    ldr r0, =MPLL_CON1
    ldr r1, =0x00803800
    str r1, [r0]
    ldr r0, =MPLL_CON0
    ldr r1, =(1<<31 | MPLL_MDIV << 16 | MPLL_PDIV << 8 | MPLL_SDIV << 0x0)
    str r1, [r0]

    //ldr r0, =EPLL_CON1
    //ldr r1, =EPLL_CON2
    //ldr r2, =0x66010000
    //ldr r3, =0x00000080
    //str r2, [r0]
    //str r3, [r1]
    //ldr r0, =EPLL_CON0
    //ldr r1, =
    //str r1, [r0]

    //ldr r0, =VPLL_CON1
    //ldr r1, =VPLL_CON2
    //ldr r2, =0x66010000
    //ldr r3, =0x00000080
    //str r2, [r0]
    //str r3, [r1]
    //ldr r0, =VPLL_CON0
    //ldr r1, =
    //str r1, [r0]

    ldr r0, =APLL_LOCK
    ldr r1, =(APLL_PDIV * 270)
    str r1, [r0]

    ldr r0, =MPLL_LOCK
    ldr r1, =(MPLL_PDIV * 270)
    str r1, [r0]

    //ldr r0, =EPLL_LOCK
    //ldr r1, =
    //str r1, [r0]

    //ldr r0, =VPLL_LOCK
    //ldr r1, =
    //str r1, [r0]

    /*SRC REFER*/
    ldr r0, =CLK_SRC_CPU
    ldr r1, =0x01000001
    str r1, [r0]

    ldr r0, =CLK_SRC_DMC
    ldr r1, =0x00011000
    str r1, [r0]

    ldr r0, =CLK_SRC_TOP0
    ldr r1, =0x00000110
    str r1, [r0]

    ldr r0, =CLK_SRC_TOP1
    ldr r1, =0x01111000
    str r1, [r0]

    ldr r0, =CLK_SRC_LEFTBUS
    ldr r1, =0x10
    str r1, [r0]

    ldr r0, =CLK_SRC_RIGHTBUS
    ldr r1, =0x10
    str r1, [r0]

    /*DIV refer*/
    ldr r0, =CLK_DIV_CPU0 
    ldr r1, =((0x0 << 28) | (0x2 << 24) | (0x1 << 20) | (0x6 << 16) | (0x7 <<12) | (0x7 << 8) | (0x3 << 4) | (0x0))
    str r1, [r0]

    ldr r0, =CLK_DIV_CPU1
    ldr r1, =((0x5 << 8) |(0x0 << 4) | (0x6))
    str r1, [r0]

    ldr r0, =CLK_DIV_DMC0
    ldr r1, =((0x0 << 28) | (0x0 << 24) | (0x1 << 20) | (0x1 << 16) | (0x1 << 12) | (0x1 << 8) | (0x1 << 4) | (0x3))
    str r1, [r0]

    ldr r0, =CLK_DIV_DMC1
    ldr r1, =0x07071713
    str r1, [r0]

    ldr r0, =CLK_DIV_TOP
    ldr r1, =((0x1 << 24) | (0x2 << 20) | (0x1 << 16) | (0x5 << 12) | (0x4 << 8) | (0x7 << 4) | (0x4))
    str r1, [r0]

    ldr r0, =CLK_DIV_LEFTBUS
    ldr r1, =((0x1 << 4) | (0x3))
    str r1, [r0]

    ldr r0, =CLK_DIV_RIGHTBUS
    ldr r1, =((0x1 << 4) | (0x3))
    str r1, [r0]

    pop {pc}
