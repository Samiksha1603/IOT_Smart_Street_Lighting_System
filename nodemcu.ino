#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
#include <Wire.h>

//----------- Enter you Wi-Fi Details---------//
char ssid[] = "OnePlus9R";     //SSID
char pass[] = "Meetali3040";  // Password
//-------------------------------------------//

WiFiClient client;

unsigned long myChannelNumber = 2091705;  // Channel ID here
const int FieldNumberUS1 = 1;
const int FieldNumberUS2 = 2;
const char* myWriteAPIKey = "8RKN50SCRS6QQNZH";  // Your Write API Key here

void setup() {
// Open serial communications and wait for port to open:
Serial.begin(115200);
while (!Serial) {
; // wait for serial port to connect. Needed for native USB port only
}
 WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);}


void loop() { // run over and over
if (WiFi.status() != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    while (WiFi.status() != WL_CONNECTED) {
      WiFi.begin(ssid, pass);
      Serial.print(".");
      delay(5000);
    }
    Serial.println("\nConnected.");
  }
if (Serial.available()) {
  String data = Serial.readStringUntil('\n');
  String US1 = data.substring(0, data.indexOf(','));
  data = data.substring(data.indexOf(',') +1);
  String US2 = data.substring(0, data.indexOf('\r'));
  Serial.println(US2);
 ThingSpeak.writeField(myChannelNumber, FieldNumberUS1, US1, myWriteAPIKey);
 ThingSpeak.writeField(myChannelNumber, FieldNumberUS2, US2, myWriteAPIKey);
}
}