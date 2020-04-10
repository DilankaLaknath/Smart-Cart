
#include "__def.h"
#include "__pins.h"
#include "__var.h"

#include "_buzzer.h"
#include "_oled.h"
#include "button_panel_lib/button_panel_lib.h"
#include "_button_panel.h"
#include "_motor_control.h"
// #include "_gyro.h"

#include "_motor_func.h"
#include "_main_modes.h"

int main()
{
    InitRobot();
    BuzzerBeep(1, 50);
    EmitColor(RED_COLOR, 20, false);

    while (buttonPanel.Respond())
    {
    }
    BuzzerBeep(1, 50);

    while (1)
    {
        buttonPanel.Execute();
    }
}

void InitRobot()
{
    InitBuzzer();
    InitSerial();
    InitDisplay();
    InitMotors();
    InitButtons();
    TestI2C();
    InitMPU();
}