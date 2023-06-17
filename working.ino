//code by ak
//https://github.com/ripgamer/SD
//working 16x2 SDA@A04 SCL@A05 , vcc1@8 , vcc2@9, buzzer@13 ,BT1@A01,BT2@A01 v01
#include <LCD_I2C.h>
LCD_I2C lcd(0x27, 16, 2);// Default address of most PCF8574 modules

int timer1;
int timer2;

float Time;

int flag1 = 0;
int flag2 = 0;

float distance = 5.0;
float speed;

int ir_s1 = A0;
int ir_s2 = A1;

int buzzer = 13;
int vcc1 = 8;
int vcc2 = 9;

void setup(){
  pinMode(ir_s1, INPUT);
  pinMode(ir_s2, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(vcc1, OUTPUT);
  pinMode(vcc2, OUTPUT);
  digitalWrite(vcc1,HIGH);
  digitalWrite(vcc2,HIGH);
  Serial.begin(9600);
  
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" WELCOME To SDS");
  lcd.setCursor(0,1);
  lcd.print("SPEED DETECTOR");
  delay(2000);
  lcd.clear();
}

void loop() {

if(digitalRead (ir_s1) == LOW && flag1==0){timer1 = millis(); flag1=1;}

if(digitalRead (ir_s2) == LOW && flag2==0){timer2 = millis(); flag2=1;}

if (flag1==1 && flag2==1){
     if(timer1 > timer2){Time = timer1 - timer2;}
else if(timer2 > timer1){Time = timer2 - timer1;}
 Time=Time/1000;//convert millisecond to second
 speed=(distance/Time);//v=d/t
 speed=speed*3600;//multiply by seconds per hr
 speed=speed/1000;//division by meters per Km
}

if(speed==0){ 
lcd.setCursor(0, 1); 
if(flag1==0 && flag2==0)
{
  lcd.backlight();
  lcd.print("No car  detected");
  Serial.println("No car  detected");
}
else
{
  lcd.backlight();
  lcd.print("Searching...    ");} 
  Serial.println("Searching...    ");
}
else{
    lcd.backlight();
    lcd.clear(); 
    lcd.setCursor(0, 0); 
    lcd.print("Speed:");
    Serial.println("Speed:");
    lcd.print(speed,1);
    Serial.println(speed,1);
    lcd.print("Km/Hr  ");
    Serial.println("Km/Hr  ");
    lcd.setCursor(0, 1); 
  if(speed > 50)
  {
    lcd.print("  Over Speeding  ");
    for (int i = 0; i < 5; ++i) //Flashing the backlight
    {
        lcd.backlight();
        digitalWrite(buzzer, HIGH);
        delay(50);
        lcd.noBacklight();
        digitalWrite(buzzer, LOW);
        delay(50);
        lcd.backlight();
    }
    Serial.println("  Over Speeding  ");
  }
  else
  {
    lcd.backlight();
    lcd.print("  Normal Speed   ");
    Serial.println("  Normal Speed   "); 
  }    
    delay(3000);
    digitalWrite(buzzer, LOW);
    speed = 0;
    flag1 = 0;
    flag2 = 0;    
 }
}
