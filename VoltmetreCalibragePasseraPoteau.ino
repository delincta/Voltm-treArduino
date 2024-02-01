#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  digitalWrite(7, HIGH);
  
}

void loop() {
  // start 
  float voltDisp = 0.0;
  String unite = "V";
  int sensorValue3_5 = analogRead(A1);
  int sensorValue35 = analogRead(A0);
  int sensorValue350 = analogRead(A2);
  float voltage3_5 = (sensorValue3_5 * (5.0 / 1023.0)-2.5)*2.11;
  float voltage35 = (sensorValue35 * (5.0 / 1023.0)-2.5)*19 ;
  float voltage350 = (sensorValue350 * (5.0 / 1023.0)-2.5)*0.155*1000;
  
  
  //Serial.println(unite);
  lcd.clear();
  
 
  
  
  if ((digitalRead(7) == HIGH)) {
    if (voltage350 > 350) {
      digitalWrite(7, LOW);
      digitalWrite(8, HIGH);
      voltDisp = voltage3_5;
      unite = "V";
    } else {
      voltDisp = voltage350;
      unite = "mV";
    }
  } else if ((digitalRead(8) == HIGH)) {
    if (voltage3_5 < 0.330) {
      digitalWrite(8, LOW);
      digitalWrite(7, HIGH);
      voltDisp = voltage350;
      unite = "mV";
      
    } else if (voltage3_5 > 3.5) {
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      voltDisp = voltage35;
      unite = "V";
      
    } else {
      voltDisp = voltage3_5;
      unite = "V";
      
    }
  } else {
    if (voltage35 < 3.5) {
      digitalWrite(9, LOW);
      digitalWrite(8, HIGH);
      voltDisp = voltage3_5;
      unite = "V";
    } else {
      voltDisp = voltage35;
      unite = "V";
    }
    
    
  }

  lcd.print("Voltage: ");
  lcd.print(voltDisp);
  lcd.print(unite);

  
  delay(1000);
  
  
  
  
}