🌐 ESP32 MQTT Data Sender

👋 Perkenalan

Halo! 👋
Saya Bayu Lesmana, pengembang proyek ini, sebuah aplikasi yang menggunakan ESP32 untuk mengirim data mahasiswa melalui protokol MQTT ke broker HiveMQ Cloud. Proyek ini dibuat sebagai bagian dari pembelajaran saya dalam pengembangan IoT dan pemrograman jaringan.

⸻

📡 Fitur Utama

Berikut beberapa fitur utama dalam proyek ESP32 MQTT Data Sender:

📶 Koneksi WiFi
	•	Menghubungkan ESP32 ke jaringan WiFi yang tersedia.

🔒 Koneksi MQTT
	•	Menggunakan protokol MQTT untuk mengirim data secara real-time.
	•	Terhubung ke broker HiveMQ Cloud dengan dukungan TLS untuk keamanan data.

📊 Pengiriman Data
	•	Mengirim data mahasiswa ke topik Data/Mahasiswa.
	•	Data yang dikirim mencakup:
	•	NAMA: Bayu
	•	NIM: 11
	•	KELAS: TT-45-03
	•	Hobi: Memancing

⸻

🛠️ Teknologi yang Digunakan
	•	ESP32 (Microcontroller)
	•	Arduino IDE (Development Environment)
	•	PubSubClient (Library untuk MQTT)
	•	WiFi (Library untuk koneksi jaringan)


⸻

🚀 Cara Menjalankan Proyek Ini
	1.	Clone repository:

    ```bash 
    git clone https://github.com/[username]/esp32-mqtt-data-sender.git 
    cd esp32-mqtt-data-sender
    
   '''
	2.	Instal library yang diperlukan di Arduino IDE:
	•	Cari dan instal PubSubClient oleh Nick O’Leary melalui Library Manager.
	3.	Ganti kredensial di dalam kode:
	•	const char* ssid: Nama WiFi Anda.
	•	const char* password: Password WiFi Anda.
	•	const char* mqtt_user: Username dari akun HiveMQ Cloud Anda.
	•	const char* mqtt_password: Password dari akun HiveMQ Cloud Anda.
	4.	Unggah kode ke ESP32 melalui Arduino IDE.

📸 Screenshot

Berikut adalah contoh kode yang digunakan dalam proyek ini:

![Screenshot 2025-03-28 104413](https://github.com/user-attachments/assets/8a5367eb-2023-41b3-9366-538d6ec50660)


<img width="1437" alt="Screenshot 2025-03-29 at 00 52 24" src="https://github.com/user-attachments/assets/6b65ecd7-a841-4887-84ec-efbd30795a1e" />

🙏 Terima Kasih

Terima kasih telah mengunjungi repository ini!
Jangan lupa untuk ⭐ star jika kamu suka dengan proyek ini atau ingin belajar bersama.
Saran, kritik, atau kontribusi sangat diterima!

🧑‍💻 Developer

Bayu Lesmana
Email: bayul769@gmail.com
GitHub: @bayuish



