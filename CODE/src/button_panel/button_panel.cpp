#define BUTTON_PANEL_EXECUTE_C_ 0
#define BUTTON_PANEL_NEXT_C_ 1
#define BUTTON_PANEL_PREV_C_ 2

#include "button_panel.h"

ButtonPanel::ButtonPanel(int left_pin, int right_pin, int ok_pin)
{
    this->left_pin_ = left_pin;
    this->right_pin_ = right_pin;
    this->ok_pin_ = ok_pin;
}

void ButtonPanel::Initialize(voidFuncPtr *p_actions, char **titles, int n_actions)
{
    pinMode(this->left_pin_, INPUT);
    pinMode(this->right_pin_, INPUT);
    pinMode(this->ok_pin_, INPUT);

    this->p_actions_ = p_actions;
    this->n_actions_ = n_actions;
    this->actions_assigned_ = true;
    this->titles = titles;
}

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
        this->current_selected_--;
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
        if (digitalRead(this->ok_pin_))
        {
            return ButtonPanel::Respond(BUTTON_PANEL_EXECUTE_C_);
        }
        else if (digitalRead(this->left_pin_))
        {
            return ButtonPanel::Respond(BUTTON_PANEL_NEXT_C_);
        }
        else if (digitalRead(this->right_pin_))
        {
            return ButtonPanel::Respond(BUTTON_PANEL_PREV_C_);
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
        ButtonPanel::Prev();
        DisplayTextOLED(String(this->titles[this->current_selected_]));
    }
    else if (command == BUTTON_PANEL_PREV_C_)
    {
        ButtonPanel::Next();
        DisplayTextOLED(String(this->titles[this->current_selected_]));
    }
    delay(200);
    return true;
}

int ButtonPanel::GetCurrentSelectedCommand()
{
    return this->current_selected_;
}

void ButtonPanel::TestButtons()
{
    DisplayTextOLED(String(digitalRead(this->left_pin_)) + " " +
                    String(digitalRead(this->right_pin_)) + " " +
                    String(digitalRead(this->ok_pin_)));
}