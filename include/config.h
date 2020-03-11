#ifndef __CONFIG_H__
#define __CONFIG_H__

typedef unsigned int u32;
typedef volatile u32 v32;

#define SET_BIT(ADDR, TRANS, BIT_S, BIT_E, VAL) 	 								\
		do{																			\
			(*(TRANS *)ADDR) &= (~(((1 << ((BIT_E - BIT_S) + 1)) - 1) << BIT_S));   \
			(*(TRANS *)ADDR) |= (VAL << BIT_S);										\
		}while(0)																		

/*For the register which must be emptied and then to write
 *It must be used at front of "SET_BIT" 
 */
#define SET_VAL(ADDR, TRANS, BIT_S, BIT_E, VAL_OR) 	 								\
		do{																			\
			(*(TRANS *)ADDR) &= (~(((1 << ((BIT_E - BIT_S) + 1)) - 1) << BIT_S));   \
			(*(TRANS *)ADDR) = (VAL_OR << BIT_S);										\
		}while(0)																		

#define GET_BIT(ADDR, TRANS, BIT_S, BIT_E)											\
			((*(TRANS *)ADDR) & (((1 << ((BIT_E - BIT_S) + 1)) - 1) << BIT_S))   	

//Fun led Declare
void led_init(void);
void led_on(int);
void led_off(int);

//Fun UART Declare
void uart_init(int);
void uart_send(int, char);
char uart_recv(int);

//Fun lib Declare
void mdelay(volatile unsigned int);

//Fun Clock Declare 
void system_clock_init(void);
void mputc(char);
void mputs(const char *);
void mprintf(const char *, ...);

//Fun RAM declare
void mem_init(void);

#endif /*__CONFIG_H__*/

