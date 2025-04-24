#include <Energia.h>

#define SENSOR_PIN1      A0     // PE3
#define RELAY_PIN1       PD_0   // PD0

#define SENSOR_PIN2      A1     // PD7
#define RELAY_PIN2       PB_2   // PB2

int moistureThreshold = 500; // Adjust based on your sensor calibration

void setup() {
  pinMode(SENSOR_PIN1, INPUT);
  pinMode(RELAY_PIN1, OUTPUT);
  pinMode(SENSOR_PIN2, INPUT);
  pinMode(RELAY_PIN2, OUTPUT);
  
  // Turn relay off initially
  digitalWrite(RELAY_PIN1, HIGH); // HIGH = OFF if active LOW relay
  digitalWrite(RELAY_PIN2, HIGH); // HIGH = OFF if active LOW relay


  Serial.begin(9600);
}

void loop() {
  int sensorValue1 = analogRead(SENSOR_PIN1);
  int sensorValue2 = analogRead(SENSOR_PIN2);

  Serial.print("Soil moisture 1: ");
  Serial.println(sensorValue1);
  
  Serial.println();

  Serial.print("Soil moisture 2: ");
  Serial.println(sensorValue2);

  if (sensorValue1 < moistureThreshold) {
    // Soil is dry, activate pump
    digitalWrite(RELAY_PIN1, LOW);  // LOW = ON for active LOW relay
    Serial.println("Pump ON");
  } else {
    // Soil is wet, turn pump off
    digitalWrite(RELAY_PIN1, HIGH); // OFF
    Serial.println("Pump OFF");
  }

  Serial.println();

  if (sensorValue2 < moistureThreshold) {
    // Soil is dry, activate pump
    digitalWrite(RELAY_PIN2, LOW);  // LOW = ON for active LOW relay
    Serial.println("Pump ON");
  } else {
    // Soil is wet, turn pump off
    digitalWrite(RELAY_PIN2, HIGH); // OFF
    Serial.println("Pump OFF");
  }

  Serial.println();

  delay(2000); // Wait 2 seconds between readings
}
