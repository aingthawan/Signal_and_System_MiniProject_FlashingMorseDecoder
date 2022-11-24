#include <BH1750FVI.h>
BH1750FVI LightSensor(BH1750FVI::k_DevModeContLowRes);

int H;
int L;
uint16_t lux;
int high = 1;
int low = 0;
int ambient;
int current_status = low;
int last_status = low;

int falling_start = 0;
int rising_stop;
int falling_stop;
int rising_start;

int rising_interval;
int falling_interval;

int dot_interval = 80;          // dot or dit interval in ms.

int index = 0;
String abc[] = {
  "E","T","I","A","N","M","S","U","R","W",  // INDEX 1 -10
  "D","K","G","O","H","V","F"," ","L"," ",  // INDEX 11 -20
  "P","J","B","X","C","Y","Z","Q"," "," ",  // INDEX 21 -30
  "5","4"," ","3"," "," "," ","2"," "," ",  // INDEX 31 - ...
  " "," "," "," "," ","1","6"," "," "," ",
  " "," "," "," ","7"," "," "," ","8"," ",
  "9","0"
  };

// ===============================================================================

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  LightSensor.begin();
  Serial.println("\n\nM O R S E  C O D E  E N C O D E R");
  Serial.print("STARTING ");
  int sample = 10;
  int i = 0;
  while(i < sample){
      ambient += LightSensor.GetLightIntensity();
      Serial.print(". "); 
      delay(300);
      i += 1;
  }
  ambient = ambient / sample;
  Serial.println(" ");
  Serial.print("ambient lux : ");  
  Serial.println(ambient);  
  Serial.println(". . . . . . . . . . . . . . . ");
  delay(200);
  
  Serial.println(" ");
}

// ===============================================================================


void loop() {
  lux = LightSensor.GetLightIntensity();
  last_status = current_status;
  if(lux > (ambient + 20)){
      current_status = high;      
  }else{
      current_status = low;
  }
  //Serial.println(logic);
  if (last_status != current_status){
         //Rising Edge
         if (last_status == low){
             rising_start = millis();
             falling_stop = millis();
             falling_interval = falling_stop - falling_start;
             //Serial.print("falling interval : ");
             //Serial.println(falling_interval);                          
             if((falling_interval > ((7*dot_interval)-20))){
                 //Serial.print(index);
                 Serial.print(abc[index-1]);
                 index = 0;
                 Serial.println(" ");             
             }
             else if (falling_interval > (dot_interval+20)){
                 //Serial.print(index);
                 Serial.print(abc[index-1]);
                 index = 0; 
                 Serial.print(" ");             
             }
         }else{
         //Falling Edge
             rising_stop = millis();
             falling_start = millis();
             rising_interval = rising_stop - rising_start;
             //Serial.print("rising interval : ");             
             //Serial.println(rising_interval);                       
             if( rising_interval < (dot_interval + 20)){
                 //Serial.print(".");
                 index = (2*index)+1;                 
             }else{
                 //Serial.print("-");
                 index = (2*index)+2;                 
             }             
         }
  }else{
    if((  millis() == ((falling_start) + ((7*dot_interval) + 10))) && (last_status == low)){
      //Serial.print(" END");
      //Serial.print(index);
      Serial.print(abc[index-1]);
      index = 0;
    }else{
       
    }
  }
}
