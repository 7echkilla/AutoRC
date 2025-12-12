#include "analog_joystick.h"

#define X_PIN A0
#define Y_PIN A1

#define BAUD_RATE 9600

AnalogJoystick analog_joystick(X_PIN, Y_PIN);

void setup() {
    pinMode(X_PIN, INPUT);
    pinMode(Y_PIN, INPUT);
    
    Serial.begin(BAUD_RATE);
}

void loop() {
    int x_value = analog_joystick.get_x();
    int y_value = analog_joystick.get_y();

    Serial.print("X value: ");
    Serial.print(x_value);
    Serial.print("Y value: ");
    Serial.println(y_value);

    delay(100);
}