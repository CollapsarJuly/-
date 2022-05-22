#ifndef adc_h
#define adc_h

#define adc_pin A3

#define High_resistance 14.0
#define low_resistance 10.0

float voltage_calculator();
int read_adc_raw();
void adc_init();

volatile float output_voltage = 0;

#endif