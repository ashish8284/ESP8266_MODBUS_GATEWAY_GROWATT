//TX & RX Pin assignment
int Rx = 13; 
int Tx = 12;
int DE_RE = 4; // For MAX485 chip

//Wifi router Credentials
const char* ssid             = ""; //Enter Wifi router SSID
const char* passuint16_t     = ""; //Enter WIFI router password

//MQTT Server Setting
bool MQTT_Enable = 1; //Set 0 if MQTT function not required
int Re_Connect_Interval = 60000; //Retrial interval in case MQTT server connection is not connected
const char* mqtt_server      = ""; //Set ip address of MQTT sserver i.e. :-  "192.168.1.1"
const char* mqttUser         = ""; //MQTT server user name. Keep blank if no user name is assigned to MQTT server.
const char* mqttPassuint16_t = ""; //MQTT server password. keep blank if password is not set in MQTT server.
const char* mqttClientid     = "ABCD"; //Unique Client id. In case multiple device in same network then this required to be different for each ESP.
unsigned long  Window_Time = 5000; //Data posting Time interval for MQTT. 

//Settings for AP Mode
const char* AP_ssid             = "Techno_Growatt"; //SSID for AP mode. ESP create WIFI network wiht SSID
const char* AP_passuint16_t     = "12345678"; //Password for AP mode. User can connect with ESP using this password.
IPAddress AP_IP(192, 168, 11, 4); //IP address of ESP for AP mode operation. We can use this IP to access webpage. 
IPAddress AP_gateway(192, 168, 11, 1); //Gateway of ESP for AP mode.
IPAddress AP_subnet(255, 255, 255, 0); //Subnet of ESP for AP mode.

//Adaftruit.io credential
#define AIO_USERNAME    "" //User name of Adafruit.io account.
#define AIO_KEY         "" //AIO Key of Adafruit.io account

//Adafruit Setting
bool Ada_MQTT_Enable = 1; //Set this to enable data posting on Adafruit.io
unsigned long AdaMqttDly_Window = (1000 *60)* 1; //Data posting Time interval for Adafruit server data posting. 

//Modbus Slave address
byte Start_ID = 1; //Modbus Slave Address of Inverter.
byte End_Id = 1; //Number of inverters in single loop(currently multiple inverter data posting is not implemented).
