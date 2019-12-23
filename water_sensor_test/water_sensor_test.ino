#define WaterLevelPin A0 // The sensor works by taking an analogue Voltage reading 
#define SensorLength 42 // This is the length of the conducting part of the sensor in mm 
#define SensorMaxima 566 // this is the max analogue reading (out of 1023) 
// when the sensor is completely dipped in liquid. 
#define heightOffset 0 // This is the distance of sensor from base of tank in mm 
void setup() {
  Serial.begin(9600); 

}

void loop() {
  float waterVoltage = analogRead(WaterLevelPin);
  Serial.print(waterVoltage);
  Serial.print(" | Length (mm): ");
  float waterLevel = heightOffset + (waterVoltage*SensorLength)/SensorMaxima; // Level of water in mm 
  Serial.println(waterLevel);
  delay(100);
}
