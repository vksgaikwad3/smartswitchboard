#ifndef  QTouch_h
#define  QTouch_h

#include <Arduino.h>
#include <HBT.h>
#include "BLE.h"
#include <avr/io.h>


//#define Lamp1_Dir_Input   (DDRD &= 0b0000000)       //PD5 SW1 

//#define SW1   (PIND & 0b00100000)    //PD5
// Capsence Input Pins

#define Lamp1     13  //  ((PINC & 0x80)==0x80)    // PC7   //7    // (PIND & 0b00100000)    //PD5 Input pin             
#define Lamp2     18  // ((PINF & 0x80)==0x80)    //PF7       //4    
#define Lamp3     19  // ((PINF & 0x40)==0x40)    // PF6       //12     //A6 
#define Socket    20  // ((PINF & 0x20)==0x20)    // PF5       //6  
#define Fan_Control 23  //((PINF & 0x01)==0x01)    //PF0        //10     
#define Up          21  //((PINF & 0x10)==0x10)    //PF4        //8
#define Down        22  //((PINF & 0x02)==0x02)     //PF1          //9

// RF Inputs
/// RF Modules Output pins as Input to MCU PB0 - PB3

#define RFD0  14    //D14
#define RFD1  16    //D16(RFD2)
#define RFD2  17    //D17(RFD3)
#define RFD3  15    //D15(RFD1)

//Output Pins to control Triac Switching

#define Load1   5      //5  //  14   //Relay 1 
#define Load2   10      //PB6    //15    //Relay 2
#define Load3   9      //PB5    //16   //Relay 3
#define Load4   8      //PB4      //17   //D17 Relay 4 - Socket pin
#define Level1  11      //5      //D5
#define Level2  4        //13   //D13
#define Level3  12      //18    //D18
#define Level4  6        //19   //D19



class QTouch
{
  
  public:
  
  uint8_t i;
  QTouch();        //Constructor
  void gpioInit(void);
  byte readCapsense(void);
  byte readLoadstatus(void);
  byte readRF(void);
  void cap_setLoad(byte loadValue);
  void L1_ON(void);
  void L2_ON(void);
  void L3_ON(void);
  void Socket_ON(void);
  void FAN_ON(void);             
  void Level2_ON(void);
  void Level3_ON(void);
  void Level4_ON(void);
  void Master_ON(void);
  
  void L1_OFF(void);
  void L2_OFF(void);
  void L3_OFF(void);
  void Socket_OFF(void);
  void FAN_OFF(void);
  void Level2_OFF(void);
  void Level3_OFF(void);
  void Level4_OFF(void);
  void Master_OFF(void);

  void LightControl(uint8_t pinNo , uint8_t pinValue);
  
  
  private:
  
  byte curr_status, prev_status;
  
  uint8_t m_loadValue, pin_num,pin_Value;
  uint8_t prev_loadValue;
  
  
};

#endif


