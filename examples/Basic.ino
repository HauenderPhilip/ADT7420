#include <Wire.h>
#include <ADT7420.h>

ADT7420 sensor(&Wire);
double temp;

void setup() {
  Serial.begin(9600);
  sensor.connect();
  Serial.println("Starting....");
}

void loop() {
  temp = sensor.GetTemp();
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" deg C");
  delay(1000);
}
