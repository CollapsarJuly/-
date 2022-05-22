#ifndef process_h
#define process_h


#include "key.h"
#include "ina219_driver.h"
#include "relay.h"
#include "speed.h"


#define set_state_Ev 1


void rst_click();
void mid_click();
void up_LongPress();
void up_click();
void dwn_LongPress();
void dwn_click();
void process_init();
bool flag = 0;
bool final_state= 0;


#endif