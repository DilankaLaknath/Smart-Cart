#ifndef MICROMOUSE_BUTTON_PANEL_H_
#define MICROMOUSE_BUTTON_PANEL_H_

#ifndef MICROMOUSE_MOCK_RUN_
#include "Arduino.h"
#endif

#ifndef OLED_Dee_Lib_h
#include <OLED_Dee_Lib.h>
#endif

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

    int left_pin_;
    int right_pin_;
    int ok_pin_;

    void Next();
    void Prev();

public:
    ButtonPanel(int left_pin, int right_pin, int ok_pin);

    void Initialize(voidFuncPtr *p_actions, char **titles, int n_actions);
    bool Respond();
    bool Respond(int command);

    int GetCurrentSelectedCommand();

    void TestButtons();
    void Execute();
};

#endif // MICROMOUSE_BUTTON_PANEL_H_