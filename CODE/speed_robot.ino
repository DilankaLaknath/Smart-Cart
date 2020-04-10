#include "_def.h"
#include "_pins.h"
#include "_var.h"

void setup()
{
  
  // InitLEDBlink();
  InitOLED();
  // InitMPU();
  // InitMotors();
  Serial.begin(9600);
  InitTof();
  // button_panel.Initialize(actions, titles, 3);
  // while (button_panel.Respond())
  // {
  //   LEDBlink();
  // }
  pinMode(BTN_LEFT, INPUT);
  pinMode(BTN_OK, INPUT);
  pinMode(BTN_RIGHT, INPUT);
}

void loop()
{
  GetDistance();
  button_panel.Execute();
  DisplayTextOLED(String(digitalRead(BTN_LEFT)) + String(digitalRead(BTN_OK)) + String(digitalRead(BTN_RIGHT)));
  DisplayTextOLED(String(digitalRead(BTN_RIGHT)));
}
