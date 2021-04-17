char msg[500];
void JSON_Pack() {
  const size_t capacity = 4 * JSON_OBJECT_SIZE(4) + JSON_OBJECT_SIZE(5);
  if (MB_STS == 228) MB_STS_JSON = 0;
  else MB_STS_JSON = 1;
  DynamicJsonDocument doc(capacity);
  doc["MB_STS"] = MB_STS_JSON;
  JsonObject Grid = doc.createNestedObject("Grid");
  Grid["Frq"] = GIRD_FREQ;
  Grid["Amp"] = GRID_AMP;
  Grid["Vlt"] = GRID_VLT;
  Grid["OPwr"] = GRID_PWR_VA_L;

  JsonObject PV = doc.createNestedObject("PV");
  PV["Amp"] = PV_AMP;
  PV["Volt"] = PV_VLT;
  PV["OPwerTot"] = PV_WATT_L;

  JsonObject Inv = doc.createNestedObject("Inv");
  Inv["Sts"] = STATE;
  Inv["Flt"] = FAUTL;
  Inv["Wrn"] = WARNING;
  Inv["Tmp"] = IN_TMP;
  Inv["Tmp1"] = TEMP;

  JsonObject Energy = doc.createNestedObject("Energy");
  Energy["PV_Tod"] = PV_ENER_TODY_L;
  Energy["Inv_Tod"] = ENR_TODAY_L;
  Energy["PV_Tot"] = PV_ENER_TOT_L ;
  Energy["Inv_Tot"] = ENR_TOT_L;
  serializeJson(doc, Serial);
  serializeJson(doc, msg);
  Serial.println();
  client.publish("Growatt/Data/Json", msg);
  
  Gateway_Status = String(MB_STS_JSON);
  Inverter_Status = String(STATE);
  Inverter_Temp = String(TEMP);
  Energy_Today = String(ENR_TODAY_L);
  Energy_Total = String(ENR_TOT_L);
  Panel_Volatge = String(PV_VLT);
  Panel_Amps = String(PV_AMP);
  Panel_Power = String(PV_WATT_L);
  Fault = String(FAUTL);
  Warning = String(WARNING);
}
