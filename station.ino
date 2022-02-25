#include "station.h"

bool wifiConnect(void) {
  String essid, passwd;

  while (true) {
    Serial.println();
    Serial.print("wifi ismi girin : ");
    essid = getStrInput();

    if (essid.length() > 32 or essid.length() < 6) {
      Serial.println();
      Serial.println("wifi ismi en az 6, en çok 32 karakterden oluşmalıdır.");
    } else {
      break;
    }
  }

  while (true) {
    Serial.println();
    Serial.print("wifi şifresi girin : ");
    passwd = getStrInput();
    Serial.println();

    if (passwd.length() > 32 or passwd.length() < 8) {
      Serial.println();
      Serial.println("wifi şifresi en az 8, en çok 32 karakterden oluşmalıdır.");
    } else {
      break;
    }
  }

  return WiFi.begin(essid, passwd);
}

void wifiSettings(void) {
  if (WiFi.isConnected()) {
    Serial.print("MAC adresi : ");
    Serial.println(WiFi.macAddress());

    Serial.print("Yerel IP : ");
    Serial.println(WiFi.localIP());

    Serial.print("Alt ağlar : ");
    Serial.println(WiFi.subnetMask());

    Serial.print("Arayüz IP : ");
    Serial.println(WiFi.gatewayIP());

    Serial.print("DNS IP : ");
    Serial.println(WiFi.dnsIP());

    Serial.print("Host adı : ");
    Serial.println(WiFi.hostname());

    Serial.print("Durum : ");
    Serial.println("Bağlı");

    Serial.print("Wifi ismi (SSID) : ");
    Serial.println(WiFi.SSID());

    Serial.print("Şifre : ");
    Serial.println(WiFi.psk());

    Serial.print("Wifi MAC adresi (BSSID) : ");
    Serial.println(WiFi.BSSIDstr());

    Serial.printf("Bağlantı gücü : %d dBm\n", WiFi.RSSI());
  } else {
    Serial.println("Bağlantı yok!");
  }
}

void wifiShutdown(void) {
  if (WiFi.isConnected()) {
    WiFi.disconnect();
    Serial.println("Wifi bağlantısı kesildi.");
  }
}

void wifiStatus(void) {
  Serial.println("Wifi ağına bağlanılıyor");
  bool _loop = true;

  while (_loop) {
    switch (WiFi.status()) {
      case WL_CONNECTED:
        Serial.println("Wifi ağına bağlanıldı.");
        digitalWrite(LED_BUILTIN, HIGH);
        _loop = false;
        break;

      case WL_NO_SSID_AVAIL:
        Serial.println("Böyle bir wifi ismi yok!");
        _loop = false;
        break;

      case WL_CONNECT_FAILED:
        Serial.println("Bağlantı başarısız!");
        _loop = false;
        break;

      case WL_WRONG_PASSWORD:
        Serial.println("Yanlış şifre!");
        _loop = false;
        break;

      case WL_IDLE_STATUS:
        Serial.print(".");
        break;

      case WL_DISCONNECTED:
        Serial.print(".");
        break;

      case -1:
        Serial.println("Cihaz, bağlantı kurarken zaman aşımına uğradı!");
        _loop = false;
        break;

      default:
        Serial.println("Bilinmyen bir hata oluştu!");
        _loop = false;
    }

    digitalWrite(LED_BUILTIN, HIGH);
    delay(250);
    digitalWrite(LED_BUILTIN, LOW);
    delay(250);
  }
}
