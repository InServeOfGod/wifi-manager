/*
  ESP8266mod Wifi module
  Board : NodeMCU 1.0 (ESP 12-E Module)

  author : InServeOfGod
  languages : cpp
  encoding : utf-8
*/

#include "kernel.h"

#define MOD_EXCEPTION "Wifi bağlantı moduna geçilirken bir hata oluştu."

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
          Serial.println(MOD_EXCEPTION);
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
        Serial.print("wifi cihazları taranıyor");
        // cihazı wifi bağlantı moduna geçir
        if (WiFi.mode(WIFI_STA)) {
          WiFi.disconnect();
          delay(100);
          WiFi.scanNetworks(true, true);
          wifiScanner();
        } else {
          Serial.println(MOD_EXCEPTION);
        }

        break;

      case ACTIVATE_FRONTEND:
        // TEST SECTION DELETE THIS LATER
        WiFi.begin("Kat4_1", "LHH13251");

        while (WiFi.status() != WL_CONNECTED) {
          Serial.print(".");
          delay(500);
        }

        // TEST SECTION

        if (WiFi.status() == WL_CONNECTED) {
          server.begin();

          Serial.println("Arayüz modu aktif.");
          Serial.println("Lütfen sistemi arayüz üzerinden yönetin.");
          Serial.print("Arayüz IP : ");
          Serial.println(WiFi.localIP());
          handleClients();
        }

        else {
          Serial.println("Arayüz modu aktifleştirilemedi! Bir wifi ağına bağlanmayı deneyin.");
        }

        break;

      case DISABLE_FRONTEND:
        server.stop();
        Serial.println("Arayüz modu kapatıldı.");
        break;

      case AP_MODE:
        Serial.println("Ulaşım noktası aktifleştiriliyor...");

        if (WiFi.mode(WIFI_AP)) {
          if (apStart()) {
            Serial.println("Ulaşım noktası aktifleştirildi.");
          }
        } else {
          Serial.println("Wifi ulaşım noktası moduna geçilirken bir hata oluştu.");
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
