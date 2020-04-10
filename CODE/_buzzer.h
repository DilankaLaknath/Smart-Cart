DigitalOut buzzer(BUZZER_PIN);

void InitBuzzer() { buzzer = 0; }

void BuzzerBeep(int count, int delayms)
{
    REP(i,0,count)
    {
        buzzer = 1;
        wait_ms(delayms);
        buzzer = 0;
        wait_ms(delayms);
    }
}