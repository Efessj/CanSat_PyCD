#include <SoftwareSerial.h>

#define rxPin 10
#define txPin 11
#define vccPin 13

// Set up a new SoftwareSerial object
SoftwareSerial mySerial =  SoftwareSerial(rxPin, txPin);

void setup()  {
    // Define pin modes for TX and RX
    pinMode(rxPin, INPUT);
    pinMode(txPin, OUTPUT);
    pinMode(vccPin, OUTPUT);
    digitalWrite(vccPin, HIGH);

    // Set the baud rate for the SoftwareSerial object
    mySerial.begin(9600);
    Serial.begin(9600);
}

void loop() {
    while (mySerial.available() > 0) {
        Serial.print(char(mySerial.read()));
    }
    Serial.print("");
}