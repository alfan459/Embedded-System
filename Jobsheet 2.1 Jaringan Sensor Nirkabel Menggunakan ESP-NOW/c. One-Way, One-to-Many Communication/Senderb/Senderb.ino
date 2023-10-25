#include <WiFi.h>
#include <esp_now.h>

// Definisikan alamat MAC dari tiga board penerima
uint8_t broadcastAddress1[] = {0x12, 0x34, 0x56, 0x78, 0x90, 0xAB}; // Alamat MAC Receiver 1
uint8_t broadcastAddress2[] = {0xAB, 0xCD, 0xEF, 0x12, 0x34, 0x56}; // Alamat MAC Receiver 2
uint8_t broadcastAddress3[] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xCD}; // Alamat MAC Receiver 3

// Struktur data untuk pesan
struct Message {
  int x;
  int y;
};

Message message1;
Message message2;
Message message3;

void setup() {
  Serial.begin(115200);

  // Inisialisasi ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Tambahkan penerima dengan alamat MAC yang sesuai
  esp_now_add_peer(broadcastAddress1, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
  esp_now_add_peer(broadcastAddress2, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
  esp_now_add_peer(broadcastAddress3, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);

  // Buat data dummy untuk masing-masing pesan
  message1.x = random(100);
  message1.y = random(100);
  message2.x = random(100);
  message2.y = random(100);
  message3.x = random(100);
  message3.y = random(100);
}

void loop() {
  // Kirim pesan ke penerima 1
  esp_err_t result = esp_now_send(broadcastAddress1, (uint8_t *)&message1, sizeof(message1));
  if (result == ESP_OK) {
    Serial.println("Pesan ke Receiver 1 terkirim");
  } else {
    Serial.println("Gagal mengirim pesan ke Receiver 1");
  }

  // Kirim pesan ke penerima 2
  result = esp_now_send(broadcastAddress2, (uint8_t *)&message2, sizeof(message2));
  if (result == ESP_OK) {
    Serial.println("Pesan ke Receiver 2 terkirim");
  } else {
    Serial.println("Gagal mengirim pesan ke Receiver 2");
  }

  // Kirim pesan ke penerima 3
  result = esp_now_send(broadcastAddress3, (uint8_t *)&message3, sizeof(message3));
  if (result == ESP_OK) {
    Serial.println("Pesan ke Receiver 3 terkirim");
  } else {
    Serial.println("Gagal mengirim pesan ke Receiver 3");
  }

  delay(5000); // Kirim pesan setiap 5 detik
}
