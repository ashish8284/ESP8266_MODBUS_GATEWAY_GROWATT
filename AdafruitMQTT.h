boolean AdaMQTTSTS = LOW;
#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883                   // use 8883 for SSL
Adafruit_MQTT_Client mqtt(&Adafruit_Client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);
unsigned long AdaMqttDly;
String Topic[] = {"Sts", "PI_Amp", "PV_Vlt", "E_Tot", "E_Today"};

//Topics
Adafruit_MQTT_Publish Sts = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/Sts");
Adafruit_MQTT_Publish PI_Amp = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/PI_Amp");
Adafruit_MQTT_Publish PV_Vlt = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/PV_VLt");
Adafruit_MQTT_Publish E_Tot = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/E_Tot");
Adafruit_MQTT_Publish E_Today = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/E_Today");

void  Adafruit_Connect();

void Adafruit_Post() {
  if ((millis() - AdaMqttDly) > AdaMqttDly_Window) {
    Adafruit_Connect();
    AdaMqttDly = millis();
    Webpabe_Update();
    ArduinoOTA.handle();
    if (AdaMQTTSTS) {
      Serial.println("Updating on Adafruit");
      if (! Sts.publish(STATE)) {
        //Serial.println(F("Failed"));
      } else {
        //Serial.println(F("OK!"));
      }
      if (! PI_Amp.publish(PV_AMP)) {
        //Serial.println(F("Failed"));
      } else {
        //Serial.println(F("OK!"));
      }
      if (! PV_Vlt.publish(PV_VLT)) {
        //Serial.println(F("Failed"));
      } else {
        //Serial.println(F("OK!"));
      }
      if (! E_Today.publish(PV_ENER_TODY_L)) {
        //Serial.println(F("Failed"));
      } else {
        //Serial.println(F("OK!"));
      }
      if (! E_Tot.publish(PV_ENER_TOT_L)) {
        //Serial.println(F("Failed"));
      } else {
        //Serial.println(F("OK!"));
      }
    }
    AdaMQTTSTS = LOW;
  }
}
void Adafruit_Connect() {
  ArduinoOTA.handle();
  int8_t ret;
  if (mqtt.connected()) {
    AdaMQTTSTS = HIGH;
    return;
  }
  Serial.println("Connecting to Adafruit MQTT... ");
  if ((ret = mqtt.connect()) != 0) {
    Serial.println(mqtt.connectErrorString(ret));
    ArduinoOTA.handle();
    Serial.println("Adafruit MQTT not connected Retry interval is 5 minutes");
    AdaMQTTSTS = LOW;
  }
}
