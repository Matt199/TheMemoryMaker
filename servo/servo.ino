#include <Engine.h>
#include <PenAlphabet.h>
#include <TextTranslate.h>
#include <Servo.h>

  String input = "";

  /* 
   * CREATE SERVOS OBJECT  
   */
Servo servoZ;
Servo servoX;

  /* 
   * CREATE PEN OBJECT 
   */
Pen penZ(13, servoZ);
Pen penX(12, servoX);

  /* 
   * CREATE ENGINE OBJECT 
   */
Engine engine1(3, 2, 4);
Engine engine2(5, 7, 8);

  /* 
   * CREATE TEXT TRANSLATE OBJECT 
   */
TextTranslate textTranslate(penX, penZ, engine1, engine2); 
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

      
  /* 
   * -----------------------------
   * INIT TWO SERVOS FOR X and Z axis  
   * SET BASE POSITION
   */
  penZ.servoInit(60);
  penX.servoInit(0);
  /* 
   * -----------------------------
   * INIT TWO MOTORS FOR PAPER ROLL 
   */
  engine1.initEngine();
  engine2.initEngine();
  /* 
   * -----------------------------
   * ITRANSLATE THE WORD IN BINARY FORM AND PRINT BY MOVING THE SERVOS  
   */

 
   
  
}

void loop() {
readSerial();
}


void readSerial(){

       /*
        * READ DATA FROM PROCESING
        */
        
         if(Serial.available()) {
            delay(100); //Wait for all data to be received
            while(Serial.available()) {
            input = Serial.readString();

       
             textTranslate.changeStringToBoolTable(input);
              textTranslate.printByServo();
        
       
      }
   }

   
  }
  
