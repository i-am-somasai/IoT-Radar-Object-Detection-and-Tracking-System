#include <WiFi.h>      // Required for WiFi functionality on ESP32
#include <esp_now.h>   // Required for ESP-NOW communication

// Define a structure to receive data from the transmitter
typedef struct struct_message {
  int angle;      // Angle of the radar or gun servo (in degrees)
  int distance;   // Measured distance from ultrasonic sensor (in cm)
} struct_message;

struct_message incomingData; // Variable to store received data

// Callback function that gets triggered automatically when data is received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingDataBytes, int len) {
  // Copy incoming byte data into the structured format
  memcpy(&incomingData, incomingDataBytes, sizeof(incomingData));

  // Display received data in the Serial Monitor
  Serial.print("Receiver Received -> Angle: ");
  Serial.print(incomingData.angle);
  Serial.print("°, Distance: ");
  Serial.print(incomingData.distance);
  Serial.println(" cm");
}

void setup() {
  Serial.begin(115200); // Initialize Serial Monitor at 115200 baud

  // Configure ESP32 as a Wi-Fi Station (not connected to any router)
  WiFi.mode(WIFI_STA);
  WiFi.disconnect(); // Ensures it doesn't auto-connect to any Wi-Fi network

  // Initialize ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return; // Stop execution if ESP-NOW fails to initialize
  }

  // Register the receive callback function
  esp_now_register_recv_cb(OnDataRecv);

  Serial.println("ESP-NOW Receiver Ready"); // Indicate successful setup
}

void loop() {
  // No repeated actions needed here.
  // Data is received and handled via the OnDataRecv callback.
}
