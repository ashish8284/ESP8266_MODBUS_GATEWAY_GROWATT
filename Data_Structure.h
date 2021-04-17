//Modbus Status
int MB_STS = 0;
bool MB_STS_JSON;
//Grid
float GIRD_FREQ; //013
float GRID_VLT; //0014
float GRID_AMP; //0015
float GRID_PWR_VA_H; //0016-17 Watt
float GRID_PWR_VA_L; //0016-17 Watt
uint16_t GRID_FLT; //90

//PV Cell
float PV_VLT; //03
float PV_AMP; //04
float PV_WATT_H; //05-06
float PV_WATT_L; //05-06
float PV_IN_PVR_W_H; //01-02
float PV_IN_PVR_W_L; //01-02

//inverter
uint16_t STATE;//00
uint16_t FAUTL; //40 & *1
uint16_t WARNING; //64
float IN_TMP; //41
float TEMP;//32
float  INV_OUT_PWR_W_H; //11-12
float  INV_OUT_PWR_W_L; //11-12

//ENERGY
float ENR_TODAY_H; //26-27
float ENR_TODAY_L; //26-27
float ENR_TOT_H;  //28-29
float ENR_TOT_L;  //28-29
float PV_ENER_TODY_H; //48-48
float PV_ENER_TODY_L; //48-48
float PV_ENER_TOT_H; //50-51
float PV_ENER_TOT_L; //50-51

uint16_t MB_BF1[7];
uint16_t MB_BF2[7];
uint16_t MB_BF3[7];
uint16_t MB_BF4[2];
uint16_t MB_BF5[4];
uint16_t MB_BF6[1];
uint16_t MB_BF7[1];
