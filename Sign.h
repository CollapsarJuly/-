#ifndef Sign_h
#define Sign_h


#define EvNum 5

static u16 ev_mem[EvNum] = {0};

u8 redEvFlag(u8 n);
void setEvFlag(u8 n, u8 d);
u8 redBIT(u32 m,u8 n);
void setBIT(u32 *m,u8 n,u8 d);



#endif