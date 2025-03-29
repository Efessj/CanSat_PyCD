#include <SoftwareSerial.h>
#include <TinyGPS++.h>

static const int gpsTX = 3, gpsRX = 4;
SoftwareSerial gpsSerial(gpsRX, gpsTX);
TinyGPSPlus gps;

float latitud, longitud;

void setup()
{
  Serial.begin(9600);
  gpsSerial.begin(4800);
  //Serial.println("Buscando señal GPS...");
}

void loop()
{
  if (gpsSerial.available() > 0) {
    gps.encode(gpsSerial.read());  // Decodifica los datos recibidos
      
    latitud = gps.location.lat();
    longitud = gps.location.lng();
    }
	
	Serial.print(" Latitud: ");
  Serial.print(latitud, 6);
  Serial.print(" Longitud: ");
  Serial.println(longitud, 6);
  delay(1000);
  
  }
}
