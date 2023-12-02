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


Untuk flowchart, bisa dilihat pada gambar di bawah ini:



**5. Kesimpulan**

Dari praktikum ini, kita dapat mengetahui bahwa kita bisa mengatur LED dengan interval waktu tertentu menggunakan perintah delay().

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


Untuk Flowchart bisa dilihat pada gambar dibawah ini:




**5. Kesimpulan**


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


Flowchart dapat dilihat pada gambar dibawah ini:



**5. Kesimpulan**


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

Flowchart dapat dilihat pada gambar dibawah ini:

**5. Kesimpulan**

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



**5. Kesimpulan**
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

**4. Hasil dan Pembahasan**


Untuk flowchart, bisa dilihat pada gambar di bawah ini:



**5. Kesimpulan**


<br></br>
