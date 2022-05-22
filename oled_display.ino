
#include "oled_display.h"
#include "ina219_driver.h"
#include "speed.h"
#include "key.h"
#include "adc.h"


void oled_init()
{
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    // 清除屏幕
    display.clearDisplay();
    // 设置字体颜色,白色可见
    display.setTextColor(WHITE);
    //设置字体大小
    display.setTextSize(TextSize);
    //设置光标位置
    display.setCursor(0, 0);
}

void print_char_oled(int i,int j,char a[30])
{
    display.setCursor(i, j);
    display.print(a);
}

void print_int_oled(int i,int j,int k)
{
    display.setCursor(i, j);
    display.print(k);
}

void print_float_oled(int i,int j,float k)
{
    display.setCursor(i, j);
    display.print(k);
}

void oled_display_frame(void p())
{
    display.clearDisplay();
    p();
    display.display();
}

void main_interface()
{
    print_char_oled(0,line-2," Low_Speed:");
    print_int_oled(70,line-2,LowSpeed);
    print_char_oled(90,line-2,"r/s");

    print_char_oled(0,line*2+3,"High_Speed:");
    print_int_oled(70,line*2+3,HighSpeed);
    print_char_oled(90,line*2+3,"r/s");

    if(mid_state == 0)
        print_char_oled(110,line-2,"<-");
    else
        print_char_oled(110,line*2+3,"<-");


}


void final_results()
{
    print_char_oled(10,line-6," Input:");
    print_float_oled(55,line-6,jet_temp1);
    print_char_oled(110,line-6,"J");

    print_char_oled(10,line*2-1,"Output:");
    print_float_oled(55,line*2-1,jet_temp2);
    print_char_oled(110,line*2-1,"J");

    version_display("V4.0.518");
}


void ina219_display()
{
    
    if(flag == 0)
        display_voltage = motor_voltage;
    else
        display_voltage = output_voltage;


    print_char_oled(0,0,"Voltage:");
    print_float_oled(50,0,display_voltage);
    print_char_oled(105,0,"V");

    print_char_oled(0,line,"Current:");
    print_float_oled(50,line,current_mA);
    print_char_oled(105,line,"mA");


    print_char_oled(0,line*2,"Speed:");
    print_float_oled(50,line*2,get_speed());
    print_char_oled(105,line*2,"r/s");

    print_char_oled(0,3*line,"Energy:");
    
    print_float_oled(50,3*line,jet);

    print_char_oled(105,3*line,"J");

}

void version_display(char *p)
{
    print_char_oled(80,25,p);
}