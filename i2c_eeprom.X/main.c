
// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

#include <xc.h>
#include "I2C_EEPROM.h"
#define _XTAL_FREQ 16000000
 
void main(void) {
 
  I2C_Master_Init(100000);
  unsigned int Address = 0x0023; // Some Random Address
  unsigned char Data = 0x41;     // Some Random Data To Write
 unsigned int Address2 = 0x0028; // Some Random Address
  unsigned char Data2 = 0x42;     // Some Random Data To Write
  unsigned int Address3 = 0x0036; // Some Random Address
  unsigned char Data3 = 0x43;     // Some Random Data To Write
  
  EEPROM_Write(Address, Data); // Write 0x04 @ 0x0020
    __delay_ms(10); // Wait tWR=10ms For Write To Complete
  EEPROM_Write(Address2, Data2); // Write 0x05 @ 0x0021
    __delay_ms(10); // Wait tWR=10ms For Write To Complete
  EEPROM_Write(Address3, Data3);     // Write 0x06 @ 0x0022
  __delay_ms(10); // Wait tWR=10ms For Write To Complete
 
  TRISD = 0x00;
  PORTD = EEPROM_Read(Address); // Should Read 0x04
  __delay_ms(2000);
  PORTD = EEPROM_Read(Address2); // Should Read 0x05
  __delay_ms(2000);
  PORTD = EEPROM_Read(Address3);   // Should Read 0x06
  __delay_ms(2000);
 
  while(1)
  {
     // Stay IDLE .. DO Nothing!
  }
  return;
}