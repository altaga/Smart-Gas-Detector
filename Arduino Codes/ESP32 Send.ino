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
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  String pay="";
  Serial.println(pay);
  for (int i=0;i<length;i++) 
  {
    pay+=(char)payload[i];
  }
  Serial.print(pay);
  Serial.println();
}
 
void setup() {
 
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
 
    if (client.connect("ESP32Client", mqttUser, mqttPassword )) {
 
      Serial.println("connected");
 
    } else {
 
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
 
    }
  }
  client.setCallback(callback);
  client.subscribe("esp/test2");
}
 
void loop() {
  client.loop();
    for(int i=0;i<100;i++)
  {
   sensorValue+= analogRead(A0);
   delayMicroseconds(500); 
  }

  sensorValue/=100;
  // map it to the range of the analog out:
  // change the analog out value:
    if (sensorValue< 800)
  {
     if (flag ==0)
    {
     client.publish("esp/test", "Apagado");  
    }
    flag=1;
   Serial.println(0);
   counter=0;
  }
  else if ((sensorValue>= 800) && (counter > 5))
  {
    if (flag==1)
    {
     client.publish("esp/test", "Encendido");  
    }
    flag=0;
   Serial.println(sensorValue);
   
  }
  else
  {
    Serial.println(0);
    counter+=1;
  }
}
