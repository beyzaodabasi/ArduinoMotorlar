#include <LiquidCrystal.h>
#include <Keypad.h>
#include <Servo.h>

//LCD
LiquidCrystal lcd {2,3,4,5,6,7};

int led = 13;

//Keypad
const byte satir=4;
const byte sutun=4;

char tusTakimi[satir][sutun] = {
  
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte satirPins[satir] = {A4, A3, A2, A1}; 
byte sutunPins[sutun] = {11, 10, 9, 8};

Keypad keypad = Keypad( makeKeymap(tusTakimi), satirPins, sutunPins, satir, sutun );

//Motor
Servo motor;
String girilenSifre = "";
String sifre = "1234";

void setup()
{
  Serial.begin(9600);
  
  lcd.begin(16,2);
  motor.attach(12);
  motor.write(0);
  pinMode(led, OUTPUT);
 
}

void loop()
{
 
  //Keypad
  char tus = keypad.getKey();
  if(tus){
    
    switch(tus){
      
      case '*':
      lcd.clear();
      girilenSifre = ""; 
      motor.write(0);
      digitalWrite(led, LOW);
      lcd.write("Kapali");    
      break;
      
      
      case '#':
      if(girilenSifre==sifre){
        motor.write(90);
        digitalWrite(led, HIGH);
        lcd.setCursor(0,1);
        lcd.write("Kilit Acik");
        
      }
      else{
        lcd.setCursor(0,1);
        lcd.write("Sifre Gecersiz");
        digitalWrite(led, LOW);
      }
      
      girilenSifre="";
      break;
      
      case 'D':
      lcd.clear();
      break;
      
      default:
      lcd.write(tus);
      girilenSifre+=tus;
      break;
    }

  }
}
