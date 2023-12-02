# ESP32 & DHT11 1: Example
Program pertama akan digunakan untuk mencoba sensor DHT11.

**1. Alat dan Bahan**
1. ESP32            ==> 1 buah
2. Resistor 10K ohm ==> 1 buah
3. DHT11            ==> 1 buah  

**2. Rangkaian**

![image](https://github.com/alfan459/Embedded-System/assets/54757609/1fe265a4-125d-48cc-b898-fea30cf33965)


**3. Program**

Program dapat dilihat pada folder berikut ini: <a href="https://github.com/alfan459/Embedded-System/tree/master/Jobsheet%202%20Protokol%20Komunikasi%20dan%20Sensor/b.%20Mengakses%20Sensor%20DHT11/Program%20Contoh"> Program </a>

**4. Hasil dan Pembahasan**

https://github.com/alfan459/Embedded-System/assets/54757609/832715cd-2ba7-4708-9520-d3906ddc5ae0

Untuk flowchart, bisa dilihat pada gambar di bawah ini:

![Flowchart 1](https://github.com/alfan459/Embedded-System/assets/54757609/d7b54174-694b-43ee-a919-b75cbd598c0f)

Program ini menggunakan sensor DHT11 untuk membaca suhu dan kelembapan. 

1. **Pendefinisian Pin dan Tipe Sensor:**
   - `DHTPIN` didefinisikan sebagai pin digital (GPIO) yang terhubung ke sensor DHT.
   - Tipe sensor DHT dipilih dengan mendefinisikan `DHTTYPE`. Untuk contoh ini, dipilih tipe DHT11, tetapi dapat diubah menjadi DHT22 atau DHT21 jika diperlukan.
   - Menambahkan juga library DHT pada awal program.
   - Untuk type dari DHT menggunakan DHT11

```cpp
#include "DHT.h"

#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
```

2. **Setup Awal:**
   - Komunikasi serial diatur pada baudrate 9600.
   - Pesan selamat datang ditampilkan di Serial Monitor.
   - Komunikasi dengan sensor DHT dimulai menggunakan `dht.begin()`.

```cpp
void setup() {
  Serial.begin(9600);
  Serial.println(F("DHT11 Embedded System Test!"));
  dht.begin();
}
```

3. **Loop Utama:**
   - Terdapat jeda waktu 2 detik (`delay(2000)`) antara pembacaan suhu dan kelembapan.
   - Pembacaan suhu dan kelembapan dilakukan menggunakan fungsi `dht.readTemperature()` dan `dht.readHumidity()`.
   - Hasil pembacaan dicek menggunakan `isnan` untuk memastikan data yang valid.
   - Heat index dihitung baik dalam Fahrenheit maupun Celsius menggunakan fungsi `dht.computeHeatIndex()`.

```cpp
void loop() {
  delay(2000);
  
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
}
```

**5. Kesimpulan**
Dalam praktikum ini kita bisa mengecek kondisi suhu dan kelembapan sekitar kita menggunakan sensor DHT11, baik dalam derajat celcius maupun farenheit.

<br></br>

# ESP32 & DHT11 2: Controlling LED & Buzzer
Program kedua digunakan untuk mengatur kondisi LED dan buzzer menyala atau tidak melalui sensor DHT11.

**1. Alat dan Bahan**
1. ESP32             ==> 1 buah
2. DHT11             ==> 1 buah
3. Resistor 220 Ohm  ==> 1 buah
4. Resistor 10K ohm  ==> 1 buah 


**2. Rangkaian**

![Rangkaian](https://github.com/alfan459/Embedded-System/assets/54757609/404322eb-617c-4736-974d-c1ec60d3c022)


**3. Program**

Program dapat dilihat pada folder berikut ini: <a href="https://github.com/alfan459/Embedded-System/tree/master/Jobsheet%202%20Protokol%20Komunikasi%20dan%20Sensor/b.%20Mengakses%20Sensor%20DHT11/Running%20Led%20dan%20Buzzer%20dengan%20dht11"> Program </a>

**4. Hasil dan Pembahasan**

https://github.com/alfan459/Embedded-System/assets/54757609/2e9c38bc-0893-4240-98a9-303b0f99527e

Untuk flowchart, bisa dilihat pada gambar di bawah ini:

![Flowchart 2](https://github.com/alfan459/Embedded-System/assets/54757609/52f6d721-8505-4c49-b68a-bbe060b83016)

Program ini menggunakan sensor DHT11 untuk membaca suhu dan kelembapan, dan berdasarkan nilai suhu, akan mengendalikan LED dan buzzer. Berikut adalah analisis program:

1. **Pendefinisian Pin dan Tipe Sensor:**
   - LED dan buzzer dikendalikan oleh pin tertentu pada mikrokontroller.
   - Pembacaan suhu dan kelembapan menggunakan sensor DHT11 seperti pada program sebelumnya.

```cpp
const int led1 = 16;    // LED1 dihubungkan pada GPIO16
const int led2 = 8;     // LED2 dihubungkan pada GPIO8
const int led3 = 9;     // LED3 dihubungkan pada GPIO9
const int buzzer = 10;  // Buzzer dihubungkan pada GPIO10
```

2. **Setup Awal:**
   - Komunikasi serial diatur pada baudrate 9600.
   - Inisialisasi LED dan buzzer sebagai output.
   - Memulai komunikasi dengan sensor DHT.

```cpp
void setup() {
  Serial.begin(9600);
  Serial.println(F("DHT11 Embedded System Test!"));
  dht.begin();
  
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  pinMode (led3, OUTPUT);
}
```

3. **Loop Utama:**
   - Terdapat jeda waktu 2 detik (`delay(2000)`) antara pembacaan suhu dan kelembapan.
   - Pembacaan suhu dan kelembapan dilakukan seperti pada program sebelumnya.
   - Jika pembacaan suhu gagal, pesan kesalahan akan ditampilkan.
   - Berdasarkan suhu, program mengendalikan LED dan buzzer sesuai kondisi tertentu.

```cpp
void loop() {
  delay(2000);
  
  // ... (pembacaan suhu dan kelembapan)

  // Jika suhu berada di bawah atau sama dengan 30 derajat, maka running LED dan aktifkan buzzer
  if (t <= 30.00) {
    digitalWrite(led1, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(1000);
    digitalWrite(buzzer, LOW);
    delay(1000);
  } else {
    // ... (pengaturan LED untuk kondisi suhu di atas 30 derajat)
  }
}
```

**5. Kesimpulan**

Program akan membaca suhu dan kelembapan setiap 2 detik. Jika suhu di bawah atau sama dengan 30 derajat, LED akan berkedip dan buzzer akan aktif. Jika suhu di atas 30 derajat, LED akan berkedip tanpa aktivasi buzzer.
<br></br>
