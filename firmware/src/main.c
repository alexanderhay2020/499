// PIC32 control of pneumatic actuator

#include<xc.h>                      // processor SFR definitions
#include<sys/attribs.h>             // __ISR macro
#include<string.h>
#include<stdio.h>

#include "init.h"
#include "adc.h"
#include "i2c.h"
#include "ssd1306.h"
#include "font.h"

void wait(float time){
    
}

void draw_box(){
    
    int i = 0;
    char indicator_msg[10];
    
    // left horizontal lines
    for(i=15;i<49;i++){
        ssd1306_drawPixel(i,21,1);
        ssd1306_drawPixel(i,31,1);
    }
    // left vertical lines
    for(i=21;i<31;i++){
        ssd1306_drawPixel(15,i,1);
        ssd1306_drawPixel(48,i,1);
    }

    // right horizontal lines
    for(i=79;i<114;i++){
        ssd1306_drawPixel(i,21,1);
        ssd1306_drawPixel(i,31,1);
    }

    // right vertical lines
    for(i=22;i<31;i++){
        ssd1306_drawPixel(79,i,1);
        ssd1306_drawPixel(113,i,1);
    }

    sprintf(indicator_msg, "RIGHT");
    drawString(82,23,indicator_msg);

    sprintf(indicator_msg, "LEFT");
    drawString(20,23,indicator_msg);
}

int main() {

    init_pic();
//    init_i2c();
    ssd1306_setup();
//    ssd1306_clear();
//    init_ADC(14);
    
    TRISAbits.TRISA4 = 0;           // sets A4 as output
    TRISBbits.TRISB4 = 0;           // sets B4 as output
//    TRISBbits.TRISB5 = 1;           // sets B5 as input
    
    LATAbits.LATA4 = 0;             // sets A4 to low
    LATBbits.LATB4 = 1;             // sets B4 to high
    
    char indicator_msg[10];
    char pressure_msg[20];

    while (1) {
        // use _CP0_SET_COUNT(0) and _CP0_GET_COUNT() to test the PIC timing
        // remember the core timer runs at half the sysclk

        _CP0_SET_COUNT(0);
//        int i = 0;
        
        ssd1306_clear();
        ssd1306_drawPixel(0,0,LATAbits.LATA4); // flashes single LED on screen
        
        if (LATAbits.LATA4 == 0){
            sprintf(indicator_msg, "v");
            drawString(29,14,indicator_msg);  
        }
        else {
            sprintf(indicator_msg, "v");
            drawString(93,14,indicator_msg);
        }
        LATAbits.LATA4 = !LATAbits.LATA4;
        LATBbits.LATB4 = !LATBbits.LATB4;
        while(_CP0_GET_COUNT() < 24000000/2){}

        draw_box();

        int val = read_adc(14);
        sprintf(pressure_msg, "PSI VOLTAGE: %d", val);
        drawString(0,0,pressure_msg); 
        ssd1306_update();
    }
}