# GPIO 1
Program pertama akan digunakan untuk membuat blink dengan interval 100ms, 1 detik, 2 detik, dan 3 detik sekali.

**1. Alat dan Bahan**
1. ESP32             ==> 1 buah
2. LED               ==> 1 buah
3. Resistor 220 Ohm  ==> 1 buah
4. Resistor 10k Ohm  ==> 1 buah
5. Push button       ==> 1 buah


**2. Rangkaian**

![image](https://github.com/alfan459/Embedded-System/assets/54757609/4850f38f-859e-461b-a830-cd9b53a8e40e)


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

# GPIO 2
Program pertama akan digunakan untuk membuat blink 1 detik sekali menggunakan timer milis().

**1. Alat dan Bahan**
1. ESP32             ==> 1 buah
2. LED               ==> 1 buah
3. Resistor 220 Ohm  ==> 1 buah
4. Resistor 10k Ohm  ==> 1 buah
5. Push button       ==> 1 buah


**2. Rangkaian**

![image](https://github.com/alfan459/Embedded-System/assets/54757609/4850f38f-859e-461b-a830-cd9b53a8e40e)


**3. Program**

Program dapat dilihat pada folder berikut ini: <a href="https://github.com/alfan459/Embedded-System/tree/master/Jobsheet%201%20Dasar%20Pemrograman%20ESP32/a.%20GPIO/Blink%20dengan%20Millis"> Program </a>

**4. Hasil dan Pembahasan**

![GPIO 1](https://github.com/alfan459/Embedded-System/assets/54757609/d6d24241-0add-4543-a049-e1a800bf9378)

Untuk Flowchart bisa dilihat pada gambar dibawah ini:

![Flowchart2](https://github.com/alfan459/Embedded-System/assets/54757609/28954bd9-7499-47e5-b546-ec70c1f35ab9)


Program ini dibuat untuk mengendalikan LED sehingga LED akan berkedip setiap 1 detik. Program ini menggunakan metode non-blocking dengan `millis()`, yang memungkinkan Arduino untuk terus menjalankan instruksi di `loop()` tanpa harus menunggu. Beberapa variable yang digunakan adalah
   - `ledPin`: Mendefinisikan pin yang digunakan untuk menghubungkan LED (GPIO 5).
   - `ledState`: Variabel yang menunjukkan keadaan LED (HIGH atau LOW).
   - `previousMillis`: Menyimpan waktu terakhir LED berubah keadaan.
   - `interval`: Menyimpan interval waktu (dalam milidetik) untuk nge-blink LED (1000 ms atau 1 detik).

Di dalam `setup()`, `ledPin` diatur sebagai OUTPUT menggunakan `pinMode()`, sehingga Arduino tahu bahwa pin tersebut digunakan untuk mengontrol LED.
Di dalam `loop()`, pertama-tama kita mendapatkan nilai `currentMillis` menggunakan `millis()`. `currentMillis` akan menyimpan waktu saat ini sejak Arduino dihidupkan. Selanjutnya, program memeriksa apakah selisih waktu antara `currentMillis` dan `previousMillis` lebih besar atau sama dengan `interval` (1 detik). Ini berfungsi sebagai mekanisme waktu untuk mengubah keadaan LED. Jika selisih waktu sudah mencapai atau melebihi `interval`, maka `previousMillis` diperbarui dengan `currentMillis`. Kemudian, program memeriksa keadaan `ledState`. Jika `ledState` adalah LOW (mati), maka akan diubah menjadi HIGH (nyala), dan sebaliknya. Terakhir, menggunakan `digitalWrite()`, LED akan diatur sesuai dengan nilai `ledState`. Ini akan membuat LED berkedip (nyala-mati) dengan interval 1 detik.

![carbon (1)](https://github.com/alfan459/Embedded-System/assets/54757609/ce34b0e2-bd7c-4c2d-b6cf-499ff547da11)


**5. Kesimpulan**

Program ini menciptakan efek berkedip pada LED dengan menggunakan fungsi `millis()` untuk menghindari ketergantungan waktu (blocking) dan memungkinkan Arduino menjalankan tugas lainnya tanpa harus menunggu.


<br></br>

# GPIO 3
Program pertama akan digunakan untuk mengendalikan LED menggunakan push button.

**1. Alat dan Bahan**
1. ESP32             ==> 1 buah
2. LED               ==> 1 buah
3. Resistor 220 Ohm  ==> 1 buah
4. Resistor 10k Ohm  ==> 1 buah
5. Push button       ==> 1 buah


**2. Rangkaian**

![image](https://github.com/alfan459/Embedded-System/assets/54757609/4850f38f-859e-461b-a830-cd9b53a8e40e)


**3. Program**

Program dapat dilihat pada folder berikut ini: <a href="https://github.com/alfan459/Embedded-System/tree/master/Jobsheet%201%20Dasar%20Pemrograman%20ESP32/a.%20GPIO/Program%20Contoh"> Program </a>

**4. Hasil dan Pembahasan**

![GPIO 3](https://github.com/alfan459/Embedded-System/assets/54757609/ea07038b-8f00-4882-8bbf-3fa435e164d7)

Flowchart dapat dilihat pada gambar dibawah ini:

![Flowchart3](https://github.com/alfan459/Embedded-System/assets/54757609/e2f8bf50-de43-4b2e-b198-aa04fa0019ef)


Program ini dimulai dengan mendefinisikan pin yang akan digunakan untuk tombol (button1 dan button2) dan LED (led1 dan led2) menggunakan konstanta `const`. Variabel `buttonState1` dan `buttonState2` digunakan untuk menyimpan keadaan (HIGH atau LOW) dari tombol 1 dan tombol 2.

Dalam blok `setup()`, program melakukan inisialisasi pin menggunakan `pinMode`. `button1` dan `button2` diatur sebagai input (untuk membaca tombol), sedangkan `led1` dan `led2` diatur sebagai output (untuk mengendalikan LED).

Dalam blok `loop()`, program terus berjalan secara berulang. 
   - Program membaca keadaan tombol 1 dengan `digitalRead(button1)` dan menyimpannya dalam variabel `buttonState1`. Keadaan tombol ini kemudian diperiksa dalam kondisi berikut:
   - Jika tombol 1 ditekan (keadaan HIGH), maka program akan menghidupkan LED 1 dengan `digitalWrite(led1, HIGH)`.
   - Jika tombol 1 tidak ditekan (keadaan LOW), maka program akan mematikan LED 1 dengan `digitalWrite(led1, LOW)`.
   - Program juga membaca keadaan tombol 2 dengan `digitalRead(button2)` dan menyimpannya dalam variabel `buttonState2`. Keadaan tombol ini kemudian diperiksa dalam kondisi berikut:
   - Jika tombol 2 ditekan (keadaan HIGH), maka program akan menghidupkan LED 2 dengan `digitalWrite(led2, HIGH)`.
   - Jika tombol 2 tidak ditekan (keadaan LOW), maka program tidak melakukan apa-apa terhadap LED 2.

**5. Kesimpulan**

Dengan demikian, program ini mengendalikan dua LED (led1 dan led2) dengan dua tombol (button1 dan button2). Ketika tombol 1 ditekan, LED 1 akan menyala, dan ketika tombol 2 ditekan, LED 2 akan menyala. Program akan terus berjalan dalam loop dan memeriksa keadaan tombol serta mengendalikan LED sesuai dengan input dari tombol.

<br></br>

# GPIO 4
Program pertama akan digunakan untuk mengendalikan LED agar blink setiap 500 ms ketika push button ke-2 ditekan.

**1. Alat dan Bahan**
1. ESP32             ==> 1 buah
2. LED               ==> 2 buah
3. Resistor 220 Ohm  ==> 1 buah
4. Resistor 10k Ohm  ==> 1 buah
5. Push button       ==> 2 buah


**2. Rangkaian**
![Rangkaian GPIO 4](https://github.com/alfan459/Embedded-System/assets/54757609/389106d1-e4a8-41c3-8bed-ea941e62d3db)


**3. Program**

Program dapat dilihat pada folder berikut ini: <a href="https://github.com/alfan459/Embedded-System/tree/master/Jobsheet%201%20Dasar%20Pemrograman%20ESP32/a.%20GPIO/Blink%20500ms%202%20led%202%20button"> Program </a>

**4. Hasil dan Pembahasan**

![GPIO 4](https://github.com/alfan459/Embedded-System/assets/54757609/5c06b0e8-8ff4-441a-baa4-7ff00b3c4a38)

Tambahkan flowchart, untuk keterangan programnya bisa dilihatpada program terlampir.

**4. Kesimpulan**

Dari praktikum ini, kita dapat mengetahui bahwa kita bisa mengatur LED

<br></br>

# GPIO 5
Program pertama akan digunakan untuk membuat LED menyala bergantian dari kiri ke kanan ketika push button ke-3 ditekan.

**1. Alat dan Bahan**
1. ESP32             ==> 1 buah
2. LED               ==> 5 buah
3. Resistor 220 Ohm  ==> 1 buah
4. Resistor 10k Ohm  ==> 1 buah
5. Push button       ==> 3 buah


**2. Rangkaian**
![Rangkaian GPIO 5](https://github.com/alfan459/Embedded-System/assets/54757609/81dfe4c2-b0fe-4576-8de2-ab5ee3ced849)


**3. Program**

Program dapat dilihat pada folder berikut ini: <a href="https://github.com/alfan459/Embedded-System/tree/master/Jobsheet%201%20Dasar%20Pemrograman%20ESP32/a.%20GPIO/Running%20Led"> Program </a>

**4. Hasil dan Pembahasan**

![GPIO 5](https://github.com/alfan459/Embedded-System/assets/54757609/e9fa7683-f447-4b10-9758-9ef9b0d55a98)

Tambahkan flowchart, untuk keterangan programnya bisa dilihatpada program terlampir.

**5. Kesimpulan**

Dari praktikum ini, kita dapat mengetahui bahwa kita bisa mengatur LED
