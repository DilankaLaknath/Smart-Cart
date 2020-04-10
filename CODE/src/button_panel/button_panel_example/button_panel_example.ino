#include <button_panel.h>
#include <OLED_Dee_Lib.h>

void function_1();
void function_2();

#define BTN_LEFT PB9  //PB11
#define BTN_OK PA15   //PB10
#define BTN_RIGHT PB8 //PB1

ButtonPanel button_panel(BTN_LEFT, BTN_RIGHT, BTN_OK);
voidFuncPtr actions[] = {function_1, function_2};
char *titles[] = {
    (char *)"function 1",
    (char *)"function 2"};

void setup()
{
    InitOLED("Hello!");
    button_panel.Initialize(actions, titles, 2);
    while (button_panel.Respond())
    {
    }
}

void loop()
{
    button_panel.Execute();
}

void function_1()
{
    DisplayTextOLED("func 1 run");
}

void function_2()
{
    DisplayTextOLED("func 2 run");
}