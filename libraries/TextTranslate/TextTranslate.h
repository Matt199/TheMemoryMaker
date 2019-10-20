#include "Arduino.h"
#include <PenAlphabet.h>
#include <Servo.h>
#include <Engine.h>

#ifndef TextTranslate_h
#define TextTranslate_h


class TextTranslate
{
    public: 
        TextTranslate(Pen penX, Pen penZ, Engine engine1, Engine engine2);
        void textInit(void);
        void changeStringToBoolTable(String string);
        void printByServo(void);
        bool boolArray[1500];
        int savedBoolCount;
    private:
        Pen _penX;
        Pen _penZ;
        Engine _engine1;
        Engine _engine2;
        
};

#endif
