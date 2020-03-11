#include <stdarg.h>

void mdelay(volatile unsigned int i)
{
    while(--i)
        ;
}

void mputc(char ch)
{
    if(ch == '\n')
        uart_send(0, '\r');
    uart_send(0, ch);
}

void mputs(const char *p)
{
    while(*p)
    {
        mputc(*p++); 
    }
    mputc('\n');
}

void conversion(int num, int dec)
{
    if(num == 0)
        return; 

    conversion(num/dec, dec);
    uart_send(0, "0123456789ABCDEF"[num%dec]);
}

int mprintf(const char *format, ...)
{
    va_list ap;

    int n;
    char c;
    char *s;

    va_start(ap, format);

    while(*format)
    {
        if(*format == '%') 
        {
            format++; 
            switch(*format)
            {
                case 'd': 
                    n = va_arg(ap, int);
                    conversion(n, 10);
                    break;
                case 'p':
                case 'x':
                    n = va_arg(ap, int);
                    mputc('0');
                    mputc('x');
                    conversion(n, 16);
                    break;
                case 'o':
                    n = va_arg(ap, int);
                    conversion(n, 8);
                    break;
                case 'c':
                    c = (char)va_arg(ap, int); 
                    mputc(c);
                    break;
                case 's':
                    s = va_arg(ap, char *);
                    mputs(s);
                    break;
            }
        }
        else
        {
            mputc(*format); 
        }

        *format++;
    }

    va_end(ap);
}
