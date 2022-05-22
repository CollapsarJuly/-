#include <Wire.h>
#include <avr/wdt.h>
#include "oled_display.h"
#include "ina219_driver.h"
#include "speed.h"
#include "time_unit.h"
#include "key.h"
#include "relay.h"
#include "adc.h"


eeprom.read()

void setup()
{

    oled_init();
    ina219_init();
    encoder_init();
    key_init();
    relay_init();
    process_init();
    adc_init();
    wdt_enable(WDTO_120MS);

    Serial.begin(115200);

    
}

void loop()
{
    time_calculator();
    ina219_calculator();
    speed_calculate();
    key_handle();
    voltage_calculator();
        
    if(set_state == 0 && final_state == 0)
        oled_display_frame(ina219_display);

    
    if(set_state == 1 && final_state == 0)
        oled_display_frame(main_interface);

    if(final_state == 1)
        oled_display_frame(final_results);
    



    Serial.print(jet);
    Serial.print(",");
    Serial.print(get_speed());
    Serial.print(",");
    Serial.println(display_voltage);

    wdt_reset();
}





