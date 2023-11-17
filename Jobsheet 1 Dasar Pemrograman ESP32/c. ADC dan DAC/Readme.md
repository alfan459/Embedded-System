# PWM 1: Example
Program pertama akan digunakan untuk menampilkan pembacaan potensio.

**1. Alat dan Bahan**
1. ESP32             ==> 1 buah
2. Potensio 10k Ohm  ==> 1 buah


**2. Rangkaian**

![image](https://github.com/alfan459/Embedded-System/assets/54757609/2c9c037a-9eb1-472a-833c-7137a8311d9a)



**3. Program**

Program dapat dilihat pada folder berikut ini: <a href="https://github.com/alfan459/Embedded-System/tree/master/Jobsheet%201%20Dasar%20Pemrograman%20ESP32/c.%20ADC%20dan%20DAC/Program%20Contoh"> Program </a>

**4. Hasil dan Pembahasan**

![ADC DAC 1](https://github.com/alfan459/Embedded-System/assets/54757609/67c66308-4865-4563-86f5-7198c5c76a53)


Untuk flowchart, bisa dilihat pada gambar di bawah ini:

![Flowchart 1](https://github.com/alfan459/Embedded-System/assets/54757609/fb0bebfc-f73a-4bbc-886b-bc8e87bf75fc)

![adc1](https://github.com/alfan459/Embedded-System/assets/54757609/cb9647dd-0e3f-44bf-808b-e0e33dc890d0)



Terdapat potensiometer yang terhubung ke pin GPIO34 (Analog ADC1_CH6. Untuk komunikasi serial pada baudrate 115200. Menambahkan jeda waktu selama 1 detik pada awal eksekusi. Menggunakan fungsi `analogRead(potPin)` untuk membaca nilai analog dari potensiometer. Lalu nilai dibaca disimpan dalam variabel `potValue`. Setelah itu menampilkan nilai potensiometer ke Serial Monitor dengan `Serial.println(potValue)`. Menambahkan jeda waktu 500 milidetik (`delay(500)`) agar nilai yang ditampilkan tidak terlalu cepat.


**5. Kesimpulan**

Program ini memberikan pemahaman dasar tentang penggunaan ADC (Analog-to-Digital Converter) pada Arduino. Untuk mengimplementasikan DAC (Digital-to-Analog Converter), diperlukan pin DAC dan perangkat pendukung tambahan. Dalam program ini, belum ada bagian yang mengendalikan DAC. Jika ingin menggabungkan penggunaan DAC, perlu memastikan bahwa mikrokontroler Arduino yang digunakan mendukung DAC dan memiliki pin DAC yang sesuai.


<br></br>

# PWM 2
Program kedua digunakan untuk mengatur cahaya LED menggunakan potensio.

**1. Alat dan Bahan**
1. ESP32             ==> 1 buah
2. LED               ==> 1 buah
3. Resistor 220 Ohm  ==> 1 buah
3. Potensio 10k Ohm  ==> 1 buah


**2. Rangkaian**

![rangkaian2](https://github.com/alfan459/Embedded-System/assets/54757609/cae8d5af-9686-42d8-a783-a5bd18d3a090)


**3. Program**

Program dapat dilihat pada folder berikut ini: <a href="https://github.com/alfan459/Embedded-System/tree/master/Jobsheet%201%20Dasar%20Pemrograman%20ESP32/b.%20PWM/Program%20Lanjutan%20PWM"> Program </a>

**4. Hasil dan Pembahasan**

![ADC DAC 2](https://github.com/alfan459/Embedded-System/assets/54757609/7e356dc6-fb4c-4f21-99e2-f1f4b3849738)

Untuk flowchart, bisa dilihat pada gambar di bawah ini:

![Flowchart 2](https://github.com/alfan459/Embedded-System/assets/54757609/63129470-c792-4efc-bd5b-05ef3fa92b87)


![adc2](https://github.com/alfan459/Embedded-System/assets/54757609/96f9fe71-cd0e-4f95-8605-4cb253f8be29)


Terdapat potensiometer yang terhubung ke pin GPIO34 (Analog input). Juga terdapat LED yang terhubung ke pin GPIO5 (Analog output).
Untuk komunikasi serial pada baudrate diatur pada 115200.

**Pengaturan PWM:**
   - Mengkonfigurasi LED PWM dengan `ledcSetup`.
   - Menghubungkan channel PWM ke GPIO untuk mengontrol LED dengan `ledcAttachPin`.

**Loop Utama:**
   - **Membaca Nilai Analog:**
     - Menggunakan fungsi `analogRead(analogInPin)` untuk membaca nilai analog dari potensiometer.
     - Menyimpan nilai analog dalam variabel `sensorValue`.
   - **Mapping Nilai Analog:**
     - Menggunakan fungsi `map` untuk mengonversi nilai analog (0-4095) ke rentang nilai PWM (0-255).
     - Menyimpan nilai hasil mapping dalam variabel `outputValue`.
   - **Mengatur LED:**
     - Menggunakan `analogWrite` untuk mengatur kecerahan LED berdasarkan nilai yang telah dimapped.
   - **Serial Monitor:**
     - Menampilkan nilai sensor dan output ke Serial Monitor.
   - **Jeda Waktu:**
     - Menunggu 2 milidetik sebelum melakukan pembacaan nilai analog selanjutnya.

Program ini mengimplementasikan kontrol kecerahan LED menggunakan potensiometer. Nilai analog dari potensiometer dibaca, di-mapped, dan kemudian digunakan untuk mengatur kecerahan LED melalui PWM. Informasi nilai sensor dan output ditampilkan di Serial Monitor. Jeda waktu 2 milidetik memberikan waktu untuk proses ADC dan pemrosesan selanjutnya.


**5. Kesimpulan**

Program ini memberikan pemahaman tentang penggunaan potensiometer dan kontrol PWM pada Arduino. Potensiometer digunakan sebagai input analog, dan LED diatur menggunakan sinyal PWM.


<br></br>


