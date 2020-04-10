#ifndef _BUTTON_PANEL_H_
#define _BUTTON_PANEL_H_
#include "mbed.h"

typedef void (*voidFuncPtr)(void);
// Usage:
//
// [Global]
// ButtonPanel button_panel(2, 3, 4);
//
// [Setup]
// voidFuncPtr actions[] = {
//     test_all,
//     encoder_test,
//     gyro_test,
//     sharp_ir_test,
//     motor_control_test};
// char *titles[] = {
//     (char *)"Test All",
//     (char *)"Encoder Test",
//     (char *)"Gyro Test",
//     (char *)"Sharp IR Test",
//     (char *)"Motor Control Test"};
// button_panel.Initialize(actions, titles, 5);
// while(button_panel.Respond()){ }
//
// [Loop]
// button_panel.Execute();
class ButtonPanel
{
private:
    voidFuncPtr *p_actions_;        // Pointer of the pointer of the first element of the array
    char **titles;                  // Pointer of pointer of first character in char arrays
    int n_actions_;                 // Number of pointers (size of array)
    int current_selected_ = 0;      // Current selected option
    bool actions_assigned_ = false; // Whether actions array was assigned

    DigitalIn leftButton;
    DigitalIn okButton;
    DigitalIn rightButton;

    void Next();
    void Prev();

public:
    ButtonPanel(PinName left_pin, PinName right_pin, PinName ok_pin, voidFuncPtr *p_actions, char **titles, int n_actions) : leftButton(left_pin), rightButton(right_pin), okButton(ok_pin)
    {
        this->p_actions_ = p_actions;
        this->n_actions_ = n_actions;
        this->actions_assigned_ = true;
        this->titles = titles;
    }

    bool Respond();
    bool Respond(int command);

    int GetCurrentSelectedCommand();

    string TestButtons();
    void Execute();
};

#endif // MICROMOUSE_BUTTON_PANEL_H_