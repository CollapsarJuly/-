#include "Sign.h"



u8 redEvFlag(u8 n)
{
    u8 temp,i;
    i = (n>>4);
    n &= 0xf;
    temp = ((ev_mem[i] & (1<<n)) == (1<<n));
    return temp;
}

void setEvFlag(u8 n, u8 d)
{
    u8 i;
    i = (n>>4);
    n &= 0xf;
    ev_mem[i] = ev_mem[i] & (~(1<<n));
    ev_mem[i] = ev_mem[i] | (d<<n);

}

u8 redBIT(u32 m,u8 n)
{
    return ((m&(1<<n)) == (1<<n));
}

void setBIT(u32 *m,u8 n,u8 d)//m变量，n第几位，d设置为0或者1
{
    *m = (*m) & (~(1<<n));
    *m = (*m) | (d<<n);
}