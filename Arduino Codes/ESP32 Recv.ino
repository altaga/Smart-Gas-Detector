#include <WiFi.h>
#include <PubSubClient.h>
 
const char* ssid = "YOUR_SSID";
const char* password =  "YOUR_PWRD";
const char* mqttServer = "YOUR_MQTT_SERVER";
const int mqttPort = "YOUR_MQTT_PORT";
const char* mqttUser = "YOUR_MQTT_USER";
const char* mqttPassword = "YOUR_MQTT_PWRD";

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
  if(pay=="FAN ON")
  {
   digitalWrite(12,LOW);
   Serial.println("FAN ON"); 
  }
  else if (pay=="FAN OFF")
  {
   digitalWrite(12,HIGH); 
   Serial.println("FAN OFF"); 
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
