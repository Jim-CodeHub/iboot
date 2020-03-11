#include <config.h>
#include <uart.h>

void uart_init(int n)
{
    SET_BIT(CLK_SRC_PERIL0, v32, 0, 3, 6);
    SET_BIT(CLK_DIV_PERIL0, v32, 0, 3, 7);
    SET_BIT(GPA0CON, v32, 0, 7, 0x22);
    SET_BIT(ULCON(n), v32, 0, 1, 0x3);
    SET_BIT(UBRDIV(n), v32,0, 15, 53);
    SET_BIT(UFRACVAL(n), v32, 0, 3,5);
    SET_BIT(UCON(n), v32, 0, 3,  0x5);
}

void uart_send(int n, char ch)
{
    while(!GET_BIT(UTRSTAT(n), v32, 2, 2))
        ;

    SET_VAL(UTXH(n), v32, 0, 7, ch);
}

char uart_recv(int n)
{
    while(!GET_BIT(UTRSTAT(n), v32, 0, 0))
        ;

    return GET_BIT(URXH(n), v32, 0, 7);
}
