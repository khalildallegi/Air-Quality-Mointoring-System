
#include <DHT.h>  // Include the DHT sensor library

#define DHT_PIN 13  // Pin connected to the DHT11 sensor
#define DHT_TYPE DHT11  // DHT type (DHT11 in this case)

#define MQ2_PIN 12   // Pin connected to MQ2 sensor (AO)
#define MQ4_PIN 14   // Pin connected to MQ4 sensor (AO)
#define MQ6_PIN 27   // Pin connected to MQ6 sensor (AO)
#define MQ7_PIN 26   // Pin connected to MQ7 sensor (AO)
#define MQ9_PIN 25   // Pin connected to MQ9 sensor (AO)
#define MQ135_PIN 33 // Pin connected to MQ135 sensor (AO)

DHT dht(DHT_PIN, DHT_TYPE);  // Initialize the DHT11 sensor

// Updated threshold calibration based on typical gas concentrations
int mq2_threshold = 400;   // Threshold for MQ2 (Smoke, LPG, Methane, Alcohol, CO)
int mq4_threshold = 500;   // Threshold for MQ4 (Methane, Natural Gas)
int mq6_threshold = 1000;  // Threshold for MQ6 (LPG, Butane, Propane)
int mq7_threshold = 200;   // Threshold for MQ7 (Carbon Monoxide)
int mq9_threshold = 150;   // Threshold for MQ9 (CO, Methane, LPG, Carbon Monoxide)
int mq135_threshold = 400; // Threshold for MQ135 (Ammonia, Benzene, Alcohol, Smoke, CO2)


#define mq2led 15
#define mq4led 2
#define mq6led 4
#define mq7led 5
#define mq9led 18
#define mq135led 19
void setup() {
  // Start serial communication for debugging
  Serial.begin(115200);

  // Start DHT sensor
  dht.begin();

  // Set MQ pins as input (optional, default is input)
  pinMode(MQ2_PIN, INPUT);
  pinMode(MQ4_PIN, INPUT);
  pinMode(MQ6_PIN, INPUT);
  pinMode(MQ7_PIN, INPUT);
  pinMode(MQ9_PIN, INPUT);
  pinMode(MQ135_PIN, INPUT);

   pinMode(mq2led,OUTPUT);
   pinMode(mq4led,OUTPUT);
   pinMode(mq6led,OUTPUT);
   pinMode(mq7led,OUTPUT);
   pinMode(mq9led,OUTPUT);
   pinMode(mq135led,OUTPUT);
}

void loop() {
  // Read temperature and humidity from DHT11 sensor
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Check if any readings failed
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Read analog values from MQ sensors (raw values)
  int mq2_value = analogRead(MQ2_PIN);
  int mq4_value = analogRead(MQ4_PIN);
  int mq6_value = analogRead(MQ6_PIN);
  int mq7_value = analogRead(MQ7_PIN);
  int mq9_value = analogRead(MQ9_PIN);
  int mq135_value = analogRead(MQ135_PIN);

  // Print the sensor data to the Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C | Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  // Print the analog readings from MQ sensors
  Serial.print("MQ2 Sensor Value: ");
  Serial.println(mq2_value);
  
  Serial.print("MQ4 Sensor Value: ");
  Serial.println(mq4_value);
  
  Serial.print("MQ6 Sensor Value: ");
  Serial.println(mq6_value);
  
  Serial.print("MQ7 Sensor Value: ");
  Serial.println(mq7_value);
  
  Serial.print("MQ9 Sensor Value: ");
  Serial.println(mq9_value);
  
  Serial.print("MQ135 Sensor Value: ");
  Serial.println(mq135_value);

  // Add logic to interpret analog values based on a threshold for safety or monitoring
  // Check if the sensor values exceed the threshold for each sensor
  if (mq2_value > mq2_threshold) {
    Serial.println("Warning: High levels of gas detected by MQ2!");
    digitalWrite(mq2led,HIGH);
  }

  if (mq4_value > mq4_threshold) {
    Serial.println("Warning: High levels of gas detected by MQ4!");
      digitalWrite(mq4led,HIGH);
  }

  if (mq6_value > mq6_threshold) {
    Serial.println("Warning: High levels of gas detected by MQ6!");
      digitalWrite(mq6led,HIGH);
  }

  if (mq7_value > mq7_threshold) {
    Serial.println("Warning: High levels of gas detected by MQ7!");
      digitalWrite(mq7led,HIGH);
  }

  if (mq9_value > mq9_threshold) {
    Serial.println("Warning: High levels of gas detected by MQ9!");
      digitalWrite(mq9led,HIGH);
  }

  if (mq135_value > mq135_threshold) {
    Serial.println("Warning: High levels of gas detected by MQ135!");
      digitalWrite(mq135led,HIGH);
  }

  // Add a delay before the next reading
  delay(2000);  // Delay 2 seconds (2000 milliseconds)
}
