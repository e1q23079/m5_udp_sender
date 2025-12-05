# M5 UDP Sender

M5Stack デバイス用のシンプルなUDP送信プログラムです。ボタンを押すと指定したIPアドレスとポートにUDPパケットを送信します。

## 概要

このプロジェクトは、M5Stick-C を使用してWiFi経由でUDPパケットを送信するシンプルなアプリケーションです。ボタンAを押すと、指定されたサーバーに文字 '1' を送信します。

## ハードウェア要件

- M5Stick-C

## ソフトウェア要件

- [PlatformIO](https://platformio.org/)
- M5Unified ライブラリ (v0.2.7以降)

## セットアップ

### 1. WiFi設定

`src/main.cpp` の以下の部分を、使用するWiFiネットワークの情報に変更してください:

```cpp
const char SSID[] = "sample";
const char PASSWORD[] = "samplePassword";
```

### 2. UDP送信先設定

UDPパケットの送信先IPアドレスとポートを設定してください:

```cpp
const char ip[] = "192.168.4.1";
const int port = 3000;
```

## ビルドとアップロード

PlatformIOを使用してビルドとアップロードを行います。

```bash
# ビルド
pio run

# アップロード
pio run --target upload
```

または、VS Code の PlatformIO 拡張機能を使用してビルド・アップロードできます。

## 使用方法

1. デバイスの電源を入れます
2. 画面に "sender" と表示され、WiFi接続が完了すると "connected" と表示されます
3. ボタンA (M5Stick-Cの大きなボタン) を押すと、設定したサーバーにUDPパケット ('1') が送信されます

## プロジェクト構成

```
.
├── platformio.ini      # PlatformIO設定ファイル
├── src/
│   └── main.cpp       # メインプログラム
├── include/           # ヘッダーファイル
├── lib/               # プライベートライブラリ
└── test/              # テストコード
```
