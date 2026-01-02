# Implementasi Kontrol PID Pada Sistem Ball Balancer

Proyek ini bertujuan untuk mengembangkan sistem **Ball Balancer** otomatis yang menjaga bola tetap di titik tengah bidang datar menggunakan algoritma kontrol **PID (Proportional-Integral-Derivative)**.

## 📋 Deskripsi Proyek
 Sistem ini menggunakan **Arduino Uno** sebagai otak utama untuk membaca posisi bola melalui **Sensor Ultrasonik HC-SR04**.  Berdasarkan data posisi tersebut, Arduino menghitung koreksi sudut yang diperlukan dan menggerakkan **Motor Servo** untuk memiringkan papan penyeimbang hingga bola kembali ke setpoint (tengah).

## 🔧 Komponen yang Digunakan
*  **Mikrokontroler:** Arduino Uno
*  **Sensor:** Ultrasonik HC-SR04
*  **Aktuator:** Motor Servo
*  **Software:** Arduino IDE & MATLAB (untuk visualisasi real-time)

## 📐 Konfigurasi PID
 Parameter PID yang digunakan dalam proyek ini adalah
- **Kp (Proportional):** 19
- **Ki (Integral):** 0.03
- **Kd (Derivative):** 15

## 🔌 Rangkaian Elektronik
*  **Sensor Ultrasonik:** Trig ke Pin 2, Echo ke Pin 3
*  **Motor Servo:** Sinyal PWM ke Pin 5
*  **Daya:** 5V dan GND dari Arduino

## 📊 Hasil Visualisasi
Proyek ini mengintegrasikan MATLAB untuk monitoring grafis.  Grafik menunjukkan hubungan antara pembacaan jarak (biru) dan respon sudut servo (merah) secara real-time.

---
👥 Tim Pengembang
Proyek ini merupakan hasil kerja kelompok sebagai bagian dari tugas besar mata kuliah Sistem Automasi di Program Studi Teknik Komputer.
