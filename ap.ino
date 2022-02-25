#include "ap.h"

bool apStart(void) {
  String essid, passwd;
  long max_conn;

  while (true) {
    Serial.println();
    Serial.print("Bağlantı noktası ismi (SSID) girin : ");
    essid = getStrInput();

    if (essid.length() > 32 or essid.length() < 8) {
      Serial.println();
      Serial.println("Bağlantı noktası ismi en az 8, en çok 32 karakterden oluşmalıdır.");
    } else {
      break;
    }
  }

  while (true) {
    Serial.println();
    Serial.print("Bağlantı noktası şifresi girin : ");
    passwd = getStrInput();

    if (passwd.length() > 16 or passwd.length() < 8) {
      Serial.println("Bağlantı noktası şifresi en az 8, en çok 16 karakterden oluşmalıdır.");
    } else {
      break;
    }
  }

  while (true) {
    Serial.println();
    Serial.println("Şu kadar kullanıcı ağa bağlanabilsin (1~8) : ");
    max_conn = getNumberInput();

    if (max_conn < 1 or max_conn > 8) {
      Serial.println("Bağlantı noktasına en az 1, en fazla 8 kişi bağlanabilir!");
    } else {
      break;
    }
  }

  return WiFi.softAP(essid, passwd, 1, false, max_conn);
}

void apSettings(void) {
  Serial.println();
  Serial.print("Bağlanan kullanıcı sayısı : ");
  Serial.printf("%d", WiFi.softAPgetStationNum());
  Serial.println();

  Serial.print("Bağlantı noktası IP adresi : ");
  Serial.println(WiFi.softAPIP());

  Serial.print("Bağlantı noktası MAC adresi : ");
  Serial.println(WiFi.softAPmacAddress().c_str());
}

void apShutdown(void) {
  WiFi.softAPdisconnect(true);
}
