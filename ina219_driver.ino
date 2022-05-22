#include "ina219_driver.h"
#include "oled_display.h"
#include "time_unit.h"
#include "speed.h"
#include "kalman.h"
#include "adc.h"
#include "process.h"



void ina219_calculator()  //1.6
{
    float current_plus = 0;
    
    shuntvoltage = ina219.getShuntVoltage_mV();
        
    motor_voltage = power_supply - shuntvoltage/1000.0;
    
    current_mA = ina219.getCurrent_mA();

    current_plus = abs(current_mA);

    // if(abs(current_mA) <= 0.5)
    //     current_mA=0;
    

    if(speed_appropriate())
    {
        if(flag == 0)
        {
            je = current_plus /1000.0 * motor_voltage  * T2/1000.0 ;
            je -= (current_plus/1000.0) * (current_plus/1000.0) * 3.4 * T2/1000.0;
        }
        else
            je=current_plus* (voltage_calculator()) * T2/1000.0/1000.0 ;
            
    }
    else
        je=0;



    jet+=je;
}

void ina219_init()
{
    ina219.begin();
}

void clear_jet()
{
    jet=0;
}