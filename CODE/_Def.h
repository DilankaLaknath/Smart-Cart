#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"
#include "src/button_panel/button_panel.h"

void test_buttons();
void get_z_angle();

void Hold()
{
  while (true)
  {
  }
}

bool blink_state = false;

void InitLEDBlink()
{
  pinMode(13, OUTPUT);
}

void LEDBlink()
{
  // blink_state = (digitalRead(13)) ? true : false;
  digitalWrite(13, !digitalRead(13));
  delay(500);
}