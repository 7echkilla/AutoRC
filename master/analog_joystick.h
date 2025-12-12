#ifndef ANALOG_JOYSTICK_H
#define ANALOG_JOYSTICK_H

class AnalogJoystick {
    public:
        AnalogJoystick(int x_pin, int y_pin);
        int get_x();
        int get_y();

    private:
        int _x_pin, _y_pin;
};

#endif