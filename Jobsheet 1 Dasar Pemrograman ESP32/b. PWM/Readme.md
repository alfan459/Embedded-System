# PWM 1
Program pertama akan digunakan untuk membuat blink dengan interval 100ms, 1 detik, 2 detik, dan 3 detik sekali.

**1. Alat dan Bahan**
1. ESP32             ==> 1 buah
2. LED               ==> 3 buah
3. Resistor 220 Ohm  ==> 3 buah


**2. Rangkaian**

![image](https://github.com/alfan459/Embedded-System/assets/54757609/8792b94b-a270-4b61-8a92-8e72fc0594f9)


**3. Program**

Program dapat dilihat pada folder berikut ini: <a href="https://github.com/alfan459/Embedded-System/tree/master/Jobsheet%201%20Dasar%20Pemrograman%20ESP32/a.%20GPIO/Blink%20100ms%2C%201%20detik%2C%202%20detik%2C%203%20detik"> Program </a>

**4. Hasil dan Pembahasan**

![GPIO 2](https://github.com/alfan459/Embedded-System/assets/54757609/741c77fd-f7b2-49c1-835a-f1b214b5d36a)

Untuk flowchart, bisa dilihat pada gambar di bawah ini:

![Flowchart1](https://github.com/alfan459/Embedded-System/assets/54757609/3062ca6a-98dd-441c-8fe5-7019fac6f825)

Pada skema rangkaian, terdapat 1 led dan 1 pushbutton. Untuk LED sendiri diatur menjadi output terhubung dengan GPIO5. Sedangkan pushbutton terhubung dengan GPIO4 sebagai input. Untuk mengatur perangkat agar menjadi input atau output, diatur dalam function setup. Lalu pada function loop digunakan untuk program utama yang akan berjalan secara terus menerus. Dimana program utamanya digunakan untuk menyalakan LED selama 100ms, lalu mematikan LED selama 1 detik. Menyalakan LED selama 1 detik, dan mematikannya selama 1 detik, lalu menyala selama 2 detik, dan mati selama 1 detik, dan kondisi terakhir adalah menyala selama 3 detik, lalu mati selama 1 detik. Setelah itu akan mengulang program dari awal yakni menyala selama 100ms.

![carbon](https://github.com/alfan459/Embedded-System/assets/54757609/97217843-b313-4168-93b0-679e96dc2050)


**5. Kesimpulan**

Dari praktikum ini, kita dapat mengetahui bahwa kita bisa mengatur LED dengan interval waktu tertentu menggunakan perintah delay().

<br></br>
