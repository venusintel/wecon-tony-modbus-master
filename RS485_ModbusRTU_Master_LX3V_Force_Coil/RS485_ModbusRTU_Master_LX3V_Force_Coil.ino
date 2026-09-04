#include "TonyS_X1.h"
#include "TonyS_X1_ExternalModule.h"

#define SLAVE_ID 0x01      //LX3V D8121 = K1
#define ADDRESS  0         //LX3V M0 = 0

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
  if (Serial.available()) {
    
    char incomingByte = Serial.read();
    
    Serial.print("I received: ");
    Serial.println(incomingByte);
    if(incomingByte == '1'){
      modbus.forceSingleCoil(SLAVE_ID, ADDRESS, HIGH);
    }
    else if(incomingByte == '0'){
      modbus.forceSingleCoil(SLAVE_ID, ADDRESS, LOW);
    }
    else{
    }
  }
}
