#include <WiFi.h>
#include <PubSubClient.h>
#include <WiFiClientSecure.h>  // Tambahkan library ini

// Kredensial WiFi
const char* ssid = "Hotspot";
const char* password = "123456789a";

// Broker HiveMQ Cloud
const char* mqtt_server = "222075b42a03470aac13ee2d9c9c4d6f.s1.eu.hivemq.cloud";
const int mqtt_port = 8883; // TLS (port aman)

// Kredensial MQTT
const char* mqtt_user = "hivemq.webclient.1743181817332";
const char* mqtt_password = "34oSBi$Lar&%:1OzEp8R";

WiFiClientSecure espClient;  // Gunakan TLS
PubSubClient client(espClient);

// Daftar nama, kelas, dan hobi acak
const char* names[] = {"Bayu", "Dewi", "Andi", "Siti", "Budi"};
const char* classes[] = {"TT-45-01", "TT-45-02", "TT-45-03", "TT-45-04", "TT-45-05"};
const char* hobbies[] = {"Memancing", "Membaca", "Bersepeda", "Berenang", "Bermain Musik"};

void setup_wifi() {
    Serial.println("Menghubungkan ke WiFi...");
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nTerhubung ke WiFi!");
}

void reconnect() {
    while (!client.connected()) {
        Serial.print("Menghubungkan ke MQTT...");
        if (client.connect("ESP32Client", mqtt_user, mqtt_password)) {
            Serial.println("Terhubung ke MQTT!");
        } else {
            Serial.print("Gagal, rc=");
            Serial.print(client.state());
            Serial.println(" Coba lagi dalam 5 detik");
            delay(5000);
        }
    }
}

// Fungsi untuk menghasilkan data acak
String generateRandomData() {
    String payload;
    payload += "NAMA: ";
    payload += names[random(0, 5)];  // Pilih nama acak dari daftar
    payload += "\nNIM: ";
    payload += String(random(1000, 9999));  // NIM acak antara 1000 dan 9999
    payload += "\nKELAS: ";
    payload += classes[random(0, 5)];  // Pilih kelas acak dari daftar
    payload += "\nHobi: ";
    payload += hobbies[random(0, 5)];  // Pilih hobi acak dari daftar
    return payload;
}

void setup() {
    Serial.begin(115200);
    setup_wifi();
    
    // Gunakan TLS tanpa verifikasi sertifikat (kurang aman, tapi lebih mudah)
    espClient.setInsecure();
    
    client.setServer(mqtt_server, mqtt_port);
}

void loop() {
    if (!client.connected()) {
        reconnect();
    }
    client.loop();
    
    // Mengirim data acak setiap 5 detik dengan QoS 2
    String payload = generateRandomData();
    client.publish("Data/Mahasiswa", (const uint8_t*)payload.c_str(), payload.length(), true);  // QoS 2 (retained: true)
    
    Serial.println("Data terkirim:");
    Serial.println(payload);  // Tampilkan data yang dikirim di Serial Monitor
    delay(5000); // Tunggu 5 detik sebelum mengirim data berikutnya
}
