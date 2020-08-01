#include<xc.h>                      // processor SFR definitions
#include<sys/attribs.h>             // __ISR macro

#include "adc.h"

//void init_ADC(int pin) {
//    // UI exercise in setting analog pins
//    
//    int pin_count = 0;
//    
//    switch (pin_count){
//        case 0: {
//            AD1CHSbits.CH0SA0 = pin;
//            pin_count++;
//        }
//        case 1: {
//            AD1CHSbits.CH0SA1 = pin;
//            pin_count++;
//        }
//        case 2: {
//            AD1CHSbits.CH0SA2 = pin;
//            pin_count++;
//        }
//        case 3: {
//            AD1CHSbits.CH0SA3 = pin;
//            pin_count++;
//        }
//    }
////  AD1PCFGbits.PCFG0 = 0;                 // AN0 is an adc pin
////  AD1CHSbits.CH0SA0 = pin;
////  AD1CHSbits.
////  AD1CON3bits.ADCS = 2;                   // ADC clock period is Tad = m2*(ADCS+1)*Tpb = 2*3*12.5ns = 75ns
////  AD1CON1bits.ADON = 1;
//    
//}


unsigned int adc_sample_convert(int pin) { // sample & convert the value on the given

  unsigned int elapsed_time = 0;
  unsigned int finish_time = 0;
  AD1CHSbits.CH0SB = pin;                // connect chosen pin to MUXA for sampling
  AD1CON1bits.SAMP = 1;                  // start sampling
  elapsed_time = _CP0_GET_COUNT();
  finish_time = elapsed_time + 10;
  while (_CP0_GET_COUNT() < finish_time) {
    ;                                   // sample for more than 250 ns
  }
  AD1CON1bits.SAMP = 0;                 // stop sampling and start converting
  while (!AD1CON1bits.DONE) {
    ;                                   // wait for the conversion process to finish
  }
  return ADC1BUF0;                      // read the buffer with the result
}


unsigned int read_adc(int pin) {
  int i = 0;
  int sum = 0;
  while (i<=10) {
    sum += adc_sample_convert(pin);
    i++;
  }
  return (sum/10);
}