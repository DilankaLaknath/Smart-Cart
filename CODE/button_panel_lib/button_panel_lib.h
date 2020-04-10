#define BUTTON_PANEL_EXECUTE_C_ 0
#define BUTTON_PANEL_NEXT_C_ 1
#define BUTTON_PANEL_PREV_C_ 2

#include <string>
using namespace std;

#include "button_panel_def.h"
#include "../_oled.h"

void ButtonPanel::Next()
{
    this->current_selected_ = (this->current_selected_ + 1) % this->n_actions_;
}

void ButtonPanel::Prev()
{
    if (this->current_selected_ == 0)
    {
        this->current_selected_ = this->n_actions_ - 1;
    }
    else
    {
        this->current_selected_ -= 1;
    }
}

void ButtonPanel::Execute()
{
    voidFuncPtr executed_function = this->p_actions_[this->current_selected_];
    executed_function();
}

bool ButtonPanel::Respond()
{
    if (this->actions_assigned_)
    {
        if (!this->okButton.read())
        {
            return ButtonPanel::Respond(BUTTON_PANEL_EXECUTE_C_);
        }
        else if (this->leftButton.read())
        {
            BuzzerBeep(1, 50);
            return ButtonPanel::Respond(BUTTON_PANEL_PREV_C_);
        }
        else if (!this->rightButton.read())
        {
            BuzzerBeep(1, 50);
            return ButtonPanel::Respond(BUTTON_PANEL_NEXT_C_);
        }
    }
    return true;
}

bool ButtonPanel::Respond(int command)
{
    if (command == BUTTON_PANEL_EXECUTE_C_)
    {
        return false;
    }
    else if (command == BUTTON_PANEL_NEXT_C_)
    {
        ButtonPanel::Next();
        PrintDisplay(this->titles[this->current_selected_]);
    }
    else if (command == BUTTON_PANEL_PREV_C_)
    {
        ButtonPanel::Prev();
        PrintDisplay(this->titles[this->current_selected_]);
    }
    wait_ms(200);
    return true;
}

int ButtonPanel::GetCurrentSelectedCommand()
{
    return this->current_selected_;
}

string ButtonPanel::TestButtons()
{
    return (to_string(this->leftButton.read()) + " " +
            to_string(this->okButton.read()) + " " +
            to_string(this->rightButton.read()));
}