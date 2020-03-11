#ifndef __CLOCK_H__
#define __CLOCK_H__

// CMU_CPU
#define CLK_SRC_CPU         0x10044200
#define CLK_DIV_CPU0        0x10044500
#define CLK_DIV_CPU1        0x10044504
// CMU_DMC
#define CLK_SRC_DMC         0x10040200
#define CLK_DIV_DMC0        0x10040500
#define CLK_DIV_DMC1        0x10040504
// CMU_TOP
#define CLK_SRC_TOP0        0x1003C210
#define CLK_SRC_TOP1        0x1003C214
#define CLK_DIV_TOP         0x1003C510
// CMU_LEFTBUS
#define CLK_SRC_LEFTBUS     0x10034200
#define CLK_DIV_LEFTBUS     0x10034500
// CMU_RIGHTBUS
#define CLK_SRC_RIGHTBUS    0x10038200
#define CLK_DIV_RIGHTBUS    0x10038500
// locktime
#define APLL_LOCK           0x10044000
#define MPLL_LOCK           0x10044008
#define EPLL_LOCK           0x1003C010
#define VPLL_LOCK           0x1003C020
// APLL
#define APLL_CON1           0x10044104
#define APLL_CON0           0x10044100
// MPLL
#define MPLL_CON0           0x10040108
#define MPLL_CON1           0x1004010c
// EPLL
#define EPLL_CON2           0x1003C118
#define EPLL_CON1           0x1003C114
#define EPLL_CON0           0x1003C110
// VPLL
#define VPLL_CON0           0x1003C120
#define VPLL_CON1           0x1003C124
#define VPLL_CON2           0x1003C128 

/*APLL Fout = 1.4GHz*/
#define APLL_SDIV 0     
#define APLL_PDIV 3
#define APLL_MDIV 175

/*MPLL Fout = 800MHz*/
#define MPLL_SDIV 0
#define MPLL_PDIV 3
#define MPLL_MDIV 100

/*EPLL Fout = XMHz 待定*/
#define EPLL_SDIV 
#define EPLL_PDIV 
#define EPLL_MDIV 

/*VPLL Fout = XMHz 待定*/
#define VPLL_SDIV 
#define VPLL_PDIV 
#define VPLL_MDIV 

#endif /*__CLOCK_H__*/
