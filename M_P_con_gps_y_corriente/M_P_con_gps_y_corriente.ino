#include "DFRobot_BMP280.h"
#include "Wire.h"
#include <SoftwareSerial.h>
#include <TinyGPS++.h>

typedef DFRobot_BMP280_IIC    BMP;    // ******** use abbreviations instead of full names ********

BMP   bmp(&Wire, BMP::eSdoLow);

#define SEA_LEVEL_PRESSURE    1015.0f   // sea level pressure

#define vcc1 5
#define vcc2 7
#define vcc3 9
#define gnd1 6
#define gnd2 8

unsigned long tiempo = 0;
unsigned long paquete = 0;

float Sensibilidad=0.066;

static const int gpsTX = 3, gpsRX = 4;
SoftwareSerial gpsSerial(gpsRX, gpsTX);
TinyGPSPlus gps;

float latitud, longitud;

// show last sensor operate status
void printLastOperateStatus(BMP::eStatus_t eStatus)
{
  switch(eStatus) {
  case BMP::eStatusOK:    Serial.println("everything ok"); break;
  case BMP::eStatusErr:   Serial.println("unknow error"); break;
  case BMP::eStatusErrDeviceNotDetected:    Serial.println("device not detected"); break;
  case BMP::eStatusErrParameter:    Serial.println("parameter error"); break;
  default: Serial.println("unknow status"); break;
  }
}

void setup()
{
  gpsSerial.begin(9600);
  Serial.begin(9600);
  bmp.reset();
  Serial.println("bmp config test");
  //while(bmp.begin() != BMP::eStatusOK) {
  //  Serial.println("bmp begin faild");
  //  printLastOperateStatus(bmp.lastOperateStatus);
  //  delay(2000);
  //}
  Serial.println("bmp begin success");

  bmp.setConfigFilter(BMP::eConfigFilter_off);        // set config filter
  bmp.setConfigTStandby(BMP::eConfigTStandby_125);    // set standby time
  bmp.setCtrlMeasSamplingTemp(BMP::eSampling_X8);     // set temperature over sampling
  bmp.setCtrlMeasSamplingPress(BMP::eSampling_X8);    // set pressure over sampling
  bmp.setCtrlMeasMode(BMP::eCtrlMeasModeNormal);     // set control measurement mode to make these settings effective

  pinMode(vcc1, OUTPUT);
  pinMode(vcc2, OUTPUT);
  pinMode(vcc3, OUTPUT);
  pinMode(gnd1, INPUT);
  pinMode(gnd2, INPUT);

  digitalWrite(vcc1, HIGH);
  digitalWrite(vcc2, HIGH);
  digitalWrite(vcc3, HIGH);
  digitalWrite(gnd1, LOW);
  digitalWrite(gnd2, LOW);

  delay(100);
}


void loop() {
  uint32_t    presio = bmp.getPressure();
  float temp = bmp.getTemperature();
  float voltajeSensor= analogRead(A0)*(5.0 / 1023.0); //lectura del sensor   
  float I=(voltajeSensor-2.5)/Sensibilidad; //Ecuación  para obtener la corriente

  
  gps.encode(gpsSerial.read());  // Decodifica los datos recibidos
      
  latitud = gps.location.lat();
  longitud = gps.location.lng();
  

  if (tiempo + 1000 < millis()){
    Serial.print(paquete);
    Serial.print(" presio: ");
    Serial.print(presio);
    Serial.print(" temperatura: ");
    Serial.print(temp);
    Serial.print(" corriente: ");
    Serial.print(I,3);
    Serial.print(" latitud: ");
    Serial.print(latitud, 6);
    Serial.print(" longitud: ");
    Serial.println(longitud, 6);
    paquete ++;
    tiempo = millis();
  }
}
