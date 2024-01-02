#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
String textMessage;
String redledState = "HIGH";
String blueledState = "HIGH";
String greenledState = "HIGH";
const int blueled = 10;
const int greenled = 11;
const int redled = 12;
void setup() {
  lcd.begin();
  pinMode(redled, OUTPUT);
  pinMode(blueled, OUTPUT);
  pinMode(greenled, OUTPUT);
  lcd.setCursor(0,0);
  lcd.print("GSM Based Home");
  lcd.setCursor(0,1);
  lcd.print("   Automaton    ");
  delay(2000);
  digitalWrite(redled, HIGH);
  digitalWrite(blueled, HIGH);
  digitalWrite(greenled, HIGH);
  Serial.begin(19200);
  delay(20000);
  Serial.print("AT+CMGF=1\r"); 
  delay(100);
  Serial.print("AT+CNMI=2,2,0,0,0\r");
  delay(100);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("GREEN BLUE RED");
  lcd.setCursor(0,1);
  lcd.print("  ON   ON  ON ");
}
void loop(){
  if(Serial.available()>0){
    textMessage = Serial.readString(); 
    textMessage.toUpperCase();   
    delay(10);
  } 
  if (textMessage.indexOf("REDON")>=0){
     lcd.print("GREEN BLUE RED");
      lcd.clear(); 
      lcd.print("  ON   ON  ON ");
     digitalWrite(redled, HIGH);
     redledState = "on"; 
     textMessage = "";   
  }
  if(textMessage.indexOf("REDOFF")>=0){
    lcd.print("GREEN BLUE RED");
      lcd.clear(); 
      lcd.print("  ON   ON  OFF ");
     digitalWrite(redled, LOW);
     redledState = "off"; 
     textMessage = ""; 
  }
     if(textMessage.indexOf("BLUEON")>=0){
     lcd.print("GREEN BLUE RED");
      lcd.clear(); 
      lcd.print("  ON   ON  ON ");
    digitalWrite(blueled, HIGH);
    blueledState = "on"; 
    textMessage = "";   
  }
   if(textMessage.indexOf("BLUEOFF")>=0){
     lcd.setCursor(8,1); 
     lcd.print("OFF");
    digitalWrite(blueled, LOW);
    blueledState = "off"; 
    textMessage = ""; 
  }
    if(textMessage.indexOf("GREENON")>=0){
     lcd.setCursor(3,1); 
     lcd.print("ON");
    digitalWrite(greenled, HIGH);
    greenledState = "on"; 
    textMessage = "";   
  }
  if (textMessage.indexOf("GREENOFF")>=0){
     lcd.setCursor(3,1); 
     lcd.print("ON");
    digitalWrite(greenled, LOW);
    greenledState = "off"; 
    textMessage = ""; 
  }
}  