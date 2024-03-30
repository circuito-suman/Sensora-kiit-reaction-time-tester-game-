#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

#include <cstring> 
#include <string> 
#include <iostream>

using namespace std;

#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883
#define AIO_USERNAME  "your_adafruit_username"
#define AIO_KEY  "your_adafruit_key"
WiFiClient client;
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);




Adafruit_MQTT_Publish ultra = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/Name");



String playerName = "";
    char* char_array = new char[100]; 
int max_points=30;

int sequence[30] = {};
int i,point;


//for esp
const int startLEDPins[] = {D6, D7, D8}; // currently  only D8 is used
const int buttonpins[] = {D0, D1, D2, D5};
int inputpin = D4;

int delayTime = 1000; // for start leds
int BUZZER = A0;










boolean MQTT_connect() 
{  
  int8_t ret;
  if (mqtt.connected()) 
  {    return true; 
  }  
  uint8_t retries = 3;  
  while ((ret = mqtt.connect()) != 0) 
  { 
    mqtt.disconnect(); 
    delay(2000);  
    retries--;
    if (retries == 0) 
    { 
      return false; 
    }
  } 
  return true;
}



void stringtochar() 
{ 

  
  playerName=playerName + " " ;
  playerName.concat(point);

    strcpy(char_array, playerName.c_str()); 
}





void set()
{
  WiFi.disconnect();
  delay(3000);
  Serial.println("wificonnecting");
  WiFi.begin("game","00000000");// put your wifi ssid, password
  while ((!(WiFi.status() == WL_CONNECTED)))
  {
    delay(300);
    Serial.print("..");
  }
  Serial.println("Connected");
  Serial.println("Your IP is");
  Serial.println((WiFi.localIP()));
}
void lop()
{
    if (MQTT_connect()) 
    {
      if (ultra.publish(char_array)) 
      {
        Serial.println("data sent");
      } 
      else 
      {
        Serial.println("data not sent");
      }
    } 
    else 
    {
      Serial.println("mqtt not connected");
    }
}





void IRAM_ATTR  point_count() // Counting point when interrupt encounters
{ 
    digitalWrite(sequence[i], LOW);
     point = point + 1;
}



void generateRandomSequence() {
  for (int i = 0; i < max_points; i++) {
    int randomIndex = random(0, 4); 

    switch (randomIndex) {
      case 0:
        sequence[i] = 16;  //D0
        break;
      case 1:
        sequence[i] = 5;  //D1
        break;
      case 2:
        sequence[i] = 4;  //D2
        break;
      case 3:
        sequence[i] = 14;  //D5
        break;
    }
  }
}











void setup()
{
    Serial.begin(115200);
    set();
    randomSeed(analogRead(0)); // Seed the random number generator
  generateRandomSequence();

    for (int K = 0; K<3; ++K)
    {
        pinMode(startLEDPins[K], OUTPUT);
        digitalWrite(startLEDPins[K], LOW);
    }
for(int a=0;a<4;a++){
  pinMode(buttonpins[a],OUTPUT);
}
    pinMode(inputpin, INPUT);
    attachInterrupt(digitalPinToInterrupt(inputpin), point_count, RISING);
    point=0;
}



void readPlayerName() {
    Serial.println("Enter your name:");
    while (Serial.available() == 0) {} 
    playerName = Serial.readStringUntil('\n');
    Serial.println("Hello, " + playerName + "! Get ready to play the game!");
}






// start animation part
void raceStartAnimation()
{
    digitalWrite(startLEDPins[2], HIGH); 
    delay(delayTime*3); 

    digitalWrite(startLEDPins[2], LOW);
    delay(delayTime);
    Serial.println("START");
}

void loop()
{
    int j;

 readPlayerName();
 

    raceStartAnimation();


        for (i = 0; i <= max_points; i++) // Starting game sequence
        {
            digitalWrite(sequence[i], HIGH);
            delay(400);
            digitalWrite(sequence[i], LOW);
            delay(70);
        }

 stringtochar();
 Serial.println(playerName);
   lop();
    Serial.println(point); 

    point=0;

   delay(2000);

        
}