#include <Energia.h>

#define SENSOR_PIN1    A1   // Soil moisture sensor analog input pin (AOUT)
#define SENSOR_PIN2    A2   // Soil moisture sensor analog input pin (AOUT)
#define SENSOR_PIN3    A3   // Soil moisture sensor analog input pin (AOUT)

#define RELAY_PIN1    0    // Relay control pin 1 (for pump, connected to PB0)
#define RELAY_PIN2    1    // Relay control pin 2 (for pump, connected to PB1)

int moistureThreshold = 350;  // Threshold moisture level for watering (tune as needed)

void setup() {
  // Set up the relay pins as outputs
  pinMode(RELAY_PIN1, OUTPUT);
  pinMode(RELAY_PIN2, OUTPUT);

  // Initialize serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Read the soil moisture level (analog reading from A1)
  int moistureLevel1 = analogRead(SENSOR_PIN1);
  int moistureLevel2 = analogRead(SENSOR_PIN2);
  int moistureLevel3 = analogRead(SENSOR_PIN3);
  
  // Print the moisture level to the Serial Monitor for debugging
  Serial.print("Soil Moisture1: ");
  Serial.println(moistureLevel1);
  
  Serial.print("Soil Moisture2: ");
  Serial.println(moistureLevel2);

  Serial.print("Soil Moisture3: ");
  Serial.println(moistureLevel3);

  Serial.println();

  // If moisture is below the threshold, turn on the pump (activate the relay)
  if (moistureLevel1 < moistureThreshold || moistureLevel2 < moistureThreshold || moistureLevel3 < moistureThreshold) {
    digitalWrite(RELAY_PIN1, HIGH);  // Turn on the relay (activate the pump)
    digitalWrite(RELAY_PIN2, HIGH);  // If using both relay channels
  } else {
    digitalWrite(RELAY_PIN1, LOW);   // Turn off the relay (deactivate the pump)
    digitalWrite(RELAY_PIN2, LOW);   // If using both relay channels
  }

  // Delay for a second before the next reading
  delay(10000);
}
