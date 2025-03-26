//codigo para leer el modulo gps
#include <SoftwareSerial.h>
#include <TinyGPS++.h>

static const int gpsTX = 3, gpsRX = 4;
SoftwareSerial gpsSerial(gpsRX, gpsTX);
TinyGPSPlus gps;



void setup()
{
  Serial.begin(9600);
  gpsSerial.begin(9600);
  Serial.println("Buscando señal GPS...");
}

void loop()
{
  if (gpsSerial.available() > 0) {
    gps.encode(gpsSerial.read());  // Decodifica los datos recibidos

    if (gps.location.isUpdated()) {  // Solo muestra si hay datos nuevos
      Serial.print("Latitud: ");
      Serial.print(gps.location.lat(), 6);
      Serial.print(" | Longitud: ");
      Serial.println(gps.location.lng(), 6);
    }
  }
}
