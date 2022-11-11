## Reference Materials

### Datasheet
[Digital 16bit Serial Output Type Ambient Light Sensor IC BH1750FVI ](https://www.mouser.com/datasheet/2/348/bh1750fvi-e-186247.pdf)

- Working Mode Reference

![image](https://user-images.githubusercontent.com/109336369/201388050-01c5c824-ece5-49e5-b2b9-4a64f17e2ba1.png)

- Lux Calculation Example

![image](https://user-images.githubusercontent.com/109336369/201387900-a761d71e-c57c-4080-a651-899d45f10bc7.png)


* * *

### Basic Arduino Code For BH1750 Light Intensity Sensor

in lux.ino

[>>> Code Reference](https://www.allnewstep.com/article/347/104-arduino-gy-30-%E0%B8%AA%E0%B8%AD%E0%B8%99%E0%B8%A7%E0%B8%B4%E0%B8%98%E0%B8%B5%E0%B9%83%E0%B8%8A%E0%B9%89%E0%B8%87%E0%B8%B2%E0%B8%99%E0%B9%80%E0%B8%8B%E0%B8%99%E0%B9%80%E0%B8%8B%E0%B8%AD%E0%B8%A3%E0%B9%8C%E0%B8%84%E0%B8%A7%E0%B8%B2%E0%B8%A1%E0%B9%80%E0%B8%82%E0%B9%89%E0%B8%A1%E0%B9%81%E0%B8%AA%E0%B8%87-gy-30-bh1750fvi-gy-30)

* * *

### Sensor Working Principle Reference

From Arduino library of the sensor itself ( BH1750.cpp )

```
uint16_t BH1750FVI::GetLightIntensity(void)
{
  uint16_t Value = 0;

  Wire.requestFrom(m_DeviceAddress, 2);
  Value = Wire.read();
  Value <<= 8;
  Value |= Wire.read();

  return Value / 1.2;
}
```

[>>> BH1750 Arduino Library Repo. Reference](https://github.com/claws/BH1750)
