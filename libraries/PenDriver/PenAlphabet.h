

#ifndef PenAlphabet_h
#define PenAlphabet_h

#include "Arduino.h"
#include "Servo.h"

class Pen
{
    public:
        Pen(int pin, Servo servo);
        Pen();
    void servoInit(int base);
        void penDown();
        void penUp();
        void drawBit();
        void nextLine();
    private: 
         int _pin;
         int _servoStep = 0;
         int _basePosition = 0;
         int _servoDelay = 200;
        int _positionIncrement = 60;
         Servo _servo;
    
};

#endif
