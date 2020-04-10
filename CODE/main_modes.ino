void test_buttons()
{
  button_panel.TestButtons();
}

void get_z_angle()
{
  while (true)
  {
    GetZAngle();
    DisplayTextOLED("Z: " + String(zAngle));
  }
}