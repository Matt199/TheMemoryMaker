#include "Arduino.h"
#include "PenAlphabet.h"
#include "Servo.h"


Pen::Pen(int pin, Servo servo)
{
    _pin = pin;
    _servo = servo;
}

Pen::Pen(){}

void Pen::servoInit(int base)
{
    _servo.attach(_pin);
    _servo.write(base);
    pinMode(10,OUTPUT);
}

void Pen::penDown()
{
            _servo.write(_basePosition);
            delay(_servoDelay);
            digitalWrite(10, HIGH);
            _servo.write(_basePosition + _positionIncrement);
            delay(_servoDelay);
}
void Pen::penUp()
{
            digitalWrite(10, LOW);
            _servo.write(_basePosition + _positionIncrement);
            delay(_servoDelay);
}


void Pen::drawBit()
{
    _servoStep += 20;
    _servo.write(_servoStep);
    delay(_servoDelay);
    
}

void Pen::nextLine()
{
    _servoStep = 0;
    _servo.write(_servoStep);
}
