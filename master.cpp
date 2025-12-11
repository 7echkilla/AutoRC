// // master

#include <Servo.h>

#define BAUD_RATE 9600
#define X_PIN A0
#define Y_PIN A1
#define SELECT_PIN 2
#define SERVO_PIN 3
#define MOTOR_LF 12
#define MOTOR_LB 13
#define MOTOR_LS 11

int angle;
char direction[12];
Servo steering;

void setup() {
    pinMode(X_PIN, INPUT);
    pinMode(Y_PIN, INPUT);
    pinMode(SELECT_PIN, INPUT);

    steering.attach(SERVO_PIN);

    pinMode(MOTOR_LF, OUTPUT);
    pinMode(MOTOR_LB, OUTPUT);
    pinMode(MOTOR_LS, OUTPUT);

    Serial.begin(BAUD_RATE);
}

void loop() {
    int x_in = analogRead(X_PIN);
    int y_in = analogRead(Y_PIN);
    int brake = digitalRead(SELECT_PIN);

    sprintf(direction, "%d,%d,%d\n", x_in, y_in, brake);
    Serial.print(direction);
    
    int angle = map(x_in, 0, 1023, 0, 180);
    steering.write(angle);

    digitalWrite(MOTOR_LF, HIGH);
    digitalWrite(MOTOR_LB, LOW);
    analogWrite(MOTOR_LS, 10); // 0 -> stop, 255 -> max

    delay(1000);
}