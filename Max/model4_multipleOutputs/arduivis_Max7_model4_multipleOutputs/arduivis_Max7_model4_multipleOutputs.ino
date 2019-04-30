/* 

~~~~~~~ arduivis - MaxMSP ~~~~~~~~
~~~~~ model#4: multiple outputs ~~~~~

MaxMSP: arduivis_Max7_model4_multipleOutputs.maxpat

This is an example of how to use a loop to write
several streams of data to MaxMSP, from an Arduino.
A fading LED is used to provide visual feedback for
this process.

This code is in the public domain

written by Christopher Konopka
http://cskonopka.github.io/arduivis/
http://christopherkonopka.com/

*/

void setup() 
{ 
  // Create/open serial port
  Serial.begin(9600);  

  // Define LED mode 
  // PWM LED  
  pinMode(3, OUTPUT);     
  pinMode(5, OUTPUT);     
  pinMode(6, OUTPUT);     
  pinMode(9, OUTPUT);     
}

void loop() 
{ 
  // Loop variables
  int lp;
  int startIncrement = 0; 
  int incrementLoopRange = 255; 
  int startDecrement = 255;
  int decrementLoopRange = 0;
        

  // Loop Function        
  lp = loopSystem(startIncrement, incrementLoopRange, startDecrement, decrementLoopRange);

}

int loopSystem(int startIncrement, int incrementLoopRange, int startDecrement, int decrementLoopRange)
{
  int lp;

  // Loop #1
  // Incremental Loop
  for(lp = startIncrement; lp < incrementLoopRange; lp++)         
  {
    // Incremental loop values to LED
    // Controls fade of 4 LEDs
    analogWrite(3, lp);    
    analogWrite(5, lp);
    analogWrite(6, lp);
    analogWrite(9, lp);

      // Incremental loop values to serial buffer
      // [serial] object
      // to MaxMSP, from Arduino
      Serial.print(lp);
      Serial.print(" ");
      Serial.print(lp);
      Serial.print(" ");
      Serial.print(lp);
      Serial.print(" ");
      Serial.println(lp);

        delay(10);
  }

  // Loop #2
  // Decremental Loop
  for(lp = startDecrement; lp > decrementLoopRange; lp--)    
  {
    // Deremental loop values to LED
    // Controls fade of 4 LEDs
    analogWrite(3, lp);    
    analogWrite(5, lp);
    analogWrite(6, lp);
    analogWrite(9, lp);

      // Decremental loop values to serial buffer
      // [serial] object
      // to MaxMSP, from Arduino  
      Serial.print(lp);    
      Serial.print(" ");      
      Serial.print(lp);
      Serial.print(" ");      
      Serial.print(lp);
      Serial.print(" ");      
      Serial.println(lp);

        delay(10);
  }
}
