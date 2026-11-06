#define SOIL_PIN 34
#define RAIN_PIN 35
#define PH_PIN 32

#define DHT_PIN 4
#define DHT_TYPE DHT11

#include <DHT.h>

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();

  Serial.println("Smart Farming Assistant");
}

void loop() {
  int soilValue = analogRead(SOIL_PIN);
  int rainValue = analogRead(RAIN_PIN);
  int phValue = analogRead(PH_PIN);

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  Serial.println("----- Farm Data -----");

  Serial.print("Soil Moisture Raw: ");
  Serial.println(soilValue);

  Serial.print("Rain Sensor Raw: ");
  Serial.println(rainValue);

  Serial.print("pH Sensor Raw: ");
  Serial.println(phValue);

  if (!isnan(temperature) && !isnan(humidity)) {
    Serial.print("Temperature: ");
    Serial.println(temperature);

    Serial.print("Humidity: ");
    Serial.println(humidity);
  }

  delay(2000);
}