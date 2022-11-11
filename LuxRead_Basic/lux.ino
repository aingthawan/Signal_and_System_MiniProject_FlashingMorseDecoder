#include <BH1750FVI.h>

BH1750FVI LightSensor(BH1750FVI::k_DevModeContLowRes); 

void setup()
{
  Serial.begin(115200);
  LightSensor.begin(); 
}


void loop()
{
  uint16_t lux = LightSensor.GetLightIntensity(); 
  Serial.print("Light: ");
  Serial.print(lux);
  Serial.println(" lux");
  delay(5);
}
