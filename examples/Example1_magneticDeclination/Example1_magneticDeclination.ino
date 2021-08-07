/* WMM_Tinier Library - Computes geomagnetic declination for date and location
 * David Armstrong
 * Version 1.0.0 - August 6, 2021
 * Example1_magneticDeclination
*/

#include <WMM_Tinier.h>

// Need the following define for SAMD processors
#if defined (ARDUINO_ARCH_SAMD)
#define Serial SerialUSB
#endif

WMM_Tinier myDeclination;

void setup() {
  Serial.begin(9600);
  delay(2000); //SAMD boards may need a long time to init SerialUSB
  Serial.println("WMM_Tinier Arduino IDE Library Example\n");
  
  myDeclination.begin();
  Serial.println("We use a sample Longitude = -100 degrees 30 minutes");
  Serial.println("And a sample Latitude = 40 degrees 20 minutes");
  Serial.println("On date = Sept 9, 2021");
  
  float longitude = myDeclination.decimalDegrees(-100, 30, 0);
  float latitude = myDeclination.decimalDegrees(40, 20, 0);
  uint8_t year = 21;
  uint8_t month = 9;
  uint8_t day = 9;
  Serial.println("The calculated geomagnetic declination is: ");
  Serial.print(myDeclination.magneticDeclination(latitude, longitude, year, month, day));
  Serial.println(" degrees");
}

void loop() {
  while(1); //Freeze
}
