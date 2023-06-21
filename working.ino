//code by ak
//https://github.com/ripgamer/SD
#include <LCD_I2C.h>
#define BLYNK_TEMPLATE_ID "TMPL3oPKoZBcz"
#define BLYNK_TEMPLATE_NAME "led"
#define BLYNK_AUTH_TOKEN "o2UZlCZY_IA28AGr-H7gkuoyEfTuazbr"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ESP";
char pass[] = "87654321";

// Hardware Serial on Mega, Leonardo, Micro...
//#define EspSerial Serial1

// or Software Serial on Uno, Nano...
#include <SoftwareSerial.h>
SoftwareSerial EspSerial(2, 3); // RX, TX

// Your ESP8266 baud rate:
#define ESP8266_BAUD 9600
int GAUGE_VPIN V1;
bool ledState = false;

ESP8266 wifi(&EspSerial);
LCD_I2C lcd(0x27, 16, 2);// Default address of most PCF8574 modules

int timer1;
int timer2;

float Time;

int flag1 = 0;
int flag2 = 0;

float distance = 5.0;
float speed;
int scalingFactor = 1;

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
  Serial.begin(74880);
  
  
  
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" WELCOME To SDS");
  lcd.setCursor(0,1);
  lcd.print("SPEED DETECTOR");
  delay(10);
  lcd.clear();
  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
  delay(10);
  Blynk.begin(BLYNK_AUTH_TOKEN, wifi, ssid, pass, "blynk.cloud", 80);
  //Blynk.virtualWrite(V1,speed);
}

void loop() {
 
Blynk.virtualWrite(GAUGE_VPIN,speed);
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
  //speed update (speedometer)
  // Update Blynk
  // int gaugeValue = static_cast<int>(speed* scalingFactor);

  // // Update gauge widget
  // Blynk.virtualWrite(GAUGE_VPIN,speed);

  
}
