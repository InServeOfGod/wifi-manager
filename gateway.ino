#include "gateway.h"

String prepareHeader(void) {
  String buff;
  buff.reserve(128);  // this will prevent fragmentation of ram
  buff = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
  return buff;
}

String prepareIndex(void) {
  String buff;
  buff.reserve(256);
  buff = "<!DOCTYPE html><html><head><style type='text/css'>a {color: white} body{background: green}</style><title>hello world</title></head><body><a href='http://192.168.1.1'>go to modem gateway</a></body></html>";
  return buff;
}

void handleClients(void) {
  while (true) {
    WiFiClient _client = server.available();

    if (_client) {
      String web_page = prepareHeader() + prepareIndex();
      _client.println(web_page);

      Serial.println("A client is connected");

      /*while (_client.connected()) {
        if (_client.available()) {
          String req = _client.readStringUntil('\r');
          Serial.print(req);

          if (req.length() == 1 and req[0] == '\n') {
            String web_page = prepareHeader() + prepareIndex();
            _client.println(web_page);
          }
        }
        }*/
    }
  }

}
