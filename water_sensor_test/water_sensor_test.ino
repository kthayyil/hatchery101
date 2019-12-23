// This test can be used to calibrate the water sensor for use in a tank.
// You'll have to run the code and take a reading to find the appropriate value for SensorMaxima

#define WaterLevelPin A0  // The sensor works by taking an analogue Voltage reading
#define SensorMaxima 566  // this is the max analogue reading (out of 1023)
                          // when the sensor is completely dipped in liquid.
#define heightOffset 0    // This is the distance of sensor from base of tank in mm
#define SensorLength 42   // This is the length of the conducting part of the sensor in mm

void setup() {
  Serial.begin(9600);
}

void loop() {
  float waterVoltage = analogRead(WaterLevelPin);
  Serial.print(waterVoltage); // Raw ADC Voltage Reading. Use to define SensorMaxima
  Serial.print(" | Length (mm): ");
  float waterLevel = heightOffset + (waterVoltage*SensorLength)/SensorMaxima; // Level of water in mm
  Serial.println(waterLevel);
  delay(100);
}
