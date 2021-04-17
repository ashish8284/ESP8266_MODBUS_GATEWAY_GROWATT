void setup_wifi() {
  WiFi.softAPdisconnect();
  delay(1000);
  WiFi.mode(WIFI_AP_STA);
  //Creating WIFI AP
  WiFi.softAPConfig(AP_IP, AP_gateway, AP_subnet);
  WiFi.softAP(AP_ssid, AP_passuint16_t);
  Serial.print("WIFI AP started with IP:- ");
  Serial.println(AP_IP);
  delay(1000);

  //Connecting WIFI_Router_AS_Client
  Serial.println();
  Serial.print("Connecting to Router :- ");
  Serial.println(ssid);
  WiFi.begin(ssid, passuint16_t);
  int timeout = 0;
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    delay(100);
    timeout = timeout + 1;
    if (timeout >= 120) {
      Serial.println("Connection not establised");
      return;
    }
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
