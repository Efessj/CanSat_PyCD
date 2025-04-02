#include <SoftwareSerial.h>
#include <TinyGPS++.h>
SoftwareSerial gpsSerial(4,3);
TinyGPSPlus gps;
float lattitude,longitude;

void setup() {

  gpsSerial.begin(9600);
  Serial.begin(9600);
  
  }

void loop()
{

  gps.encode(gpsSerial.read());
  
  lattitude = (gps.location.lat());
  longitude = (gps.location.lng());
  Serial.print ("lattitude: ");
  Serial.println (lattitude, 6);
  Serial.print ("longitude: ");
  Serial.println (longitude, 6);
  
  delay(1000);

}

