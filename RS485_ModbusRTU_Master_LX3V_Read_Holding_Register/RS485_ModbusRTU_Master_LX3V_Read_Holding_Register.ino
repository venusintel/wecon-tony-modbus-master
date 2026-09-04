#include "TonyS_X1.h"
#include "TonyS_X1_ExternalModule.h"

#define SLAVE_ID 0x01      //LX3V D8121 = K1
#define ADDRESS  8013      //LX3V D8013 = 8013

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
  int s = modbus.readSingleHoldingRegister(SLAVE_ID, ADDRESS);
  int m = modbus.readSingleHoldingRegister(SLAVE_ID, ADDRESS + 1);
  int h = modbus.readSingleHoldingRegister(SLAVE_ID, ADDRESS + 2);
  int d = modbus.readSingleHoldingRegister(SLAVE_ID, ADDRESS + 3);
  int mth = modbus.readSingleHoldingRegister(SLAVE_ID, ADDRESS + 4);
  int y = modbus.readSingleHoldingRegister(SLAVE_ID, ADDRESS + 5);
  
  Serial.println(String(d) + "/" + String(mth) + "/" + String(y) + " " + String(h) + ":" + String(m) + ":" + String(s));
  delay(1000);
}
