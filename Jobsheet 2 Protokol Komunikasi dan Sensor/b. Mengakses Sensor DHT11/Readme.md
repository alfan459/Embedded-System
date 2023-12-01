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

![Flowchart 1](https://github.com/alfan459/Embedded-System/assets/54757609/94fcdd67-e4f3-4228-8b80-c2f623d2e039)

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
Praktikum ini
<br></br>

# ESP32 TOUCH 2: Menyalakan LED Lewat Sensor Touch
Program kedua digunakan untuk mengatur kondisi LED menyala atau tidak melalui sensor touch ESP 32.

**1. Alat dan Bahan**
1. ESP32             ==> 1 buah
2. LED               ==> 1 buah
3. Resistor 220 Ohm  ==> 1 buah


**2. Rangkaian**

![image](https://github.com/alfan459/Embedded-System/assets/54757609/1eaff866-7a60-478d-a3d5-e373569772c9)


**3. Program**

Program dapat dilihat pada folder berikut ini: <a href="[https://github.com/alfan459/Embedded-System/tree/master/Jobsheet%201%20Dasar%20Pemrograman%20ESP32/b.%20PWM/Program%20Lanjutan%20PWM](https://github.com/alfan459/Embedded-System/tree/master/Jobsheet%202%20Protokol%20Komunikasi%20dan%20Sensor/a.%20ESP32%20Capacitive%20Touch%20Sensor/Touch%20Test%20dan%20Led)"> Program </a>

**4. Hasil dan Pembahasan**

![touch2](https://github.com/alfan459/Embedded-System/assets/54757609/9e2e53b8-c511-4ed6-9958-ffcae10c2c71)

Untuk flowchart, bisa dilihat pada gambar di bawah ini:

![Flowchart 2](https://github.com/alfan459/Embedded-System/assets/54757609/96206f0e-a708-43ae-a224-9af7bbf7c080)

Program ini bertujuan untuk mengendalikan LED dengan menggunakan sensor sentuh pada pin GPIO4 pada ESP32. Berikut adalah analisis dari program:

1. **Pengaturan Pin:**
   - `touchPin` diatur ke GPIO4, yang merupakan pin sensor sentuh.
   - `ledPin` diatur ke GPIO16, yang merupakan pin untuk mengendalikan LED.

```cpp
const int touchPin = 4;
const int ledPin = 16;
```

2. **Pengaturan Treshold:**
   - `threshold` diatur ke nilai 20. Nilai ini digunakan sebagai batas ambang untuk menentukan apakah sensor sentuh dianggap aktif atau tidak.

```cpp
const int threshold = 20;
```

3. **Inisialisasi LED dan Serial Communication:**
   - `ledPin` diinisialisasi sebagai output.
   - Komunikasi serial diatur pada baudrate 115200.
   - Terdapat delay awal 1000 ms untuk memastikan kestabilan ESP32.

```cpp
pinMode(ledPin, OUTPUT);
Serial.begin(115200);
delay(1000);
```

4. **Loop Utama:**
   - Nilai dari sensor sentuh (`touchValue`) dibaca menggunakan fungsi `touchRead(touchPin)`.
   - Nilai tersebut ditampilkan pada Serial Monitor.
   - Jika nilai touch kurang dari nilai threshold, LED dinyalakan; sebaliknya, LED dimatikan.

```cpp
touchValue = touchRead(touchPin);
Serial.print(touchValue);
if (touchValue < threshold) {
  digitalWrite(ledPin, HIGH);
  Serial.println(" - LED on");
} else {
  digitalWrite(ledPin, LOW);
  Serial.println(" - LED off");
}
delay(500);
```

Jika sensor sentuh mendeteksi sentuhan (nilai di bawah threshold), LED akan menyala. Jika sensor sentuh tidak mendeteksi sentuhan (nilai di atas atau sama dengan threshold), LED akan mati. Hasil dapat diamati melalui Serial Monitor.


**5. Kesimpulan**

Setelah menjalankan praktikum ini, didapat kesimpulan bahwa untuk menyalakan LED dibutuhkan nilai treshold untuk batasan dimana LED akan menyala dan LED akan mati. Karena nilai dari touchread sendiri bernilai analog

<br></br>
