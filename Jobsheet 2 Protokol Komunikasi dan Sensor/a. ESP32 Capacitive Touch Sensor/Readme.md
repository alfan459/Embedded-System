# ESP32 TOUCH 1: Example
Program pertama akan digunakan untuk menampilkan pembacaan sensor touch ESP32.

**1. Alat dan Bahan**
1. ESP32             ==> 1 buah

**2. Rangkaian**

![image](https://github.com/alfan459/Embedded-System/assets/54757609/f172e71d-7663-476e-b929-b32ce02d00b5)


**3. Program**

Program dapat dilihat pada folder berikut ini: <a href="https://github.com/alfan459/Embedded-System/tree/master/Jobsheet%202%20Protokol%20Komunikasi%20dan%20Sensor/a.%20ESP32%20Capacitive%20Touch%20Sensor/Program%20Contoh"> Program </a>

**4. Hasil dan Pembahasan**

https://github.com/alfan459/Embedded-System/assets/54757609/caead734-0d30-4f79-be89-72f7cb674c8f

Untuk flowchart, bisa dilihat pada gambar di bawah ini:

![Flowchart 1](https://github.com/alfan459/Embedded-System/assets/54757609/94fcdd67-e4f3-4228-8b80-c2f623d2e039)

Program ini adalah contoh penggunaan fitur *touch* pada ESP32. Fitur ini memungkinkan ESP32 membaca nilai dari sensor sentuh yang terhubung ke pin tertentu. Berikut analisis singkat dari program:

1. **Serial Communication Setup:**
   - Baudrate serial diatur pada 115200 bps.
   - Terdapat delay awal sebesar 1000 ms untuk memberikan waktu ESP32 untuk stabil.

```cpp
Serial.begin(115200);
delay(1000);
```

2. **Loop:**
   - Pada setiap iterasi loop, nilai dari sensor sentuh yang terhubung ke pin GPIO 4 dibaca menggunakan fungsi `touchRead(4)`.
   - Nilai tersebut kemudian ditampilkan melalui Serial Monitor.
   - Terdapat delay 1000 ms untuk memberikan interval waktu antar pembacaan.

```cpp
Serial.println(touchRead(4));
delay(1000);
```

Praktikum berhasil dilakukan jika ESP32 mampu membaca dan menampilkan nilai sensor sentuh pada Serial Monitor. Variasi nilai yang ditampilkan mencerminkan tingkat sentuhan pada sensor. Perlu dipahami bahwa nilai yang dibaca dari sensor sentuh bersifat relatif dan dapat bervariasi tergantung pada kondisi lingkungan.

**5. Kesimpulan**

Praktikum berhasil dilakukan jika ESP32 mampu membaca dan menampilkan nilai sensor sentuh pada Serial Monitor.

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

# ESP32 TOUCH 3: LED Blink & Touchsensor
Program ini digunakan untuk menyalakan LED secara blink ketika sensor touch disentuh.

**1. Alat dan Bahan**
1. ESP32             ==> 1 buah
2. Resistor 220 ohm  ==> 1 buah
3. LED               ==> 1 buah

**2. Rangkaian**

![image](https://github.com/alfan459/Embedded-System/assets/54757609/1eaff866-7a60-478d-a3d5-e373569772c9)


**3. Program**

Program dapat dilihat pada folder berikut ini: <a href="https://github.com/alfan459/Embedded-System/tree/master/Jobsheet%202%20Protokol%20Komunikasi%20dan%20Sensor/a.%20ESP32%20Capacitive%20Touch%20Sensor/Touch%20Test%20dan%20Led%20Blink"> Program </a>

**4. Hasil dan Pembahasan**

![touch3](https://github.com/alfan459/Embedded-System/assets/54757609/f58b84ff-c28f-49a2-9c2a-d803b31ae20f)

Untuk flowchart, bisa dilihat pada gambar di bawah ini:

![Flowchart 3](https://github.com/alfan459/Embedded-System/assets/54757609/6a8936ef-da54-4475-91cd-f63e896309a0)

Program ini dirancang untuk mengendalikan LED dengan sensor sentuh pada pin GPIO4 pada ESP32. Berikut adalah analisis program:

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
   - Jika nilai touch kurang dari nilai threshold, LED akan berkedip dengan interval 1 detik ON dan 1 detik OFF.

```cpp
touchValue = touchRead(touchPin);
Serial.print(touchValue);
if (touchValue < threshold) {
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
  Serial.println(" - LED Blink");
} else {
  digitalWrite(ledPin, LOW);
  Serial.println(" - LED off");
}
delay(500);
```

Jika sensor sentuh mendeteksi sentuhan (nilai di bawah threshold), LED akan berkedip dengan interval 1 detik ON dan 1 detik OFF. Jika sensor sentuh tidak mendeteksi sentuhan (nilai di atas atau sama dengan threshold), LED akan mati. Hasil dapat diamati melalui Serial Monitor.

**5. Kesimpulan**

Untuk membuat LED menyala menjadi blink maka diatur pada kondisi ketika nilai touchRead berada dibawah treshold. Dan ketika diatas treshold maka diatur untuk kondisi LED mati.

<br></br>

# ESP32 TOUCH 4: Touchsensor Count
Program ini digunakan untuk menampilkan nilai yang terus bertambah pada serial monitor ketika touchsensor ditekan.

**1. Alat dan Bahan**
1. ESP32             ==> 1 buah
2. LED               ==> 1 buah
3. Resistor 220 ohm  ==> 1 buah

**2. Rangkaian**

![image](https://github.com/alfan459/Embedded-System/assets/54757609/1eaff866-7a60-478d-a3d5-e373569772c9)


**3. Program**

Program dapat dilihat pada folder berikut ini: <a href="https://github.com/alfan459/Embedded-System/tree/master/Jobsheet%202%20Protokol%20Komunikasi%20dan%20Sensor/a.%20ESP32%20Capacitive%20Touch%20Sensor/Touchcount"> Program </a>

**4. Hasil dan Pembahasan**

https://github.com/alfan459/Embedded-System/assets/54757609/505c5c47-1b4f-40c5-8997-02c481a8cb3e

Untuk flowchart, bisa dilihat pada gambar di bawah ini:

![Flowchart 4](https://github.com/alfan459/Embedded-System/assets/54757609/d12c3870-5c53-40cd-9eef-bdd5f421809b)


1. **Pengaturan Pin:**
   - `ledPin` diatur ke pin GPIO2, yang merupakan pin untuk mengendalikan LED.
   - `touchPin` diatur ke pin GPIO4, yang merupakan pin sensor sentuh.
   - `touchCount` digunakan sebagai variabel untuk menghitung jumlah sentuhan.

```cpp
const int ledPin = 2;
const int touchPin = 4;
int touchCount = 0;
```

2. **Setup Awal:**
   - Komunikasi serial diatur pada baudrate 115200.
   - `ledPin` diinisialisasi sebagai output.
   - `touchPin` diinisialisasi sebagai input.

```cpp
void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  pinMode(touchPin, INPUT);
}
```

3. **Loop Utama:**
   - Jika sensor sentuh (`touchPin`) mendeteksi sentuhan (nilai HIGH), program akan melakukan beberapa tindakan:
      - Menambah nilai `touchCount` sebanyak 1.
      - Menyalakan LED (`ledPin`).
      - Menampilkan informasi sentuhan ke Serial Monitor.
      - Menunggu 500 ms untuk menghindari deteksi berulang.
   - Jika sensor sentuh tidak mendeteksi sentuhan (nilai LOW), LED dimatikan.

```cpp
void loop() {
  if (digitalRead(touchPin) == HIGH) {
    touchCount++;
    digitalWrite(ledPin, HIGH);
    Serial.print("Sentuhan ke-");
    Serial.println(touchCount);
    delay(500);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
```

**5. Kesimpulan**

Touch sensor bisa dibaca secara digital dan analog. Jika secara digital maka ketika ditekan akan bernilai HIGH dan jika tidak maka bernilai LOW. Lalu untuk menambahkan sebuah nilai variable dapat dilakukan dengan increament (++).

<br></br>

# ESP32 TOUCH 5: Touchsensor & Running LED
Program ini digunakan untuk menyalakan LED secara running dari kiri ke kanan ketika touchsensor ditekan.

**1. Alat dan Bahan**
1. ESP32             ==> 1 buah
2. LED               ==> 3 buah
3. Resistor 220 ohm  ==> 3 buah

**2. Rangkaian**

![rangkaian5](https://github.com/alfan459/Embedded-System/assets/54757609/61b78942-b317-4169-bea8-0e518f47d3df)


**3. Program**

Program dapat dilihat pada folder berikut ini: <a href="https://github.com/alfan459/Embedded-System/tree/master/Jobsheet%202%20Protokol%20Komunikasi%20dan%20Sensor/a.%20ESP32%20Capacitive%20Touch%20Sensor/Touch%20dan%20Running%20Led"> Program </a>

**4. Hasil dan Pembahasan**

![touch5](https://github.com/alfan459/Embedded-System/assets/54757609/faf4252e-1251-406a-8cae-952e32aa6b2e)

Untuk flowchart, bisa dilihat pada gambar di bawah ini:

![Flowchart 4](https://github.com/alfan459/Embedded-System/assets/54757609/d12c3870-5c53-40cd-9eef-bdd5f421809b)


1. **Pengaturan Pin:**
   - `ledPin` diatur ke pin GPIO2, yang merupakan pin untuk mengendalikan LED.
   - `touchPin` diatur ke pin GPIO4, yang merupakan pin sensor sentuh.
   - `touchCount` digunakan sebagai variabel untuk menghitung jumlah sentuhan.

```cpp
const int ledPin = 2;
const int touchPin = 4;
int touchCount = 0;
```

2. **Setup Awal:**
   - Komunikasi serial diatur pada baudrate 115200.
   - `ledPin` diinisialisasi sebagai output.
   - `touchPin` diinisialisasi sebagai input.

```cpp
void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  pinMode(touchPin, INPUT);
}
```

3. **Loop Utama:**
   - Jika sensor sentuh (`touchPin`) mendeteksi sentuhan (nilai HIGH), program akan melakukan beberapa tindakan:
      - Menambah nilai `touchCount` sebanyak 1.
      - Menyalakan LED (`ledPin`).
      - Menampilkan informasi sentuhan ke Serial Monitor.
      - Menunggu 500 ms untuk menghindari deteksi berulang.
   - Jika sensor sentuh tidak mendeteksi sentuhan (nilai LOW), LED dimatikan.

```cpp
void loop() {
  if (digitalRead(touchPin) == HIGH) {
    touchCount++;
    digitalWrite(ledPin, HIGH);
    Serial.print("Sentuhan ke-");
    Serial.println(touchCount);
    delay(500);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
```

**5. Kesimpulan**

Touch sensor bisa dibaca secara digital dan analog. Jika secara digital maka ketika ditekan akan bernilai HIGH dan jika tidak maka bernilai LOW. Lalu untuk menambahkan sebuah nilai variable dapat dilakukan dengan increament (++).

<br></br>


