
#include "Arduino.h"
#include "Engine.h"

Engine::Engine(int motorV, int right, int left)
{
    _motorV = motorV;
    _right = right;
    _left = left;
}

Engine::Engine(){}

void Engine::initEngine(void)
{
    pinMode(_motorV,OUTPUT);
    pinMode(_right,OUTPUT);
    pinMode(_left,OUTPUT);
}

void Engine::startEngine(void)
{
    digitalWrite(_right, HIGH);
    digitalWrite(_left, LOW);
    analogWrite(_motorV, 90);
}

void Engine::stopEngine(void)
{
     digitalWrite(_right, HIGH);
     digitalWrite(_left, HIGH);

}


void Engine::nextLine(void)
{
      startEngine();
      delay(50);
      stopEngine();
      delay(2000);
}
