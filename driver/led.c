#include <led.h>
#include <config.h>

void led_init(void)
{
    SET_BIT(GPM4CON, v32, 0, 15, 0);
    SET_BIT(GPM4CON, v32, 0, 15, 0x1111);
}

void led_on(int n)
{
    switch(n)
    {
        case 1: 
            SET_BIT(GPM4DAT, v32, 0, 0, 0);
            break;
        case 2:
            SET_BIT(GPM4DAT, v32, 1, 1, 0);
            break;
        case 3:
            SET_BIT(GPM4DAT, v32, 2, 2, 0);
            break;
        case 4:
            SET_BIT(GPM4DAT, v32, 3, 3, 0);
            break;
        default:
            SET_BIT(GPM4DAT, v32, 0, 3, 0);
    }
}

void led_off(int n)
{
    switch(n)
    {
        case 1: 
            SET_BIT(GPM4DAT, v32, 0, 0, 1);
            break;
        case 2:
            SET_BIT(GPM4DAT, v32, 1, 1, 1);
            break;
        case 3:
            SET_BIT(GPM4DAT, v32, 2, 2, 1);
            break;
        case 4:
            SET_BIT(GPM4DAT, v32, 3, 3, 1);
            break;
        default:
            SET_BIT(GPM4DAT, v32, 0, 3, 0xf);
    }
}
