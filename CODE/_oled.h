#ifndef _OLED_H_
#define _OLED_H_

Adafruit_SSD1306_I2c oled(i2cVar, PH_1, 0x78, 64, 128); //ox78

void InitDisplay()
{
    oled.begin(SSD1306_SWITCHCAPVCC);
    oled.setTextWrap(true);
    oled.clearDisplay();
    oled.setTextColor(WHITE);
    oled.setTextCursor(0, 0);
    oled.printf("Circuit Breakers");
    oled.display();
}

void PrintDisplay(char *message)
{
    oled.clearDisplay();
    oled.setTextCursor(0, 0);
    oled.printf(message);
    oled.display();
}

#endif