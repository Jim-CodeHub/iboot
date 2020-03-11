#ifndef __UART_H__
#define __UART_H__

#define UART_BASE 0x13800000

//GPIO for UART
#define GPA0CON 0x11400000
#define GPA0DAT 0x11400004

//Clock for UART
#define CLK_SRC_PERIL0 0x1003C250
#define CLK_DIV_PERIL0 0x1003C550

//"8N1" for UART
#define ULCON(n)    (UART_BASE + (n*1000) + 0x0000)

//Mode for UART
#define UCON(n)     (UART_BASE + (n*1000) + 0x0004)

//FIFO for UART
#define UFCON(n)    (UART_BASE + (n*1000) + 0x0008)  

//Stat for UART
#define UTRSTAT(n)  (UART_BASE + (n*1000) + 0x0010)

//Data (Send) for UART
#define UTXH(n)     (UART_BASE + (n*1000) + 0x0020) 

//Data (Recv) for UART
#define URXH(n)     (UART_BASE + (n*1000) + 0x0024)

//Baud (1) for UART
#define UBRDIV(n)   (UART_BASE + (n*1000) + 0x0028)

//Baud (.) for UART
#define UFRACVAL(n) (UART_BASE + (n*1000) + 0x002C)

#endif /*__UART_H__*/

