#include "key.h"



void key_init()
{
    rst_button.reset();
    rst_button.attachClick(rst_click);

    mid_button.reset();
    mid_button.attachClick(mid_click);


    up_button.reset();
    up_button.attachDuringLongPress(up_LongPress);
    up_button.attachClick(up_click);

    dwn_button.reset();
    dwn_button.attachDuringLongPress(dwn_LongPress);
    dwn_button.attachClick(dwn_click);

    
    
}

void key_handle()
{
    rst_button.tick();

    mid_button.tick();

    up_button.tick();

    dwn_button.tick();

    
}


