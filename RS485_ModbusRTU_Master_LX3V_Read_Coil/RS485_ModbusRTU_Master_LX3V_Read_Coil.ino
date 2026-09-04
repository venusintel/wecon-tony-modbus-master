#include "TonyS_X1.h"
#include "TonyS_X1_ExternalModule.h"

#define SLAVE_ID 0x01       //LX3V D8121 = K1
#define ADDRESS  64512      //LX3V Y0 ~ Y5 = 64512 ~ 64517, X0 ~ X7 = 63488 ~ 64595

Tony_Modbus_Master modbus;

void setup() 
{
  Serial.begin(115200);
  Serial.println("TonyS_X1 Example");
  Tony.begin();
  modbus.setSlot(SLOT4);
  modbus.begin(9600);
}

void loop() 
{
  if(modbus.readSingleCoilStatus(SLAVE_ID, ADDRESS)){
    Serial.println("Y0 = ON");
  }
  else{
    Serial.println("Y0 = OFF");
  }
  delay(500);
}
