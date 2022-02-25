#include <ESP8266WiFi.h>
#include "input.h"
#include "station.h"

// seçenek değişkenleri
#define WIFI_CONNECT 1
#define WIFI_DISCONNECT 2
#define WIFI_INFO 3
#define WIFI_SCAN 4
#define ACTIVATE_FRONTEND 5
#define DISABLE_FRONTEND 6
#define AP_MODE 7
#define AP_MODE_DISABLE 8
#define AP_INFO 9
