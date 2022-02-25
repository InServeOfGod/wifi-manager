/*
  ESP8266mod Wifi module
  Board : NodeMCU 1.0 (ESP 12-E Module)

  author : InServeOfGod
  languages : cpp
  encoding : utf-8
*/

#include "kernel.h"

void setup() {
  // ayarlar : serial protunu 115200'e bağladık ve RST ledini yazılabilir moda getirdik
  Serial.begin(115200);
  Serial.setDebugOutput(false);

  while (!Serial) {
    delay(1);
  }

  Serial.println();
  Serial.println();
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  //  seçenekleri listele
  getChoices();
}

void loop() {
  // seçenek gönderildiğinde işlem yap
  Serial.println("seçim : ");
  long choose = getNumberInput();

  // eğer girilen veri geçerli ise
  if (choose) {
    switch (choose) {
      case WIFI_CONNECT:
        // cihazı wifi bağlantı moduna geçir
        if (WiFi.mode(WIFI_STA)) {
          Serial.println("Wifi bağlantı modu aktif.");

          // daha önceden bağlantı kurulmuşsa bağlantıyı kapat
          wifiShutdown();

          // wifi ağına bağlanmaya çalış
          if (wifiConnect()) {
            wifiStatus();
          } else {
            Serial.println("Bu ağa bağlanılamıyor.");
          }
        } else {
          Serial.println("Wifi bağlantı moduna geçerken bir hata oluştu!");
        }

        break;

      case WIFI_DISCONNECT:
        wifiShutdown();
        digitalWrite(LED_BUILTIN, LOW);
        break;

      case WIFI_INFO:
        Serial.println("Wifi bilgileri paylaşılıyor...");
        wifiSettings();
        break;

      case WIFI_SCAN:
        Serial.println("wifi cihazları taranıyor...");
        break;

      case ACTIVATE_FRONTEND:
        Serial.println("Arayüz modu aktif.");
        break;

      case DISABLE_FRONTEND:
        Serial.println("Arayüz modu kapatıldı.");
        break;

      case AP_MODE:
        Serial.println("Wifi ulaşım noktası aktif.");
        break;

      default:
        Serial.println("Geçersiz seçenek!");
    }
  }
}
