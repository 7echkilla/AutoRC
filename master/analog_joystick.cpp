#include "analog_joystick.h"
#include <Arduino.h>

AnalogJoystick::AnalogJoystick(int x_pin, int y_pin) {
    _x_pin = x_pin;
    _y_pin = y_pin;
}

int AnalogJoystick::get_x() {
    return analogRead(_x_pin);
}

int AnalogJoystick::get_y() {
    return analogRead(_y_pin);
}