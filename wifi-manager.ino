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
          Serial.println("Wifi bağlantı modu aktifleştiriliyor...");

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
        Serial.println("Ulaşım noktası aktifleştiriliyor...");

        if (apStart()) {
          Serial.println("Ulaşım noktası aktifleştirildi.");
        }

        break;

      case AP_MODE_DISABLE:
        apShutdown();
        break;

      case AP_INFO:
        Serial.println("Ulaşım noktası bilgileri paylaşılıyor...");
        apSettings();
        break;


      default:
        Serial.println("Geçersiz seçenek!");
    }
  }
}
