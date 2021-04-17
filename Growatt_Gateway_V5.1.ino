#include "ESPAsyncWebServer.h"
#include <ModbusRTU.h>
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <ArduinoOTA.h>

#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

WiFiClient Growatt;
WiFiClient Adafruit_Client;
PubSubClient client(Growatt);
ModbusRTU mb;

#include "Settings.h"
#include "Convert_Data.h"
#include "Data_Structure.h"
#include "Webpage.h"
#include "WebserverSetup.h"
#include "Wifi_Setup.h"
#include "JsonBuild.h"
#include "MQTT.h"
#include "Modbus_CallBack.h"
#include "Modbus_Call.h"
#include "AdafruitMQTT.h"
#include "OTA.h"

SoftwareSerial S(Rx, Tx);
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(115200);
  Serial.println();
  S.begin(9600, SWSERIAL_8N1);
  mb.begin(&S,DE_RE); //Assing Software serial port to Modbus instance for MAX485 chip having DI,DE,RE,RO Pin at TTL side
  mb.master();
  setup_wifi();
  asynkweb_setup();
  if (MQTT_Enable) {
    client.setServer(mqtt_server, 1883);
    client.setCallback(callback);
  }
  Webpabe_Update();
  otasetup();
}
void loop() {
  ArduinoOTA.handle();
  ModbusCall();
  mb.task();
  if (MQTT_Enable) {
    Local_MQTT_reconnect();
  }
  if (Ada_MQTT_Enable) {
    Adafruit_Post();
  }
  yield();
}
