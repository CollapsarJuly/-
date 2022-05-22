#include "speed.h"
#include "time_unit.h"
#include "kalman.h"


float speed_calculate() //  r/s
{
    speed_r = 125.0 * (float)pulse / (4.0 * (float)T2);
    
    speed_r = kalman_filter_speed(speed_r);

    if(speed_r <= 0.3 )
        speed_r = 0;
    pulse = 0;
    wdt_reset();

}

float get_speed()
{
    return speed_r;
}

void pulse_count()
{
    pulse++;
}

void encoder_init()
{
    pinMode(encoder_pin,INPUT);
    attachInterrupt(0,pulse_count,HIGH);
    interrupts();
}




bool speed_appropriate()
{
    if(LowSpeed >= HighSpeed )
        LowSpeed = HighSpeed  - 1;
    if(get_speed() >= LowSpeed && get_speed() <= HighSpeed)
        return 1;
    else
        return 0;
}
