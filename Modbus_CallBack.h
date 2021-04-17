bool cbWrite(Modbus::ResultCode event, uint16_t transactionId, void* data) {
#ifdef ESP8266
  //Serial.printf_P("Request result: 0x%02X, Mem: %f\n", event, ESP.getFreeHeap());
  //Serial.println(event);
  MB_STS = event;
  ArduinoOTA.handle();
#elif ESP32
  //Serial.printf_P("Request result: 0x%02X, Mem: %f\n", event, ESP.getFreeHeap());
#else
  //Serial.print("Request result: 0x");
  //Serial.print(event, HEX);
#endif
  return true;
}
