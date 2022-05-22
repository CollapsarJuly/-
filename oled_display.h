#ifndef oled_display_h
#define oled_display_h


#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // 设置OLED宽度
#define SCREEN_HEIGHT 32 // 设置OLED高度
#define OLED_RESET 4 //需要设置，但是不用
#define line 8 //列间隔
#define TextSize 1 //字体大小

extern Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void oled_init();
void print_char_oled(int i,int j,char a[30]);
void print_int_oled(int i,int j,int k);
void print_float_oled(int i,int j,float k);
void oled_display_frame(void p());
void main_interface();
void final_results();
void ina219_display();

float display_voltage = 0.0;


#endif