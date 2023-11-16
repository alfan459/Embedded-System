# PWM 1: Example
Program pertama akan digunakan untuk membuat efek fade pada LED menggunakan PWM.

**1. Alat dan Bahan**
1. ESP32             ==> 1 buah
2. LED               ==> 3 buah
3. Resistor 220 Ohm  ==> 3 buah


**2. Rangkaian**

![image](https://github.com/alfan459/Embedded-System/assets/54757609/8792b94b-a270-4b61-8a92-8e72fc0594f9)


**3. Program**

Program dapat dilihat pada folder berikut ini: <a href="https://github.com/alfan459/Embedded-System/tree/master/Jobsheet%201%20Dasar%20Pemrograman%20ESP32/b.%20PWM/Program%20Contoh"> Program </a>

**4. Hasil dan Pembahasan**

![PWM 1](https://github.com/alfan459/Embedded-System/assets/54757609/2e3cddb3-534b-4b23-aad6-f672326ef669)


Untuk flowchart, bisa dilihat pada gambar di bawah ini:

![Flowchart 1](https://github.com/alfan459/Embedded-System/assets/54757609/513e634c-38f5-4634-ab52-a57a986a241d)

![pwm1](https://github.com/alfan459/Embedded-System/assets/54757609/b2bb6a4b-01ef-4356-a43b-0e3b7ca72684)


Program tersebut adalah contoh implementasi PWM (Pulse Width Modulation) pada mikrokontroler Arduino untuk mengendalikan intensitas cahaya dari LED. Berikut analisisnya:

Inisialisasi PIN:
   - `ledPin`: Merupakan pin GPIO yang terhubung ke LED dan digunakan untuk mengatur output PWM. Dalam kasus ini, terhubung ke pin GPIO16.

Konfigurasi PWM:
   - `freq`: Menyimpan frekuensi PWM yang diinginkan, dalam hertz (Hz). Dalam kasus ini, frekuensinya adalah 5000 Hz.
   - `ledChannel`: Menyimpan nomor saluran PWM yang digunakan. Pada mikrokontroler ESP32, biasanya ada beberapa saluran PWM yang tersedia. Dalam kasus ini, menggunakan saluran 0.
   - `resolution`: Menyimpan resolusi PWM dalam bit. Semakin tinggi nilai resolusinya, semakin halus perubahan intensitas cahaya LED. Dalam kasus ini, resolusinya adalah 8 bit.

Setup:
   - `ledcSetup()`: Mengkonfigurasi saluran PWM dengan frekuensi dan resolusi yang telah ditentukan sebelumnya.
   - `ledcAttachPin()`: Menghubungkan saluran PWM dengan pin GPIO yang ditentukan (`ledPin`).
   - `pinMode()` dan `digitalWrite()`: Menginisialisasi pin 5 sebagai OUTPUT dan mengatur nilainya menjadi LOW. Meskipun pin 5 tidak digunakan dalam program, mungkin digunakan untuk tujuan lain.

Loop:
   - Terdapat dua loop for yang digunakan untuk meningkatkan dan mengurangi intensitas cahaya LED.
   - Dalam setiap loop, nilai PWM (`dutyCycle`) diubah dari 0 hingga 255 dan sebaliknya.
   - `ledcWrite()`: Digunakan untuk menetapkan tingkat intensitas cahaya LED berdasarkan nilai `dutyCycle`.
   - `delay(15)`: Memberikan jeda waktu (delay) 15 milidetik setiap kali perubahan intensitas cahaya.

Program ini menciptakan efek perlahan naik dan turun pada intensitas cahaya LED, yang sering digunakan untuk menciptakan efek "fade" atau perubahan cahaya yang halus. Nilai delay dan rentang nilai `dutyCycle` dapat disesuaikan untuk mengatur kecepatan perubahan dan rentang intensitas cahaya LED.


**5. Kesimpulan**

Penggunaan PWM memungkinkan kontrol yang halus terhadap intensitas cahaya, yang berguna dalam berbagai aplikasi seperti pencahayaan, kontrol motor, dan lainnya.

<br></br>

# PWM 2: Pengendalian 3 LED dengan Satu Channel PWM
Program pertama akan digunakan untuk membuat efek fade pada LED menggunakan PWM.

**1. Alat dan Bahan**
1. ESP32             ==> 1 buah
2. LED               ==> 3 buah
3. Resistor 220 Ohm  ==> 3 buah


**2. Rangkaian**

![image](https://github.com/alfan459/Embedded-System/assets/54757609/8792b94b-a270-4b61-8a92-8e72fc0594f9)


**3. Program**

Program dapat dilihat pada folder berikut ini: <a href="https://github.com/alfan459/Embedded-System/tree/master/Jobsheet%201%20Dasar%20Pemrograman%20ESP32/b.%20PWM/Program%20Lanjutan%20PWM"> Program </a>

**4. Hasil dan Pembahasan**

![PWM 2](https://github.com/alfan459/Embedded-System/assets/54757609/68196d0b-b263-49db-af58-069f76adcf67)



Untuk flowchart, bisa dilihat pada gambar di bawah ini:

![Flowchart 2](https://github.com/alfan459/Embedded-System/assets/54757609/5170fdd7-efc4-4336-8f00-75edc6b9ff50)

![pwm2](https://github.com/alfan459/Embedded-System/assets/54757609/58620bb3-c009-40e5-b015-aecf93530e7d)


Program Arduino yang diberikan adalah contoh penggunaan PWM untuk mengendalikan intensitas cahaya pada tiga LED yang berbeda (LED1, LED2, dan LED3) menggunakan satu saluran PWM. Berikut adalah analisa dari program tersebut:

#### **1. Pengaturan Pin:**
   - `ledPin`: Terhubung ke LED1 dan diatur pada pin GPIO16.
   - `ledPin2`: Terhubung ke LED2 dan diatur pada pin GPIO17.
   - `ledPin3`: Terhubung ke LED3 dan diatur pada pin GPIO5.

#### **2. Pengaturan PWM:**
   - Frekuensi PWM (`freq`) diatur sebesar 5000 Hz.
   - Resolusi PWM (`resolution`) diatur sebesar 8-bit.

#### **3. Setup:**
   - `ledcSetup(ledChannel, freq, resolution)`: Mengkonfigurasi saluran PWM dengan frekuensi dan resolusi tertentu.
   - `ledcAttachPin(ledPin, ledChannel)`, `ledcAttachPin(ledPin2, ledChannel)`, `ledcAttachPin(ledPin3, ledChannel)`: Menghubungkan saluran PWM dengan masing-masing pin LED.

#### **4. Loop:**
   - **Loop Pertama:**
     - Meningkatkan intensitas cahaya pada ketiga LED dari 0 hingga 255.
     - Menggunakan `ledcWrite(ledChannel, dutyCycle)` untuk mengatur intensitas cahaya dengan nilai `dutyCycle`.
     - `delay(15)`: Memberikan jeda 15 milidetik untuk efek perlahan.

   - **Loop Kedua:**
     - Mengurangi intensitas cahaya pada ketiga LED dari 255 hingga 0.
     - Sama seperti loop pertama, menggunakan `ledcWrite` dan `delay` untuk efek perlahan.

   - **Ulangi Loop:**
     - Setelah loop pertama dan kedua selesai, program kembali ke awal dan mengulangi prosesnya.


**5. Kesimpulan**

Program memberikan efek cahaya perlahan naik dan turun pada ketiga LED, menciptakan tampilan visual yang menarik. Program ini menggunakan satu saluran PWM untuk mengendalikan tiga LED, sehingga intensitas cahaya pada ketiganya akan sama karena saling berbagi saluran yang sama. Program ini dapat digunakan sebagai dasar untuk menciptakan efek pencahayaan yang berbeda pada beberapa LED dengan modifikasi tertentu.

<br></br>

