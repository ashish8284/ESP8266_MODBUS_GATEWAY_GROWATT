uint16_t CALL_STP = 0;
unsigned long Post_window = 0;
void ModbusCall() {
  if (CALL_STP == 0) {
    if (!mb.slave()) {
      mb.readIreg(1, 0, MB_BF1, 7, cbWrite);
      for (uint16_t x = 0; x < 7 ; x++) {
      }
      CALL_STP = 1;
      ArduinoOTA.handle();
    }
    STATE = MB_BF1[0];
    //PV_IN_PVR_W_H = MB_BF1[1] / 10.0;
    PV_IN_PVR_W_L = MB_BF1[2] / 10.0;
    PV_VLT = MB_BF1[3] / 10.0;
    PV_AMP = MB_BF1[4] / 10.0;
    //PV_WATT_H = MB_BF1[5] / 10.0;
    PV_WATT_L = MB_BF1[6] / 10.0;
  }
  if (CALL_STP == 1) {
    if (!mb.slave()) {
      mb.readIreg(1, 11, MB_BF2, 7, cbWrite);
      for (uint16_t x = 0; x < 7; x++) {
      }
      CALL_STP = 2;
      ArduinoOTA.handle();
    }
    //INV_OUT_PWR_W_H = MB_BF1[0] / 10.0;
    INV_OUT_PWR_W_L = MB_BF1[1] / 10.0;
    GIRD_FREQ = MB_BF2[2] / 100.0;
    GRID_VLT = MB_BF2[3] / 10.0;
    GRID_AMP = MB_BF2[4] / 10.0;
    //GRID_PWR_VA_H = MB_BF2[5] / 10.0;
    GRID_PWR_VA_L = MB_BF2[6] / 10.0;
    //mb.task();
    //yield();
  }
  if (CALL_STP == 2) {
    if (!mb.slave()) {
      mb.readIreg(1, 26, MB_BF3, 7, cbWrite);
      for (uint16_t x = 0; x < 7; x++) {
      }
      CALL_STP = 3;
      ArduinoOTA.handle();
    }
    //ENR_TODAY_H = MB_BF3[0] / 10.0;
    ENR_TODAY_L = MB_BF3[1] / 10.0;
    //ENR_TOT_H = MB_BF3[2] / 10.0;
    ENR_TOT_L = MB_BF3[3] / 10.0;
    TEMP = MB_BF3[6] / 10.0;
  }
  if (CALL_STP == 3) {
    if (!mb.slave()) {
      mb.readIreg(1, 40, MB_BF4, 2, cbWrite);
      for (uint16_t x = 0; x < 2; x++) {
      }
      CALL_STP = 4;
      ArduinoOTA.handle();
    }
    FAUTL = MB_BF4[0];
    IN_TMP = MB_BF4[1] / 10.0;
  }
  if (CALL_STP == 4) {
    if (!mb.slave()) {
      mb.readIreg(1, 48, MB_BF5, 4, cbWrite);
      for (uint16_t x = 0; x < 4; x++) {
      }
      CALL_STP = 5;
      ArduinoOTA.handle();
    }
    //PV_ENER_TODY_H = MB_BF5[0] / 10.0;
    PV_ENER_TODY_L = MB_BF5[1] / 10.0;
    //PV_ENER_TOT_H = MB_BF5[2] / 10.0;
    PV_ENER_TOT_L = MB_BF5[3] / 10.0;
    //Serial.print(MB_BF5[0]);Serial.print(MB_BF5[1]);Serial.print(MB_BF5[2]);Serial.print(MB_BF5[3]);Serial.println();
  }
  if (CALL_STP == 5) {
    if (!mb.slave()) {
      mb.readIreg(1, 64, MB_BF6, 1, cbWrite);
      for (uint16_t x = 0; x < 1; x++) {
      }
      CALL_STP = 6;
      ArduinoOTA.handle();
    }
    WARNING = MB_BF6[0];
  }
  if (CALL_STP == 6) {
    if (!mb.slave()) {
      mb.readIreg(1, 90, MB_BF7, 1, cbWrite);
      //Serial.print("Seventh:-");
      for (uint16_t x = 0; x < 1; x++) {
      }
      CALL_STP = 0;
      ArduinoOTA.handle();
    }
    GRID_FLT = MB_BF7[0];
  }
  if (millis() - Post_window > Window_Time) {
    JSON_Pack();
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    delay(200);
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    delay(200);
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    delay(200);
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    Post_window += Window_Time;
    ArduinoOTA.handle();
  }
}
