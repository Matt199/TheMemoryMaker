#include "TextTranslate.h"
#include "Arduino.h"
#include <PenAlphabet.h>
#include <Servo.h>
#include <Engine.h>

    TextTranslate::TextTranslate(Pen penX, Pen penZ, Engine engine1, Engine engine2){
        _penX = penX;
        _penZ = penZ;
        _engine1 = engine1;
        _engine2 = engine2;
    }

   

    void TextTranslate::changeStringToBoolTable(String string)
    {
        savedBoolCount = 0;
	    int boolTableIterator = 0;
	    for(int i=0; i<string.length(); i++)
	    {
		    char charToConvert = string.charAt(i);
		    for(int j=0; j<8; j++)
		    {
		    	boolArray[boolTableIterator] = (bool)(charToConvert & 1); //mask on LSB
			    charToConvert >>= 1; //right bitwise shift
			    boolTableIterator++;
		    }
	    }

        savedBoolCount = boolTableIterator;
    }

    void TextTranslate::printByServo(void)
    {
        
        int printIterator = 0;
	    while(printIterator < savedBoolCount)
	    {
		    for(int i=0; i<8; i++)
		    {
		    	if(boolArray[printIterator])
		    	{
                    
			    	_penZ.penDown();
			    	_penX.drawBit();
			    	_penZ.penUp();
			    }
			    else
			    {
   
			    	_penZ.penUp();
			    	_penX.drawBit();
			    }
			    printIterator++;
		    }
            
            // NEXT LINE
            _penX.nextLine();
            delay(400);
            _engine1.startEngine();
            _engine2.startEngine();
            delay(80);
            _engine1.stopEngine();
            _engine2.stopEngine();
            delay(200);
            
	    }
    }
