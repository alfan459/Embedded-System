# A. ESP32 Wi-Fi Modes dan Wifi-Scan
Praktikum ini memperkenalkan konfigurasi mode Wi-Fi pada ESP32, menjelaskan perbedaan antara mode STA (Station), AP (Access Point), dan AP+STA. Dilanjutkan dengan praktikum wifi-scan untuk melihat jaringan Wi-Fi yang tersedia di sekitar.


**1. Alat dan Bahan**
1. ESP32             ==> 1 buah


**2. Rangkaian**

![image](https://github.com/alfan459/Embedded-System/assets/54757609/b2efc039-1443-4834-ac5d-6dd1a85054c0)


**3. Program**

Program dapat dilihat pada folder berikut ini: <a href="https://github.com/alfan459/Embedded-System/tree/master/Jobsheet%203%20Topologi%20Jaringan%20Lokal%20Dan%20Wifi/a.%20ESP32%20Wi-Fi%20Modes%20dan%20Wifi%20Scan/Scan%20Wifi
"> Program </a>

**4. Hasil dan Pembahasan**

![3 1 scan wifi](https://github.com/alfan459/Embedded-System/assets/54757609/2f8f3c2f-2f9c-4ef6-b88b-0df2446084ab)

Untuk flowchart, bisa dilihat pada gambar di bawah ini:

![Flowchart 1](https://github.com/alfan459/Embedded-System/assets/54757609/67695db9-e1aa-4be5-a2bf-8751689e73a6)


Program tersebut bertujuan untuk melakukan pemindaian (scanning) jaringan Wi-Fi yang tersedia dan menampilkan informasi seperti nama SSID (Service Set Identifier), kekuatan sinyal (RSSI), dan jenis enkripsi dari setiap jaringan yang ditemukan. Berikut adalah analisis komponen-komponen kunci dalam program:

1. **WiFi Library:** Program menggunakan WiFi library untuk melakukan operasi terkait jaringan Wi-Fi pada ESP32.

2. **Setup Function:**
   - Serial diatur pada kecepatan 115200 bps.
   - Mode WiFi diatur sebagai WiFi Station (WIFI_STA).
   - Dilakukan pemutusan koneksi dari AP (Access Point) jika sebelumnya telah terhubung.
   - Menampilkan pesan "Setup done" melalui Serial Monitor.

3. **Loop Function:**
   - Memulai pemindaian jaringan Wi-Fi.
   - Menampilkan pesan "scan start" pada awal pemindaian.
   - Jika tidak ada jaringan yang ditemukan, menampilkan pesan "no networks found".
   - Jika terdapat jaringan, menampilkan jumlah jaringan yang ditemukan dan informasi detail setiap jaringan.
   - Menunggu selama 5 detik sebelum melakukan pemindaian lagi.

**5. Kesimpulan**

Program ini menggunakan ESP32 untuk melakukan pemindaian jaringan Wi-Fi yang tersedia di sekitarnya. Dengan menggunakan WiFi library, program dapat menampilkan informasi seperti nama SSID, kekuatan sinyal (RSSI), dan jenis enkripsi dari setiap jaringan yang terdeteksi. Selain itu, program juga dapat mendeteksi apakah tidak ada jaringan Wi-Fi yang ditemukan.

<br></br>

# B. Menghubungkan ESP32 dengan Jaringan Wi-Fi
Pada praktikum ini, fokusnya adalah mengajarkan cara mengonfigurasi ESP32 untuk terhubung ke jaringan Wi-Fi yang ada, sehingga dapat berinteraksi dengan internet atau jaringan lokal.

**1. Alat dan Bahan**
1. ESP32             ==> 1 buah


**2. Rangkaian**

![image](https://github.com/alfan459/Embedded-System/assets/54757609/b2efc039-1443-4834-ac5d-6dd1a85054c0)


**3. Program**

Program dapat dilihat pada folder berikut ini: <a href="https://github.com/alfan459/Embedded-System/tree/master/Jobsheet%203%20Topologi%20Jaringan%20Lokal%20Dan%20Wifi/b.%20Menghubungkan%20ESP32%20dengan%20Jaringan%20Wifi/Terhubung%20ke%20wifi
"> Program </a>

**4. Hasil dan Pembahasan**

![3 2 Connect Wifi](https://github.com/alfan459/Embedded-System/assets/54757609/e47e911e-d9c3-44e6-a9bf-6039f1d962d6)


Untuk Flowchart bisa dilihat pada gambar dibawah ini:

![Flowchart 2](https://github.com/alfan459/Embedded-System/assets/54757609/cee2983e-94bf-438e-b30f-9a25812181f9)


Program ini menggunakan modul WiFi pada ESP32 untuk terhubung ke jaringan Wi-Fi dengan mode STATION. Berikut adalah penjelasan baris program:

1. **Include Library WiFi:**
   ```cpp
   #include <WiFi.h>
   ```
   Menggunakan library WiFi untuk mengakses fitur jaringan pada ESP32.

2. **Pengaturan Koneksi Wi-Fi:**
   ```cpp
   const char* ssid = "Galaxy A02s3ad8";
   const char* password = "jayu0435";
   ```
   Menyimpan nama dan kata sandi (SSID dan password) jaringan Wi-Fi yang akan dihubungi.

3. **Fungsi initWiFi():**
   ```cpp
   void initWiFi() {
     WiFi.mode(WIFI_STA);
     WiFi.begin(ssid, password);
     Serial.print("Connecting to WiFi ..");
     while (WiFi.status() != WL_CONNECTED) {
       Serial.print('.');
       delay(1000);
     }
     Serial.println(WiFi.localIP());
   }
   ```
   - `WiFi.mode(WIFI_STA);`: Mengatur mode Wi-Fi sebagai STATION (modus klien).
   - `WiFi.begin(ssid, password);`: Memulai koneksi ke jaringan Wi-Fi dengan menggunakan SSID dan password yang telah ditentukan.
   - `while (WiFi.status() != WL_CONNECTED) { ... }`: Menunggu hingga koneksi Wi-Fi terhubung.
   - `Serial.println(WiFi.localIP());`: Menampilkan alamat IP lokal setelah terhubung.

4. **Setup Awal:**
   ```cpp
   void setup() {
     Serial.begin(115200);
     initWiFi();
     Serial.print("RRSI: ");
     Serial.println(WiFi.RSSI());
   }
   ```
   - `Serial.begin(115200);`: Memulai komunikasi serial dengan baud rate 115200.
   - Memanggil fungsi `initWiFi()` untuk mengatur koneksi Wi-Fi.
   - Menampilkan kekuatan sinyal Wi-Fi (RSSI) menggunakan `WiFi.RSSI()`.

5. **Loop Utama:**
   ```cpp
   void loop() {
     // put your main code here, to run repeatedly:
   }
   ```
   Loop utama yang dapat diisi dengan kode program utama.

**5. Kesimpulan**

Program ini bertujuan untuk menghubungkan ESP32 ke jaringan Wi-Fi dengan menggunakan mode STATION dan menampilkan kekuatan sinyal (RSSI). Fungsi `initWiFi()` digunakan untuk mengatur dan menunggu hingga koneksi Wi-Fi terbentuk. Program kemudian menampilkan alamat IP lokal dan kekuatan sinyal melalui komunikasi serial. Pastikan untuk mengganti nilai `ssid` dan `password` sesuai dengan informasi jaringan Wi-Fi yang akan digunakan.



<br></br>

# C. Menghubungkan Kembali (Re-connect) ESP32 dengan Jaringan Wi-Fi
Praktikum ini membahas strategi untuk mengelola situasi ketika koneksi Wi-Fi terputus dan cara mengonfigurasi ESP32 agar dapat menghubungkan kembali secara otomatis.

**1. Alat dan Bahan**
1. ESP32             ==> 1 buah


**2. Rangkaian**

![image](https://github.com/alfan459/Embedded-System/assets/54757609/b2efc039-1443-4834-ac5d-6dd1a85054c0)


**3. Program**

Program dapat dilihat pada folder berikut ini: <a href="https://github.com/alfan459/Embedded-System/tree/master/Jobsheet%203%20Topologi%20Jaringan%20Lokal%20Dan%20Wifi/c.%20Reconnect%20ESP32%20Dengan%20Jaringan%20Wifi/Reconnect%20Wifi
"> Program </a>

**4. Hasil dan Pembahasan**

![3 3 Reconnecting](https://github.com/alfan459/Embedded-System/assets/54757609/24fb382a-b163-4c01-a1d6-fb01cb9fb8ae)

Flowchart dapat dilihat pada gambar dibawah ini:

![Flowchart 3](https://github.com/alfan459/Embedded-System/assets/54757609/74a44b6a-173e-47b3-a3af-4bd3a810d50f)


Program ini adalah contoh penggunaan ESP32 untuk terus mencoba menghubungkan ke jaringan Wi-Fi setiap 30 detik sekali jika koneksi terputus. Berikut adalah penjelasan baris program:

1. **Include Library WiFi:**
   ```cpp
   #include <WiFi.h>
   ```
   Menggunakan library WiFi untuk mengakses fitur jaringan pada ESP32.

2. **Pengaturan Koneksi Wi-Fi:**
   ```cpp
   const char* ssid = "Galaxy A02s3ad8";
   const char* password = "jayu0435";
   ```
   Menyimpan nama dan kata sandi (SSID dan password) jaringan Wi-Fi yang akan dihubungi.

3. **Variabel Waktu dan Inisialisasi WiFi:**
   ```cpp
   unsigned long previousMillis = 0;
   unsigned long interval = 30000;
   ```
   - `previousMillis`: Menyimpan waktu terakhir saat mencoba terhubung ke Wi-Fi.
   - `interval`: Interval waktu (30 detik) untuk mencoba kembali terhubung ke Wi-Fi.

4. **Fungsi initWiFi():**
   ```cpp
   void initWiFi() {
     WiFi.mode(WIFI_STA);
     WiFi.begin(ssid, password);
     Serial.print("Connecting to WiFi ..");
     while (WiFi.status() != WL_CONNECTED) {
       Serial.print('.');
       delay(1000);
     }
     Serial.println(WiFi.localIP());
   }
   ```
   Fungsi ini mirip dengan program sebelumnya. Digunakan untuk mengatur dan menunggu hingga koneksi Wi-Fi terbentuk. Program ini mencoba terhubung setiap kali dijalankan.

5. **Setup Awal:**
   ```cpp
   void setup() {
     Serial.begin(115200);
     initWiFi();
     Serial.print("RRSI: ");
     Serial.println(WiFi.RSSI());
   }
   ```
   Inisialisasi komunikasi serial dan koneksi Wi-Fi saat program pertama kali dijalankan.

6. **Loop Utama:**
   ```cpp
   void loop() {
     unsigned long currentMillis = millis();
     // if WiFi is down, try reconnecting every CHECK_WIFI_TIME seconds
     if ((WiFi.status() != WL_CONNECTED) && (currentMillis - previousMillis >= interval)) {
       Serial.print(millis());
       Serial.println("Reconnecting to WiFi...");
       WiFi.disconnect();
       WiFi.reconnect();
       previousMillis = currentMillis;
     }
   }
   ```
   - `currentMillis`: Menyimpan waktu saat ini menggunakan fungsi `millis()` untuk menghitung interval.
   - Program mengecek apakah koneksi Wi-Fi terputus (`WiFi.status() != WL_CONNECTED`) dan jika sudah mencapai interval waktu (`currentMillis - previousMillis >= interval`).
   - Jika kondisi terpenuhi, program mencetak waktu saat itu dan mencoba me-reset dan menghubungkan ulang ke Wi-Fi dengan menggunakan `WiFi.disconnect()` dan `WiFi.reconnect()`.


**5. Kesimpulan**

Program ini dirancang untuk terus mencoba menghubungkan ESP32 ke jaringan Wi-Fi setiap 30 detik sekali jika koneksi terputus. Ini dapat berguna dalam situasi di mana koneksi Wi-Fi mungkin tidak stabil. Pastikan untuk mengganti nilai `ssid` dan `password` sesuai dengan informasi jaringan Wi-Fi yang akan digunakan.
<br></br>

# D. Mengganti Hostname ESP32
Pada praktikum ini, peserta akan mempelajari cara mengganti hostname pada ESP32. Hal ini berguna dalam mengidentifikasi perangkat dengan nama yang lebih bermakna dalam jaringan.

**1. Alat dan Bahan**
1. ESP32             ==> 1 buah


**2. Rangkaian**

![image](https://github.com/alfan459/Embedded-System/assets/54757609/b2efc039-1443-4834-ac5d-6dd1a85054c0)

**3. Program**

Program dapat dilihat pada folder berikut ini: <a href="https://github.com/alfan459/Embedded-System/tree/master/Jobsheet%203%20Topologi%20Jaringan%20Lokal%20Dan%20Wifi/d.%20Mengganti%20Hostname%20ESP32/HostnameESP32"> Program </a>

**4. Hasil dan Pembahasan**

![3 4a Mengganti Hostanem](https://github.com/alfan459/Embedded-System/assets/54757609/3064b798-8636-418f-a469-496a591792f3)

![3 4b Mengganti hostname](https://github.com/alfan459/Embedded-System/assets/54757609/46be21c5-86d0-4fac-a0f3-c9984830f65c)


Flowchart dapat dilihat pada gambar dibawah ini:

![Flowchart 4](https://github.com/alfan459/Embedded-System/assets/54757609/1dbd9fcc-6d12-408c-91d4-81bfbc04a9b5)


Program ini adalah contoh penggunaan ESP32 untuk menghubungkan ke jaringan Wi-Fi dengan menetapkan hostname untuk modul ESP32. Berikut adalah penjelasan baris program:

1. **Include Library WiFi:**
   ```cpp
   #include <WiFi.h>
   ```
   Menggunakan library WiFi untuk mengakses fitur jaringan pada ESP32.

2. **Pengaturan Koneksi Wi-Fi dan Hostname:**
   ```cpp
   const char* ssid = "Galaxy A02s3ad8";
   const char* password = "jayu0435";
   String hostname = "ESP32 Node Temperature";
   ```
   - Menyimpan nama dan kata sandi (SSID dan password) jaringan Wi-Fi yang akan dihubungi.
   - `hostname`: Menyimpan nama host yang akan diberikan kepada ESP32.

3. **Fungsi initWiFi():**
   ```cpp
   void initWiFi() {
     WiFi.mode(WIFI_STA);
     WiFi.config(INADDR_NONE, INADDR_NONE, INADDR_NONE, INADDR_NONE);
     WiFi.setHostname(hostname.c_str());  // define hostname
     WiFi.begin(ssid, password);
     Serial.print("Connecting to WiFi ..");
     while (WiFi.status() != WL_CONNECTED) {
       Serial.print('.');
       delay(1000);
     }
     Serial.println(WiFi.localIP());
   }
   ```
   - Mengatur mode Wi-Fi ke mode STATION.
   - `WiFi.config(INADDR_NONE, INADDR_NONE, INADDR_NONE, INADDR_NONE);`: Menonaktifkan konfigurasi manual IP.
   - `WiFi.setHostname(hostname.c_str());`: Menetapkan hostname untuk ESP32.
   - Menunggu hingga ESP32 terhubung ke jaringan Wi-Fi.

4. **Setup Awal:**
   ```cpp
   void setup() {
     Serial.begin(115200);
     initWiFi();
     Serial.print("RRSI: ");
     Serial.println(WiFi.RSSI());
   }
   ```
   Inisialisasi komunikasi serial, koneksi Wi-Fi, dan pencetakan kekuatan sinyal (RSSI) Wi-Fi saat program pertama kali dijalankan.

5. **Loop Utama:**
   ```cpp
   void loop() {
     // put your main code here, to run repeatedly:
   }
   ```
   Bagian ini kosong karena tidak ada perintah khusus yang perlu dijalankan secara berulang dalam loop utama.


**5. Kesimpulan**

Program ini dirancang untuk menghubungkan ESP32 ke jaringan Wi-Fi menggunakan mode STATION dan menetapkan hostname sebagai "ESP32 Node Temperature". Menetapkan hostname dapat memudahkan identifikasi perangkat di jaringan. Pastikan untuk mengganti nilai `ssid` dan `password` sesuai dengan informasi jaringan Wi-Fi yang akan digunakan, dan sesuaikan `hostname` sesuai kebutuhan.


<br></br>

# E. Mengirim Data Sensor ke Database
Praktikum terakhir membahas pengiriman data sensor dari ESP32 ke database melalui koneksi Wi-Fi. Mahasiswa akan memahami langkah-langkah untuk mentransfer data sensor ke server, merangkum konsep pengiriman data melalui protokol Wi-Fi.

**1. Alat dan Bahan**
1. ESP32             ==> 1 buah
2. DHT11             ==> 1 buah
3. Resistor 10k Ohm  ==> 1 buah


**2. Rangkaian**

![image](https://github.com/alfan459/Embedded-System/assets/54757609/059a4503-f68f-4165-bd67-5182c5e70eb4)


**3. Program**

Program dapat dilihat pada folder berikut ini: <a href="https://github.com/alfan459/Embedded-System/tree/master/Jobsheet%203%20Topologi%20Jaringan%20Lokal%20Dan%20Wifi/e.%20Mengirim%20Data%20Sensor%20ke%20Database/Mengirim%20Data"> Program </a>

**4. Hasil dan Pembahasan**

![3 5 Hasil Browser](https://github.com/alfan459/Embedded-System/assets/54757609/90efb765-51f1-4752-82f1-b97620117bca)

![3 5 Hasil serial monitor](https://github.com/alfan459/Embedded-System/assets/54757609/22c1a25f-5f92-4727-8a61-39f54b67b6ca)

![3 5 Mengirim data ke database](https://github.com/alfan459/Embedded-System/assets/54757609/57b621c1-be10-45f0-8cc1-d50d4afadd6e)

Untuk flowchartnya bisa dilihat pada gambar di bawah ini:


Program ini adalah contoh implementasi ESP32 sebagai server web yang memberikan data suhu dan kelembapan dari sensor DHT11. Berikut adalah analisis singkat programnya:

1. **Include Library:**
   ```cpp
   #include "WiFi.h"
   #include "ESPAsyncWebServer.h"
   #include <Adafruit_Sensor.h>
   #include <DHT.h>
   ```
   - Menggunakan library WiFi dan ESPAsyncWebServer untuk menangani koneksi Wi-Fi dan pembuatan server web secara asynchronous.
   - Menggunakan library Adafruit_Sensor dan DHT untuk membaca data dari sensor DHT.

2. **Pengaturan Koneksi Wi-Fi dan Sensor DHT:**
   ```cpp
   const char* ssid = "Galaxy A02s3ad8";
   const char* password = "jayu0435";
   #define DHTPIN 4
   #define DHTTYPE DHT11
   DHT dht(DHTPIN, DHTTYPE);
   ```
   - Menyimpan nama dan kata sandi jaringan Wi-Fi.
   - Menetapkan pin digital yang terhubung ke sensor DHT dan tipe sensornya.

3. **Inisialisasi Server Web:**
   ```cpp
   AsyncWebServer server(80);
   ```
   Membuat objek server web asinkron pada port 80.

4. **Fungsi Baca Suhu dan Kelembapan dari Sensor DHT:**
   ```cpp
   String readDHTTemperature() { /* ... */ }
   String readDHTHumidity() { /* ... */ }
   ```
   - Membaca suhu dan kelembapan dari sensor DHT.
   - Mengembalikan nilai "--" jika pembacaan gagal.

5. **HTML untuk Halaman Web:**
   ```cpp
   const char index_html[] PROGMEM = R"rawliteral( /* ... */ )rawliteral";
   ```
   HTML yang akan dikirimkan sebagai respons dari server. Terdapat placeholder `%TEMPERATURE%` dan `%HUMIDITY%` yang akan digantikan dengan nilai aktual.

6. **Fungsi Processor untuk Menggantikan Nilai Placeholder:**
   ```cpp
   String processor(const String& var) { /* ... */ }
   ```
   - Menggantikan placeholder dengan nilai aktual dari sensor DHT.

7. **Setup Awal:**
   ```cpp
   void setup() { /* ... */ }
   ```
   - Mengatur komunikasi serial dan inisialisasi sensor DHT.
   - Membuat koneksi ke jaringan Wi-Fi dan menunggu hingga terhubung.
   - Menyiapkan route untuk halaman web dan endpoint suhu/kelembapan.
   - Memulai server web.

8. **Loop Utama:**
   ```cpp
   void loop() { /* ... */ }
   ```
   Loop utama kosong karena semua operasi dilakukan secara asinkron di server web.

**5. Kesimpulan**

Program ini menggunakan ESP32 sebagai server web yang menyajikan data suhu dan kelembapan dari sensor DHT11. Data dapat diakses melalui halaman web atau melalui endpoint `/temperature` dan `/humidity` secara terpisah. Program ini juga memanfaatkan teknologi asinkron pada server web untuk meningkatkan efisiensi dan responsivitas.
<br><br>

# F. Pertanyaan dan Tugas
Buatlah program pada ESP32 dengan urutan proses seperti berikut ini, 
agar ESP32 bisa melakukan setting SSID dan Passsword lebih fleksibel. 
a. Ketika pertama kali booting, mode ESP32 adalah Station Mode 
untuk membaca kombinasi SSID dan Password pada jaringan 
sebelumnya.  
b. Jika gagal, ESP32 akan berubah mode manjadi Access Point Mode 
dan membuat jaringan Wi-Fi tanpa proteksi/tanpa password, agar 
user dapat terhubung dengan ESP32. 
c. Setelah itu, hubungkan laptop dengan ESP32 dan akses IP Address 
ESP32 (ESP32 Web Server) pada browser laptop untuk membua 
konfigurasi SSID dan Password dan menyimpannya pada 
EEPROM. 
d. Kemudian matikan ESP32. ESP32 akan berusaha terhubung 
dengan jaringan yang telah dikonfigurasi sebelumnya. 
e. Jika berhasil terhubung, pada serial monitor akan terdapat pesan 
Connected to “SSID” Successfully. 
f. 
Jika gagal terhubung, ESP32 akan masuk pada mode Access Point 
kembali untuk melakukan konfigurasi SSID dan Password. 


**1. Program**

Program dapat dilihat pada folder berikut ini: <a href="https://github.com/alfan459/Embedded-System/tree/master/Jobsheet%203%20Topologi%20Jaringan%20Lokal%20Dan%20Wifi/Pertanyaan%20dan%20Tugas/Tugas"> Program </a>

**2. Hasil dan Pembahasan**

![Tugas](https://github.com/alfan459/Embedded-System/assets/54757609/3005a905-352d-4326-9626-fdcc1421098a)

![Tugas1](https://github.com/alfan459/Embedded-System/assets/54757609/ed684a08-8ab5-4931-a984-dd13d2499855)

![Tugas2](https://github.com/alfan459/Embedded-System/assets/54757609/79b7c13d-aad8-405d-bc00-063d8a4a19ec)


Untuk flowchart, bisa dilihat pada gambar di bawah ini:

Program ini dirancang untuk memungkinkan ESP32 melakukan konfigurasi WiFi baik dalam mode terhubung ke jaringan WiFi yang telah dikonfigurasi sebelumnya maupun dalam mode Access Point (AP) untuk konfigurasi ulang. Berikut adalah analisis programnya:

1. **Include Library:**
   ```cpp
   #include <WiFi.h>
   #include <EEPROM.h>
   #include <ESPAsyncWebServer.h>
   ```
   - Menggunakan library WiFi untuk mengelola koneksi WiFi.
   - Menggunakan library EEPROM untuk menyimpan dan membaca data dari EEPROM.
   - Menggunakan library ESPAsyncWebServer untuk membuat server web asinkron.

2. **Deklarasi Variabel:**
   ```cpp
   const char *apSSID = "ESP32_AP";
   const char *apPassword = "";

   char ssid[32];
   char password[64];
   ```
   - Menyimpan nama dan kata sandi AP (Access Point) yang digunakan ketika ESP32 berada dalam mode konfigurasi.
   - Menyimpan SSID dan kata sandi WiFi yang akan dihubungkan oleh ESP32.

3. **Inisialisasi Server Web:**
   ```cpp
   AsyncWebServer server(80);
   ```
   - Membuat objek server web asinkron pada port 80.

4. **Setup Awal:**
   ```cpp
   void setup() { /* ... */ }
   ```
   - Inisialisasi komunikasi serial dan EEPROM.
   - Membaca SSID dan kata sandi dari EEPROM.
   - Mencoba terhubung ke jaringan WiFi yang telah dikonfigurasi sebelumnya.
   - Jika gagal, ESP32 berubah menjadi mode Access Point dan membuka konfigurasi melalui server web.

5. **Loop Utama:**
   ```cpp
   void loop() { /* ... */ }
   ```
   - Jika tidak terhubung ke jaringan WiFi, ESP32 akan mencoba terhubung kembali.
   - Jika gagal, ESP32 masuk ke mode Access Point untuk konfigurasi ulang.

6. **Fungsi Read dan Write EEPROM:**
   ```cpp
   void readSSIDAndPassword() { /* ... */ }
   void writeSSIDAndPassword() { /* ... */ }
   ```
   - Membaca dan menulis SSID dan kata sandi ke EEPROM.

7. **Fungsi Connect to WiFi:**
   ```cpp
   bool connectToWiFi() { /* ... */ }
   ```
   - Mencoba terhubung ke jaringan WiFi yang telah dikonfigurasi sebelumnya.
   - Mengembalikan status koneksi.

8. **Fungsi Create Access Point:**
   ```cpp
   void createAccessPoint() { /* ... */ }
   ```
   - Mengubah ESP32 menjadi mode Access Point.
   - Menyediakan nama SSID dan kata sandi AP.
   - Menampilkan alamat IP AP melalui serial.

9. **Fungsi Setup Web Server:**
   ```cpp
   void setupWebServer() { /* ... */ }
   ```
   - Menyiapkan route untuk halaman konfigurasi web.
   - Meng-handle HTTP GET untuk menampilkan halaman konfigurasi.
   - Meng-handle HTTP POST untuk menyimpan konfigurasi yang baru.


**3. Kesimpulan**

Program ini memungkinkan ESP32 melakukan konfigurasi WiFi dengan cara yang lebih fleksibel, baik dengan terhubung ke jaringan WiFi yang telah dikonfigurasi sebelumnya maupun melalui mode Access Point untuk konfigurasi ulang. Konfigurasi dilakukan melalui antarmuka web yang sederhana dan dapat diakses dari perangkat lain dalam jaringan yang sama.


<br></br>
