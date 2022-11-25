#include <BH1750FVI.h>
BH1750FVI LightSensor(BH1750FVI::k_DevModeContLowRes);



// The setup routine runs once when you press reset:
void setup() {
  // Initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  LightSensor.begin();
}

// The loop routine runs over and over again forever:
void loop() {
  // Write the sinewave points, followed by the terminator "Carriage Return" and "Linefeed".
  uint16_t lux = LightSensor.GetLightIntensity();
  Serial.print(lux);
  Serial.write(13);
  Serial.write(10);
}


// 46
