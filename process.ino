#include "process.h"
#include "Sign.h"
void rst_click()
{
    if(final_state == 1)
        final_state = 0;
    else
    {
        set_state = 1 - set_state;
        clear_jet();
    }
}

void mid_click()
{
    if(set_state == 0)
    {
        if(flag == 0 && final_state == 0)
        {
            jet_temp1 = jet;
            clear_jet();
            relay_on();
            flag = 1;
        }
        else
        {
            jet_temp2 = jet;
            clear_jet();
            relay_off();
            final_state = 1;
            flag = 0;
        }
        
    }
    else
    {
        mid_state = 1 - mid_state;
        relay_off();
    }
        
}

void up_LongPress()
{
    if (up_button.isLongPressed() && set_state == 1)
    {
        for(int i=0;i<200;i++);
        if(mid_state == 0)
            LowSpeed++;
        else
            HighSpeed++;
    }
}
void up_click()
{
    if(mid_state == 0 && set_state == 1)
        LowSpeed++;
    else
        HighSpeed++;
}


void dwn_LongPress()
{
    if (dwn_button.isLongPressed() && set_state == 1)
    {
        for(int i=0;i<200;i++);
        if(mid_state == 0)
            LowSpeed--;
        else
            HighSpeed--;
    }
}
void dwn_click()
{
    if(mid_state == 0 && set_state == 1)
        LowSpeed--;
    else
        HighSpeed--;
}


void process_init()
{
    set_state = 0;
    mid_state = 0;
    flag = 0;
    final_state= 0;
}