//code by ak
//https://github.com/ripgamer/SG
#include <LCD_I2C.h>
#define BLYNK_TEMPLATE_ID "ADD YOUR TEMPLATE_ID HERE"
#define BLYNK_TEMPLATE_NAME "<ADD YOUR TEMPLATE NAME HERE>"
#define BLYNK_AUTH_TOKEN "<ADD YOUR AUTH_TOKEN HERE>"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "<SSID>";
char pass[] = "<PASS>";

// Hardware Serial on Mega, Leonardo, Micro...
//#define EspSerial Serial1

// or Software Serial on Uno, Nano...
#include <SoftwareSerial.h>
SoftwareSerial EspSerial(2, 3); // RX, TX

// Your ESP8266 baud rate:
#define ESP8266_BAUD 9600
#define GAUGE_VPIN V1
bool ledState = false;

ESP8266 wifi(&EspSerial);
LCD_I2C lcd(0x27, 16, 2);// Default address of most PCF8574 modules

int timer1;
int timer2;

float Time;

int flag1 = 0;
int flag2 = 0;

float distance = 4.5;
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
  lcd.print("G14 G25 G03 G01 G40");
  lcd.setCursor(0,1);
  lcd.print("connecting...");
  delay(500);
 // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
  delay(10);
  
  Blynk.begin(BLYNK_AUTH_TOKEN, wifi, ssid, pass, "blynk.cloud", 80);
  //Blynk.virtualWrite(V1,speed);
  lcd.clear();
}

void loop() {


//Blynk.virtualWrite(GAUGE_VPIN,speed);
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
    //lcd.backlight();
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
    // Update gauge widget
    Blynk.virtualWrite(GAUGE_VPIN,speed);
  }
  else
  {
    lcd.backlight();
    lcd.print("  Normal Speed   ");
    Serial.println("  Normal Speed   "); 
    // Update gauge widget
    Blynk.virtualWrite(GAUGE_VPIN,speed);
  }    
    delay(3000);
    digitalWrite(buzzer, LOW);
    Blynk.virtualWrite(GAUGE_VPIN,speed);
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
