# WMM_Tinier


WMM_Tinier - Arduino library for calculating geomagnetic variation

  Version 1.0.1 - October 15, 2022

  By David Armstrong<br>
  https://github.com/DavidArmstrong/WMM_Tinier<br>
  See MIT LICENSE.md file


This Arduino library is a small embedded C99 implementation of the World Magnetic Model published by NOAA for calculating the magnetic field declination, or variation, at any point on the world's surface for a given date in the years 2020 to 2025.  Its core coding is copied, with permission, from https://github.com/miniwinwm/WMM_Tiny and it is recommended that internal code details be obtained at that URL.

Geomagnetic variation is needed to account for the difference between the orientation of the earth's magnetic field in relation to true North.  This value varies slowly over time according to the observer's position on the earth.  Therefore, the value of variation is essential to know when using digital compass sensors so as to be able to determine a true heading.

Note: NOAA provides the latest coefficients file at this URL: https://www.ngdc.noaa.gov/geomag/WMM/soft.shtml

It is recommended that the user run the example sketch on the target Arduino board, as it shows how to use the library functions.

Notes:
  1) The library reduces memory usage by using a compressed coefficients file.  Refer to https://github.com/miniwinwm/WMM_Tiny for more details.
  2) Even with the compression used, the program is still much too large for a standard Arduino Uno board, with only 2K of RAM.  The target Arduino board must have at least 8K of RAM available.  Many of the newer processor boards can meet this requirement, such as the SAMD boards, ESP32, Teensy, and so forth.


======================================

Basic Library Functions:<br>
--  Specifics are explained with each function.

boolean begin()<br>
  This initializes the library.

float decimalDegrees(int degrees, int minutes, float seconds)<br>
  Convert a number that is specified in degrees, minutes, and seconds to decimal degrees.

void printDegMinSecs(float n)<br>
  Prints a float number of degrees to Serial in the form {deg}:{min}:{seconds}. The seconds may include a fractional part of two digits. If needed, a minus sign is printed in front of the number.  The numbers printed are not further formatted in any way.

float magneticDeclination(float Latitude, float Longitude, uint8_t year, uint8_t month, uint8_t day)<br>
  Sets the Longitude, Latitude, and date for any position on the earth that will be used to calculate the magnetic declination.  Coordinates are in degrees, and can range from -90. to +90. for Latitude, and -180. to +180. for Longitude.  The Date must be input with a 2-digit year, representing a date between 2020.0 to 2025.0, inclusive.  (So a year of 2021 must be entered as just 21.) The geomagnetic declination is returned as a float representing degrees. A positive value means that a compass will point East of North by that amount in degrees.
