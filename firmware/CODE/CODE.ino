
#define BLYNK_TEMPLATE_ID           "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME         "YOUR_TEMPLATE_NAME"
#define BLYNK_AUTH_TOKEN            "YOUR_AUTH_TOKEN"



#define BLYNK_PRINT Serial
#include <Blynk.h>
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>



#include <LiquidCrystal.h>
LiquidCrystal lcd(33,25,26,27,14,13);

#define R1 15
#define R2 2
#define R3 4
#define R4 5

#define R5 22
#define R6 21

#define MOI 35
#define TOG 34


int man,moi;

byte values[11];
char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "YOU_WIFI_SSID";             //WiFi SSID
char pass[] = "YOUR_WIFI_PASSWORD";        //WiFi Password


int x1,x2,x3,x4,x5,x6,x7,x8,x9,x10;

BLYNK_WRITE(V0) 
{
x1 = param.asInt();
if(x1==1){digitalWrite(R1,HIGH);digitalWrite(R2,LOW);digitalWrite(R3,HIGH);digitalWrite(R4,LOW);Serial.println("Forward");} 
if(x1==0){digitalWrite(R1,LOW);digitalWrite(R2,LOW);digitalWrite(R3,LOW);digitalWrite(R4,LOW);} // FORWARD
}
BLYNK_WRITE(V1) 
{
x2 = param.asInt();
if(x2==1){digitalWrite(R2,HIGH);digitalWrite(R1,LOW);digitalWrite(R4,HIGH);digitalWrite(R3,LOW);Serial.println("Reverse");} 
if(x2==0){digitalWrite(R1,LOW);digitalWrite(R2,LOW);digitalWrite(R3,LOW);digitalWrite(R4,LOW);} // REVERSE
}
BLYNK_WRITE(V2) 
{
x5 = param.asInt();
if(x5>900){digitalWrite(R1,HIGH);digitalWrite(R2,LOW);digitalWrite(R4,HIGH);digitalWrite(R3,LOW);Serial.println("RIGHT");} 
else if(x5<100){digitalWrite(R2,HIGH);digitalWrite(R1,LOW);digitalWrite(R3,HIGH);digitalWrite(R4,LOW);Serial.println("LEFT");} 
else{digitalWrite(R1,LOW);digitalWrite(R2,LOW);digitalWrite(R3,LOW);digitalWrite(R4,LOW);} 
}
BLYNK_WRITE(V3) 
{
x3 = param.asInt();
if(x3==1 && man==0){digitalWrite(R5,HIGH);Serial.println("PUMP ON");} 
if(x3==0 && man==0){digitalWrite(R5,LOW);Serial.println("PUMP OFF");} // RIGHT 
}
BLYNK_WRITE(V4) 
{
x3 = param.asInt();
if(x3==1){digitalWrite(R6,HIGH);Serial.println("SEED ON");} 
if(x3==0){digitalWrite(R6,LOW);Serial.println("SEED OFF");} // RIGHT 
}



void setup()
{
    Serial.begin(9600);
    lcd.begin(16,2);
    lcd.setCursor(0,0);lcd.print("  SEED  SOWING  ");
    lcd.setCursor(0,1);lcd.print("     ROBOT!     ");
  
      
pinMode(R1, OUTPUT);
pinMode(R2, OUTPUT);
pinMode(R3, OUTPUT);
pinMode(R4, OUTPUT);
pinMode(R5, OUTPUT);
pinMode(R6, OUTPUT);


pinMode(TOG, INPUT);

digitalWrite(R1,LOW);digitalWrite(R2,LOW);digitalWrite(R3,LOW);digitalWrite(R4,LOW);
digitalWrite(R5,LOW);digitalWrite(R6,LOW);

   delay(1500);
   lcd.clear();
   lcd.setCursor(0,0);lcd.print("...CONNECTING...");
   Blynk.begin(auth, ssid, pass);
   lcd.setCursor(0,1);lcd.print("......DONE......");
   delay(1500);
   lcd.clear();
 

 
}
 
void loop()
{

    Blynk.run();
    if(digitalRead(TOG)==LOW){man=1;lcd.setCursor(0,0);lcd.print("MODE:AUTO  ");}
    if(digitalRead(TOG)==HIGH){man=0;lcd.setCursor(0,0);lcd.print("MODE:MANUAL");}

moi=analogRead(MOI);
lcd.setCursor(0,1);lcd.print("MOISTURE:");Lcd_Decimal4(9,1,moi);

    if(man==1)
    {
      
      if(moi<500)
      {
        digitalWrite(R5,LOW);
      }
      if(moi>500)
      {
        digitalWrite(R5,HIGH);
      }
    }
}
void Lcd_Decimal4(unsigned char col, unsigned char row,unsigned int dispVal)
{
  unsigned char thou,huns,tens,ones;

    thou=(dispVal%10000)/1000;
    huns=(dispVal%1000)/100;
    tens=(dispVal%100)/10;
    ones=(dispVal%10);

    lcd.setCursor(col+0,row);lcd.print(thou); 
    lcd.setCursor(col+1,row);lcd.print(huns); 
    lcd.setCursor(col+2,row);lcd.print(tens);
    lcd.setCursor(col+3,row);lcd.print(ones);
    
}

