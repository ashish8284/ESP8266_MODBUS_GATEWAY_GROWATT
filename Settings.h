//TX & RX Pin assignment
int Rx = 13; 
int Tx = 12;
int DE_RE = 4; // For MAX485 chip

//Wifi router Credentials
const char* ssid             = "Ashish Patel02";
const char* passuint16_t     = "Aradhya$146";

//MQTT Server Setting
bool MQTT_Enable = 1;
int Re_Connect_Interval = 60000;
const char* mqtt_server      = "192.168.1.100";
const char* mqttUser         = "openhabian";
const char* mqttPassuint16_t = "openhabian";
const char* mqttClientid     = "ABCD";
unsigned long  Window_Time = 5000;

//Settings for AP Mode
const char* AP_ssid             = "Techno_Growatt";
const char* AP_passuint16_t     = "12345678";
IPAddress AP_IP(192, 168, 11, 4);
IPAddress AP_gateway(192, 168, 11, 1);
IPAddress AP_subnet(255, 255, 255, 0);

//Adaftruit.io credential
#define AIO_USERNAME    "Ashish_82848284"
#define AIO_KEY         "82184014511d457ca7c0775480419bb2"

//Adafruit Setting
bool Ada_MQTT_Enable = 1;
unsigned long AdaMqttDly_Window = (1000 *60)* 1;

//Modbus Slave address
byte Start_ID = 1;
byte End_Id = 1;
