#include <Arduino.h>
#include <M5Unified.h>
#include <WiFi.h>
#include <WiFiUdp.h>

const char SSID[] = "sample";
const char PASSWORD[] = "samplePassword";

const char ip[] = "192.168.4.1";
const int port = 3000;

// UDP設定
WiFiUDP wifiudp;

void setup() {
    // セットアップ
    auto cfg = M5.config();
    M5.begin(cfg);

    // 画面
    M5.Display.setRotation(1);
    M5.Display.setTextSize(2);
    M5.Display.println("sender");

    WiFi.begin(SSID, PASSWORD);
    while (WiFi.status() != WL_CONNECTED) {
    }
    M5.Display.println("connected");
}

void loop() {
    M5.update();
    if (M5.BtnA.wasPressed()) {
        wifiudp.beginPacket(ip, port);
        wifiudp.write('1');
        wifiudp.endPacket();
    }
}