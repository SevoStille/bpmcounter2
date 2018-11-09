/*
 * BPM counter
 * 
 * Small utility to display BPM on a 16x2 I2C LED display 
 * Written for DIN Sync devices like the TR-606.  
 * Counts timer between pulses, gets more accurate on a slow clock, but has some  
 * jitter unless you stabilize the input (with a Schmitt trigger or the like).
 * For less jitter from a fast clock, like 96ppq use my bpmcounter3 utility 
 * (which calculates speed from the number of pulses in a second)
 * 
 * Connect the (TTL level) clock signal to pin 2 (and ground to GND) - e.g. 
 * DIN Sync Pin 3 to Arduino Uno Pin 2, DIN Pin 2 to any GND terminal on the Uno 
 * 
 * Copyright 2018 Sevo Stille <mailto:sevo@radiox.de>
 * @license GPL-3.0+ <http://www.gnu.org/licenses/gpl.html>
 * 
*/


#include <LiquidCrystal_I2C.h> // For display

LiquidCrystal_I2C lcd(0x3F, 16, 2); // default 16/2 I2C display

const int ticks_per_beat = 96; // ENTER PULSE PER QUARTER CLOCK RATE HERE  (My JMS studio clock goes up to 96ppq output, 
                               // for Korg DIN sync you'd want 48, for Roland 24) 

 
int ledPin = LED_BUILTIN ;           //   STATUS LED
 
int led = 0, ledc = 0;  //  INTEGERS TO STORE LED VALUE AND COUNTER

int input = 2;                // input at pin 2
volatile byte counter;        // tick counter
float bpm;                    // BPM value
unsigned long time, currtime, prevtime;          // time between ticks

// timer interrupt function, invoked by each tick on pin, updates counter and LED 
void isr()
 {
   //On each tick calculate time difference

      currtime  = micros();
      time = currtime-prevtime;
      prevtime=currtime;

 }

 void setup()
 {
   attachInterrupt(0, isr, RISING);     //  ADD AN INTERRUPT FOR EACH TICK INPUT   
   pinMode(ledPin, OUTPUT); // Set LED OUT
   pinMode(input, INPUT); // Sets input
   counter = 0;

   lcd.init(); //Init display 
   lcd.backlight(); //Power up backlight  
     lcd.print("BPM Counter");           
     lcd.setCursor(0, 1);
     lcd.print("by sevo");          
     delay(2000);                     // pause
     lcd.clear();
     lcd.setCursor(0, 0);
     lcd.print("BPM counting");       // go
       
}

 void loop()
 {
   delay(250);//Update RPM four times per second

   detachInterrupt(0); // Halt interrupt

   bpm = ((1000000.0/time)/ticks_per_beat)*240; // for ppq

     lcd.setCursor(0, 0);
     lcd.print(time,DEC);                        //  PRINT tick count
     lcd.print(" micros      ");                       

     lcd.setCursor(0, 1);
     lcd.print(bpm,2);                        //  PRINT BPM
     lcd.print(" BPM           ");


   attachInterrupt(0, isr, RISING);   //Restart interrupt 
  
 }

 
