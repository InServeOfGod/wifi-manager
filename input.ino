#include "input.h"

void delayUntilInput(void) {
  while (!Serial.available()) {
    delay(1);
  }
}

String getStrInput(void) {
  delayUntilInput();
  String buff = Serial.readString();
  buff.replace("\n", "");
  return buff;
}

long getNumberInput(void) {
  return getStrInput().toInt();
}

void getChoices(void) {
  Serial.println("1 = WİFİ BAĞLAN");
  Serial.println("2 = WİFİ BAĞLANTISINI KAPAT");
  Serial.println("3 = WİFİ VE CİHAZ BİLGİLERİ");
  Serial.println("4 = TARAMA YAP");
  Serial.println("5 = ARAYÜZÜ ETKİNLEŞTİR");
  Serial.println("6 = ARAYÜZÜ KAPAT");
  Serial.println("7 = BAĞLANTI NOKTASINI ETKİNLEŞTİR");
  Serial.println("8 = BAĞLANTI NOKTASINI KAPAT");
  Serial.println("9 = BAĞLANTI NOKTASI VE CİHAZ BİLGİLERİ");
}
