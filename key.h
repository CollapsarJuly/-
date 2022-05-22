#ifndef key_h
#define key_h


#include <OneButton.h>
#include "ina219_driver.h"
#include "speed.h"
#include "relay.h"
#include "oled_display.h"
#include "process.h"

#define UP_pin 8
#define DWN_pin 9
#define MID_pin 10
#define SET_pin 11
#define RST_pin 12


OneButton rst_button(RST_pin,true);
OneButton up_button(UP_pin,true);
OneButton dwn_button(DWN_pin,true);

OneButton mid_button(MID_pin,true);

void key_handle();
void key_init();

bool set_state = 0;
bool mid_state = 0;




#endif