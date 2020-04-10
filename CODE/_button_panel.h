DigitalIn btnLeft(BTN_LEFT);
DigitalIn btnOk(BTN_OK);
DigitalIn btnRight(BTN_RIGHT);

void InitButtons()
{
    btnRight.mode(PullUp);
}

// Button Panel Function Defs

void test_right_90();
void test_left_90();
void print_tof_distance();
void test_motors();

// Button Panel Var
typedef void (*voidFuncPtr)(void);

voidFuncPtr actions[] = {

    test_right_90,
    test_left_90,
    print_tof_distance,

};

char *titles[] = {

    (char *)"test right 90",
    (char *)"test left 90",
    (char *)"test motors",
    (char *)"test tof distance",
};

ButtonPanel buttonPanel(BTN_LEFT, BTN_RIGHT, BTN_OK, actions, titles, 12);