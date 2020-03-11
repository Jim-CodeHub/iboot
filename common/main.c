#include <config.h>

int main(void)
{
    system_clock_init();
    led_init();
    uart_init(0);

    //------------
    led_off(10);
    mdelay(1000000);
    led_on(10);
    mdelay(1000000);

    led_off(1);
    led_off(4);

    mprintf("UART0 Init OK!\n");

#if 1
    mem_init_r2(); //只有单独使用此函数时可以正常打印，除了7FFFFFFF地址的验证,
                    //且无论如何操作都无法读取这个地址，还会导致前面的uart代码失效
                    //估计可能时钟错乱，或者时钟没有初始化错误，内存也没有驯服，暂停中
    //mem_init_r0();
    //mem_init_r1();

    u32 a, b, c, d, e;
    asm __volatile__(
            
            "ldr r0, =0x1111\n"
            "ldr r1, =0x40000000\n"
            "str r0, [r1]\n"
            "ldr %[x], [r1]\n"
            "ldr r0, =0x2222\n"
            "ldr r1, =0x50000000\n"
            "str r0, [r1]\n"
            "ldr %[y], [r1]\n"
            "ldr r0, =0x3333\n"
            "ldr r1, =0x60000000\n"
            "str r0, [r1]\n"
            "ldr %[z], [r1]\n"
            "ldr r0, =0x4444\n"
            "ldr r1, =0x70000000\n"
            "str r0, [r1]\n"
            "ldr %[p], [r1]\n"
            "ldr r0, =0x5555\n"
            "ldr r1, =0x7FFFFFFE\n" /*存储2个字节数据，需预留空间，故不能直接测试0x80000000*/
            "str r0, [r1]\n"
            "ldr %[q], [r1]\n"
            :[x] "=r" (a), [y] "=r" (b), [z] "=r" (c), [p] "=r" (d), [q] "=r" (e)
            :
            :"r0", "r1", "memory"

            );

    mprintf("addr = %x, data = %x\n", &a, a);
    mprintf("addr = %x, data = %x\n", &b, b);
    mprintf("addr = %x, data = %x\n", &c, c);
    mprintf("addr = %x, data = %x\n", &d, d);
    mprintf("addr = %x, data = %x\n", &e, e);

#endif

    return 0;
}
