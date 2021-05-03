#include <Servo.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd {11,12,7,8,9,10};

//sensörler
int ldrPin = A0;
int isik;
int sicaklikPin = A1;
int sicaklik;
int hareketPin = 13;
int hareket = 0;
int led = 12;


//Motor1
int motor1Ileri = 5;
int motor1Geri = 4;

//Motor2
int motor2Ileri = 2;
int motor2Geri = 3;

//Motor3
Servo motor3;

void setup()
{
  
  Serial.begin(9600); 
  
  lcd.begin(16,2);
  
  pinMode(ldrPin, INPUT);
  pinMode(sicaklikPin, INPUT);
  pinMode(hareketPin, INPUT);
  
  pinMode(motor1Ileri, OUTPUT);
  pinMode(motor1Geri, OUTPUT);
  pinMode(motor2Ileri, OUTPUT);
  pinMode(motor2Geri, OUTPUT);
  
  pinMode(led, OUTPUT);
  
  motor3.attach(6);
  motor3.write(0);
}
void loop()
{ 

  //isik
  isik=analogRead(ldrPin);
  Serial.print("Isik: ");
  Serial.println(isik);
  
  if(isik<85){
    digitalWrite(motor1Ileri, HIGH);
 
  }
  else{
    digitalWrite(motor1Ileri, LOW);
     
  }

  delay(1000);
     
  
  //sicaklik
  sicaklik=((analogRead(sicaklikPin)*4.88)-500)/10;
  Serial.print("sicaklik: ");
  Serial.println(sicaklik);
  
  lcd.setCursor(0,0); //1. satır
  lcd.print("sicaklik: ");
  lcd.setCursor(0,1); //2. satır
  lcd.print(sicaklik);
  lcd.print(" C"); 
  
  
  if(sicaklik>50){
    digitalWrite(motor2Ileri, HIGH);
  }
  else{
    digitalWrite(motor2Ileri, LOW);
  }
  delay(1000);
  
  
  //hareket  
  hareket=digitalRead(hareketPin);
  Serial.print("hareket: ");
  Serial.println(hareket);
  
  if(hareket==1){
    motor3.write(90);  
    //delay(300);
  }
  else{
    motor3.write(0);
    //delay(300);
  } 
  
}
