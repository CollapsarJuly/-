#include "adc.h"




void adc_init()
{
    pinMode(A3,INPUT);
}


int read_adc_raw()
{
    return analogRead(A3);
}

float voltage_calculator()
{
    output_voltage = (low_resistance + High_resistance) / low_resistance   *  5.0 / 1023.0  * read_adc_raw();
    return output_voltage;
}