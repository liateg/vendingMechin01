#include <Stepper.h>
const int stepsPerRevolution = 200;
// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
#include <LiquidCrystal.h>
//LCD RS pin to digital pin 12
//LCD Enable pin to digital pin 11
//LCD D4 pin to digital pin 5
//LCD D5 pin to digital pin 4
//LCD D6 pin to digital pin 3
//LCD D7 pin to digital pin 2
//LCD R/W pin to ground
//ends to +5V and ground
//wiper to LCD VO pin (pin 3)
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <TMRpcm.h>
#include <SPI.h>
#define SD_cardpin 4    //pin numbere whwer CS plug to arudino
#include <SD.h>
TMRpcm tmrpcm;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <Servo.h>
Servo myservo1;  //myservo1 is servo for pad1
Servo myservo2;  // myservo2 is servo for pad2
int pos1 = 0;    // variable to store the servo position
// pos1 is the position of myservo1
int pos2 = 0;    // pos2 is the position of myservo2
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int total_amount = 0;
int limitswitch1_pulse = 0;    //limitswitch1 for 1 Birr
int limitswitch2_pulse = 0;    //limitswitch for 50Cent
int pad1 = 40;     //pad1 is use and throw pads
int pad2 = 40;     //pad2 is reusable pads
int limitswitch1 = 7;
int limitswitch2 = 8;
int Credit = limitswitch1_pulse + limitswitch2_pulse / 2;      // variable for the sum of limitswitchs
////////////////////////////////////////////////////////////////////////////////////////
void setup() {
  myservo1.attach(13);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(12);
  pinMode (limitswitch1, INPUT);
  pinMode (limitswitch2, INPUT);
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  Serial.begin(9600);
  lcd.begin(16, 2);
  // when characters arrive over the serial port...
  bool (Serial.print(total_amount) == true);
  while (!Serial.print(total_amount)) {
    if (Serial.available() ) {
      // wait a bit for the entire message to arrive
      delay(100);
      // clear the screen
      lcd.clear();
      // read all the available characters
      while (Serial.available() > 0 ) {
        // display each character to the LCD
        lcd.write(Serial.print());
      }
    }
  }
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  tmrpcm.speakerPin = 9;    //transisitor to arduino
  Serial.begin(9600);
  if (!SD.begin(SD_cardpin)) {
    Serial.print("SD faild");
  }
  tmrpcm.setVolume(5);
}
void loop()
{
  while (pad1 > 0) {
    if (digitalRead(limitswitch1 == LOW)) {
      limitswitch1_pulse++;
      Serial.print("Your balance.   ");
      Serial.print(Credit);
      Serial.println("Birr");
      Serial.print("Need more");
      Serial.print(3 - Credit);
      Serial.println("Birr");
      tmrpcm.play("sound1");
      delay(100);
      lcd.clear();
    }
    else {
      limitswitch1_pulse == 0;
    }
    if (digitalRead(limitswitch2 == LOW)) {
      limitswitch2_pulse = +1;
      Serial.print("Your balance.   ");
      delay(2000);
      Serial.print(Credit);
      delay(500);
      Serial.println("Birr");
      delay(500);
      Serial.print("Need more");
      delay(100);
      Serial.print(3 - Credit);
      Serial.println("Birr");
      tmrpcm.play("sound2");
      delay(100);
      lcd.clear();
    }
    else {
      limitswitch2_pulse == 0;
    }
    if (limitswitch1_pulse + limitswitch2_pulse / 2 == 3) {
      // step one revolution  in one direction:
      myStepper.step(stepsPerRevolution);
      delay(500);
      limitswitch1_pulse == 0;
      limitswitch2_pulse == 0;
      for (pos1 = 0; pos1 <= 270; pos1 += 1) { // goes from 0 degrees to 270 degrees
        // in steps of 1 degree
        myservo1.write(pos1);              // tell servo to go to position in variable 'pos'
        pad1--;
        Serial.print("Please take your pad");
        total_amount = +3;
        Serial.print(total_amount);
        delay(1000);
        Serial.print("There are   ");
        delay(500);
        Serial.print(pad1);
        Serial.print("avilaible use and throw sanitary napkins");
        tmrpcm.play("sound3");
        delay(100);
        lcd.clear();
      }
    }
    else {
      pos1 = 0;
      myservo1.write(pos1);
    }
    for (!Credit == 3; !Credit == 0;) {  // if credit is not 3 or 0 ,delay30 seconds and give back inserted coins
      delay(30000);
      // step one revolution  in opposite direction:
      myStepper.step(-stepsPerRevolution);
      delay(500);
    }
  }
  if (pad1 == 0) {
    pos1 == 0;
    myservo1.write(pos1);
    Serial.print("Sorry the machine is ranout of pads");
  }
}
