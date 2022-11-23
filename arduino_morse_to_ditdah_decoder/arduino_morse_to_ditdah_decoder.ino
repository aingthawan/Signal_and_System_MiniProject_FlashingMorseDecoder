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
int logic;

int rising_interval;
int falling_interval;

int dot_interval = 50;

/*
char decode_tree[] = {
  "E","T","I","A","N","M","S","U","R","W",  // INDEX 1 -10
  "D","K","G","O","H","V","F","","L",""  // INDEX 11 -20
  "P","J","B","X","C","Y","Z","Q","",""  // INDEX 21 -30
  }
*/
// ===============================================================================

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  LightSensor.begin();
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
  logic = 0;
  
  Serial.println(" ");
}

// ===============================================================================


void loop() {
  lux = LightSensor.GetLightIntensity();
  last_status = current_status;
  if(lux > (ambient + 20)){
      current_status = high;      
      logic = 1;
  }else{
      current_status = low;      
      logic = 0;
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
                 Serial.println(" ");             
             }
             else if (falling_interval > (dot_interval+20)){
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
                 Serial.print(".");
             }else{
                 Serial.print("-");
             }
             
         }
  }
}
