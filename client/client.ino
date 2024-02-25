#include <WiFi.h>
#include <Arduino.h>

const int potPin = 34;

const char ssid[] = "TP-Link_B922";
const char password[] = "13600167";

int potValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  // Potentiometer
  // analogReadResolution(12);
  pinMode(potPin, INPUT);

  // TCP Connection Setup
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

WiFiClient client;
const char* host = "192.168.0.106";
const int port = 1333;

char command[1];

void loop() {
  potValue = analogRead(potPin);
  Serial.println(potValue);

  // Convert output value to command
  if (potValue > 2048) { 
    command[0] = 'L'; // Turn left
  } else {
    command[0] = 'R'; // Turn right
  }

  // put your main code here, to run repeatedly:
  if (!client.connected()) {
    Serial.println("Connecting to server...");
    if (client.connect(host, port)) {
      Serial.println("Connected to server");
      // Send data to server
      client.println("Hello from ESP32");
    } else {
      Serial.println("Connection failed");
      delay(5000);
    }
  }

  client.print(command);

  delay(500);
}
