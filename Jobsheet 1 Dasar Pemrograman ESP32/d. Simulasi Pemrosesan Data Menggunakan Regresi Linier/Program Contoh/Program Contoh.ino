// 10 September 2023
// Alfan, Ayum, Rani
// Program Contoh Simulasi Pemrosesan data menggunakan regresi linier dengan sensor soil moisture

const int numReadings = 10;           // Jumlah pembacaan atau array

int readings[numReadings];            // Pembacaan dari analoginput
int readIndex = 0;                    // index dari pembacaan tertentu
int total = 0;                        // jumlah proses total
int average = 0;                      // rata rata

int inputPin = 2;                     // pin input dihubungkan pada GPIO2

void setup() {
  Serial.begin(9600);                 // Komunikasi serial diatur pada baudrate 9600
  
  // inisialisasi semua pembacaan ke 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}

void loop() {
  // jumlah total sama dengan nilai variabel total dikurangin pembacaan terakhir
  total = total - readings[readIndex];
  
  // membaca nilai sensor
  readings[readIndex] = analogRead(inputPin);
  
  // menambahkan nilai pembacaan ke total
  total = total + readings[readIndex];
  
  // menambahkan nilai index
  readIndex = readIndex + 1;
  
  // jika berada pada posisi terakhir array
  if (readIndex >= numReadings) {
    // mulai dari awal:
    readIndex = 0;
  }
  
  // hitung rata rata
  average = total / numReadings;
  
  // menampilkan rata rata ke serial monitor
  Serial.println(average);
  delay(1);
  // delay antar pembacaan untuk stabilitas
}