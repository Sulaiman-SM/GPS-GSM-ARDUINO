// Author: Sulaiman Al-Mazruii
// This example code hes been worked on with SKG13BL GPS Module (NEO-6M-0-001)
#include <SoftwareSerial.h>
#include <TinyGPS.h>

long lat,lon; // create variable for latitude and longitude object
SoftwareSerial gpsSerial(4, 3); // create gps sensor connection on this format =>> (RX , TX)
TinyGPS gps; // create gps object out of the TinyGPS Library

void setup(){
  Serial.begin(9600); // connect serial
  gpsSerial.begin(9600); // connect gps sensor
}

void loop(){
  // calls getGPS()function
  getGPS();
}

// reads GPS data from the module, specifically latitude and longitude 
// and reconstructs them to be viewed by google maps url and then print
// that to arduino serial
void getGPS(){
  while(gpsSerial.available()){ // check for gps data
   if(gps.encode(gpsSerial.read())){ // encode gps data
    gps.get_position(&lat,&lon); // get latitude and longitude
    String LAT = String(lat);
    String LON = String(lon);
    LAT = LAT.substring(0,2) + "." + LAT.substring(2);
    LON = LON.substring(0,2) + "." + LON.substring(2);
    // display position
    Serial.print("Position: look for position below on google maps");
    Serial.print("https://maps.google.com/?q="+LAT+","+LON+"\n");//Serial.print(LAT);Serial.print(",");Serial.println(LON);
   }
  }
  }
