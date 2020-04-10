
void test_buttons()
{
    oled.clearDisplay();
    oled.setTextCursor(0, 0);
    oled.printf("l: %d ok: %d r: %d\n", btnLeft.read(), !btnOk.read(), !btnRight.read());
    oled.display();
}

void test_right_90()
{
    EncoderTurnRight90(ENCODER_TURN_RIGHT_90_TICKS, 500);
    Hold();
}

void test_left_90()
{
    TurnLeft90();
    Hold();
}

void test_motors()
{
    UptoFinishSwordPickupFirstRound();
    BuzzerBeep(10, 200);
    LineFollowTilCont(400);
    SwordDropTask();

    // BreakAndTurnLeft();
    // BreakMotors();
    Hold();
}
