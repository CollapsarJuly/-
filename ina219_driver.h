#ifndef ina219_driver_h
#define ina219_driver_h

#include <Adafruit_INA219.h>


Adafruit_INA219 ina219;

#define power_supply  12.35


float shuntvoltage = 0;
float current_mA = 0;

static float je = 0;
static float jet = 0;
static float jet_temp1= 0;
static float jet_temp2= 0;

float motor_voltage = 0;

void ina219_calculator();
void ina219_init();
void clear_jet();



#endif