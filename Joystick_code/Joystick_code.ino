#include <Joystick.h>

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  5, 1,                  // Button Count, Hat Switch Count
  true, true, false,     // X and Y, but no Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering

int number[9] = {14,5,6,10,15,9,16,7,8}; // post wiring mapping 1

void setup() {
  // Initialize Button and Hat Switch Pins
  for (int i = 0; i < 9; i++)
  {
    pinMode(number[i], INPUT_PULLUP);
  }

  // Initialize Joystick Library
  Joystick.begin();
}

// Last state of the buttons
int lastButtonState[9] = {0,0,0,0,0,0,0,0,0};

// Initialize X Y Axis Pins
int XAxisPin = A0;
int YAxisPin = A1;
// Initial axis value  
int XAxis = 0;
int YAxis = 0;

void loop() {

  // Read pin values
  for (int i = 0; i < 9; i++)
  {
    int currentButtonState = !digitalRead(number[i]);
    if (currentButtonState != lastButtonState[i])
    {
      Joystick.setButton(i, currentButtonState);
      lastButtonState[i] = currentButtonState;

      // Hat Switch
      if (i > 4)
      {
          if ((lastButtonState[5] == 0)
        && (lastButtonState[6] == 0)
        && (lastButtonState[7] == 0)
        && (lastButtonState[8] == 0)) {
          Joystick.setHatSwitch(0, -1);
      }
      if (lastButtonState[5] == 1) {
        Joystick.setHatSwitch(0, 0);
      }
      if (lastButtonState[6] == 1) {
        Joystick.setHatSwitch(0, 90);
      }
      if (lastButtonState[7] == 1) {
        Joystick.setHatSwitch(0, 180);
      }
      if (lastButtonState[8] == 1) {
        Joystick.setHatSwitch(0, 270);
      }
      }
    }
  }

  // Read axis values

  YAxis = analogRead(YAxisPin);
  YAxis = map(YAxis,275,10,0,1023); // Sensor 1 (internal serial number)
  Joystick.setYAxis(YAxis);

  XAxis = analogRead(XAxisPin);
  XAxis = map(XAxis,443,597,0,1023); // Sensor 2 (internal serial number)
  Joystick.setXAxis(XAxis);
  
}