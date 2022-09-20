#include <WiFi.h>
#include <PubSubClient.h>
#include "time.h"
#define LED 2

char* ssid = "Bruno";
char* pwd = "123456789";
char* mqtt_server = "test.mosquitto.org";

WiFiClient wclient;
PubSubClient mqttClient(wclient); 

void connectWifi(){
  Serial.println("Conectando...");
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println(" ");
  Serial.print("Conectado ao WiFi com o IP: ");
  Serial.println(WiFi.localIP());
}

void connectMqtt(){
  if (!mqttClient.connected()){
    if (mqttClient.connect("isabelle")){
      Serial.println("Conectou...");
      mqttClient.subscribe("fatec/labs/407/luz/isabelle");
    } else {
      Serial.println("Sem conexão...");
      delay(5000);
    }
  }
}
void callback(char* topic, byte* message, unsigned int length){
  String msg;
  Serial.print(topic);
  Serial.print(" ");
  for (int i = 0; i<length; i++) {
    msg += (char)message[i];
  }
  Serial.println(msg);
  if (msg[1] == 'n')
    digitalWrite(LED, HIGH);
  else
    digitalWrite(LED, LOW);
}

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  WiFi.begin(ssid, pwd);
  connectWifi(); 
  mqttClient.setServer(mqtt_server, 1883);
  mqttClient.setCallback(callback); 
}

void loop() {
  if (!mqttClient.connected()){
    connectMqtt();
  }
  mqttClient.loop();
}
