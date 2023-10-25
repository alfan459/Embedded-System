// 10 September 2023
// Alfan, Ayum, Rani
// Program Mengecek MAC Address ESP32

// Menambahkan library WiFi
#include "WiFi.h"

void setup() {
  Serial.begin(115200);               // Komunikasi serial diatur pada baudrate 115200
  WiFi.mode(WIFI_MODE_STA);           // Mode wifi diatur pada mode STA
  Serial.println(WiFi.macAddress());  // Menampilkan alamat MAC pada serial monitor
}

void loop() {

}