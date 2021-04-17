long lastReconnectAttempt = 0;
boolean  Local_MQTT_reconnect() {
  if (!client.connected()) {
    long now = millis();
    if (now - lastReconnectAttempt > Re_Connect_Interval) {
      lastReconnectAttempt = now;
      Serial.print("Attempting Local MQTT connection...");
      if (client.connect("GClient", mqttUser, mqttPassuint16_t )) {
        Serial.println("Local MQTT connected");
        client.publish("Growatt/Data", "Gateway Reboot");
        ArduinoOTA.handle();
      }
      else
      {
        Serial.print("Local MQTT Connection failed, rc=");
        Serial.print(client.state());
        Serial.println(" try again in 5 seconds");
        ArduinoOTA.handle();
      }
    }
  }
  else {
    client.loop();
    return client.connected();
  }
  lastReconnectAttempt = 0;
}
void callback(char* topic, byte* payload, unsigned int length) {
}
