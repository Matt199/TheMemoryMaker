
#ifndef Engine_h
#define Engine_h

#include "Arduino.h"

class Engine{
    public:
        Engine(int motorV, int right, int left);
        Engine();
        void initEngine(void);
        void startEngine(void);
        void stopEngine(void);
        void nextLine(void);

    private: 
        int _motorV;
        int _right;
        int _left;
};


#endif