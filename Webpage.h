String Gateway_Status = "Null" ;
String Inverter_Status = "Null" ;
String Inverter_Temp = "Null" ;
String Energy_Today = "Null";
String Energy_Total = "Null";
String Panel_Volatge = "Null";
String Panel_Amps = "Null";
String Panel_Power = "Null";
String Fault = "Null";
String Warning = "Null";
String CL_IP = "Null";

AsyncWebServer server(80);
AsyncEventSource events("/events");

unsigned long lastTime = 0;
unsigned long timerDelay = 3000;  // send readings timer

String processor(const String& var) {
  if (var == "Gateway_Status") {
    return String(Gateway_Status);
  }
  if (var == "Inverter_Status") {
    return String(Inverter_Status);
  }
  if (var == "Inverter_Temp") {
    return String(Inverter_Temp);
  }
  else if (var == "Energy_Today") {
    return String(Energy_Today);
  }
  else if (var == "Energy_Total") {
    return String(Energy_Total);
  }
  else if (var == "Panel_Volatge") {
    return String(Panel_Volatge);
  }
  else if (var == "Panel_Amps") {
    return String(Panel_Amps);
  }
  else if (var == "Panel_Power") {
    return String(Panel_Power);
  }
  else if (var == "Fault") {
    return String(Fault);
  }
  else if (var == "Warning") {
    return String(Warning);
  }
  else if (var == "CL_IP") {
    return String(CL_IP);
  }
}

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <title>Techno Automation</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.7.2/css/all.css" integrity="sha384-fnmOCqbTlWIlj8LyTjo7mOUStjsKC4pOpQbqyi7RrhN7udi9RwhKkMHpvLbHG9Sr" crossorigin="anonymous">
  <link rel="icon" href="data:,">
  <style>
    html {font-family: Arial; display: inline-block; text-align: center;}
    p {  font-size: 1.5rem;}
    body {  margin: 0;}
    .topnav { overflow: hidden; background-color: #4B1D3F; color: white; font-size:1.5rem; }
    .content { padding: 10px; }
    .card { background-color: white; box-shadow: 2px 2px 12px 1px rgba(140,140,140,.5); }
    .cards { max-width: auto; margin: 0 auto; display: grid; grid-gap: 1rem; grid-template-columns: repeat(auto-fit, minmax(200px, 1fr)); }
    .reading { font-size: 2rem; }
    .card.Gateway_Status { color: #0b7c7b; }
    .card.Inverter_Status { color: #0e7c7b; }
    .card.Inverter_Temp { color: #037c7b; }
    .card.Energy_Today { color: #3fca6b; }
    .card.Energy_Total { color: #d62246; }
    .card.Panel_Volatge { color: ##bb10eb; }
    .card.Panel_Amps { color: ##ba10eb; }
    .card.Panel_Power { color: ##bc10eb; }
    .card.Fault { color: #17bebb; }
    .card.Warning { color: ##bb10eb; }
    .card.CL_IP { color: ##bb10eb; }
  </style>
</head>
<body>
  <div class="topnav">
    <h4>Growatt_Inverter(TA)V1</h4>
  </div>
  <div class="content">
    <div class="cards">
      <div class="card Gateway_Status">
        <h4><i class="fas fa-plug"></i> Gateway_Status</h4><p><span class="reading"><span id="M_S">%Gateway_Status%</span></span></p>
      </div>
      <div class="card Inverter_Status">
        <h4><i class="fas fa-plug"></i> Inverter_Status</h4><p><span class="reading"><span id="M_S">%Inverter_Status%</span></span></p>
      </div>
            <div class="card Inverter_Temp">
        <h4><i class="fas fa-temperature-high"></i> Inverter_Temp</h4><p><span class="reading"><span id="M_S">%Inverter_Temp%</span></span> Deg</p>
      </div>
      <div class="card Energy_Today">
        <h4><i class="fas fa-charging-station"></i> Energy_Today</h4><p><span class="reading"><span id="W_L">%Energy_Today%</span></span> Kwh</p>
      </div>
      <div class="card Energy_Total">
        <h4><i class="fas fa-charging-station"></i> Energy_Total</h4><p><span class="reading"><span id="L_S">%Energy_Total%</span></span> Kwh</p>
      </div>
      <div class="card Panel_Volatge">
        <h4><i class="fas fa-solar-panel"></i> Panel_Volatge</h4><p><span class="reading"><span id="R_H">%Panel_Volatge%</span> </span> Vdc</p>
      </div>
      <div class="card Panel_Amps">
        <h4><i class="fas fa-solar-panel"></i> Panel_Amps</h4><p><span class="reading"><span id="R_H">%Panel_Amps%</span></span> Amp</p>
      </div>
      <div class="card Panel_Power">
        <h4><i class="fas fa-solar-panel"></i> Panel_Power</h4><p><span class="reading"><span id="R_H">%Panel_Power%</span></span> Watt</p>
      </div>
      <div class="card Fault">
        <h4><i class="fa fa-bell"></i> Fault</h4><p><span class="reading"><span id="Fault">%Fault%</span></span></p>
      </div>
      <div class="card Warning">
        <h4><i class="fa fa-warning"></i> Warning</h4><p><span class="reading"><span id="WRN">%Warning%</span></span></p>
      </div>
      <div class="card CL_IP">
        <h4><i class="fa fa-warning"></i> CL_IP</h4><p><span class="reading"><span id="WRN">%CL_IP%</span></span></p>
      </div>
    </div>
  </div>
<script>
if (!!window.EventSource) {
 var source = new EventSource('/events');

 source.addEventListener('open', function(e) {
  console.log("Events Connected");
 }, false);
 source.addEventListener('Fault', function(e) {
  if (e.target.readyState != EventSource.OPEN) {
    console.log("Events Disconnected");
  }
 }, false);

 source.addEventListener('message', function(e) {
  console.log("message", e.data);
 }, false);

 source.addEventListener('Gateway_Status', function(e) {
  console.log("Gateway_Status", e.data);
  document.getElementById("M_S").innerHTML = e.data;
 }, false);

 source.addEventListener('Inverter_Status', function(e) {
  console.log("Inverter_Status", e.data);
  document.getElementById("M_S").innerHTML = e.data;
 }, false);

 source.addEventListener('Inverter_Temp', function(e) {
  console.log("Inverter_Temp", e.data);
  document.getElementById("M_S").innerHTML = e.data;
 }, false);

 source.addEventListener('Energy_Today', function(e) {
  console.log("Energy_Today", e.data);
  document.getElementById("W_L").innerHTML = e.data;
 }, false);

 source.addEventListener('Energy_Total', function(e) {
  console.log("Energy_Total", e.data);
  document.getElementById("L_S").innerHTML = e.data;
 }, false);

  source.addEventListener('Panel_Volatge', function(e) {
  console.log("Panel_Volatge", e.data);
  document.getElementById("R_H").innerHTML = e.data;
 }, false);

  source.addEventListener('Panel_Amps', function(e) {
  console.log("Panel_Amps", e.data);
  document.getElementById("R_H").innerHTML = e.data;
 }, false);

   source.addEventListener('Panel_Power', function(e) {
  console.log("Panel_Power", e.data);
  document.getElementById("R_H").innerHTML = e.data;
 }, false);
 source.addEventListener('Fault', function(e) {
  console.log("Fault", e.data);
  document.getElementById("Fault").innerHTML = e.data;
 }, false);

  source.addEventListener('Warning', function(e) {
  console.log("Warning", e.data);
  document.getElementById("WRN").innerHTML = e.data;
 }, false);

  source.addEventListener('CL_IP', function(e) {
  console.log("CL_IP", e.data);
  document.getElementById("CL_IP").innerHTML = e.data;
 }, false);

}
</script>
</body>
</html>)rawliteral";

void Webpabe_Update() {
  events.send("ping", NULL, millis());
  events.send(String(Gateway_Status).c_str(), "Inverter_Status", millis());
  events.send(String(Inverter_Status).c_str(), "Inverter_Status", millis());
  events.send(String(Inverter_Temp).c_str(), "Inverter_Temp", millis());
  events.send(String(Energy_Today).c_str(), "Energy_Today", millis());
  events.send(String(Energy_Total).c_str(), "Energy_Total", millis());
  events.send(String(Panel_Volatge).c_str(), "Panel_Volatge", millis());
  events.send(String(Panel_Amps).c_str(), "Panel_Amps", millis());
  events.send(String(Panel_Power).c_str(), "Panel_Power", millis());
  events.send(String(Warning).c_str(), "Warning", millis());
  events.send(String(Fault).c_str(), "Fault", millis());
  CL_IP = WiFi.localIP().toString();
  events.send(String(CL_IP).c_str(), "CL_IP", millis());
  ArduinoOTA.handle();
}
