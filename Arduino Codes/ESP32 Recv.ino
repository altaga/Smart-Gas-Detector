#include <WiFi.h>
#include <PubSubClient.h>
 
const char* ssid = "Alta Int";
const char* password =  "Altamirano0128";
const char* mqttServer = "m12.cloudmqtt.com";
const int mqttPort = 13853;
const char* mqttUser = "ijplykav";
const char* mqttPassword = "tLPKg_Y3FDy_";

float sensorValue= 0;        // value read from the pot
int counter=0;
int flag =0;
 
WiFiClient espClient;
PubSubClient client(espClient);

void callback(char* topic, byte* payload, unsigned int length) {
  String pay="";
  for (int i=0;i<length;i++) 
  {
    pay+=(char)payload[i];
  }
  Serial.print(pay);
  if(pay=="Encendido")
  {
   digitalWrite(12,LOW);
   Serial.println("Encenciendo Ventilador"); 
  }
  else
  {
   digitalWrite(12,HIGH); 
   Serial.println("Apagando Ventilador"); 
  }
  Serial.println();
}
 
void setup() {
  pinMode(12,OUTPUT);
  digitalWrite(12,HIGH);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println("Connected to the WiFi network");
 
  client.setServer(mqttServer, mqttPort);
 
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
 
    if (client.connect("ESP32Client2", mqttUser, mqttPassword )) {
 
      Serial.println("connected");
 
    } else {
 
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
 
    }
  }
  client.setCallback(callback);
  client.subscribe("esp/test");
}
 
void loop() {
  client.loop();
}
