#include <ESP8266WiFi.h>

// seçenek değişkenleri
#define WIFI_CONNECT 1
#define WIFI_SCAN 2
#define ACTIVATE_FRONTEND 3
#define DISABLE_FRONTEND 4
#define HOTSPOT_MODE 5
#define NO_COMMUNICATE 6

void setup() {
  // ayarlar : serial protunu 115200'e bağladık ve RST ledini yazılabilir moda getirdik
  Serial.begin(115200);

  while (!Serial) {
    delay(1);
  }

  Serial.println();
  Serial.println();
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  //  seçenekleri listele
  Serial.println("1 = WİFİ BAĞLAN");
  Serial.println("2 = WİFİ TARA");
  Serial.println("3 = ARAYÜZÜ ETKİNLEŞTİR");
  Serial.println("4 = ARAYÜZÜ KAPAT");
  Serial.println("5 = WİFİ PAYLAŞ");
  Serial.println("6 = TÜM BAĞLANTILARI KES");

  // seçenek gönderilinceye kadar bekle
  while (!Serial.available()) {
    delay(1);
  }

  // seçenek gönderildiğinde işlem yap
  int choose = Serial.parseInt();

  if (choose) {
    // test
    Serial.print("you selected : ");
    Serial.println(choose);
    // test end

    switch (choose) {
      case WIFI_CONNECT:
        Serial.println("Wifi Bağlantı modu aktif.");
        break;

      case ACTIVATE_FRONTEND:
        Serial.println("Arayüz modu aktif.");
        break;

      case DISABLE_FRONTEND:
        Serial.println("Arayüz modu etkisizleştirildi.");
        break;

      case HOTSPOT_MODE:
        Serial.println("Wifi paylaşma modu aktif.");
        break;

      case NO_COMMUNICATE:
        Serial.println("Tüm bağlanıtlar kesildi başa dölüyüyor.");
        break;

      default:
        Serial.println("Geçersiz seçenek!");
    }
  }











}
