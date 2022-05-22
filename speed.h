#ifndef speed_h
#define speed_h
#include <avr/wdt.h>
#define encoder_pin 2

static unsigned int LowSpeed = 2;
static unsigned int HighSpeed = 7;

volatile long long int pulse = 0;
volatile float speed_r = 0;
float speed_calculate();
void pulse_count();
void encoder_init();
float get_speed();
bool speed_appropriate();

#endif