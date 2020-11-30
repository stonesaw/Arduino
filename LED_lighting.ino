const int LED = 13;

// 設定
void setup() {
    pinMode(LED, OUTPUT); // 13番のLEDを出力用に設定
}

// メインループ
void loop() {
    digitalWrite(LED, HIGH); // LEDをつける
    delay(500);              // 500ms待つ
    degitalWrite(LED, LOW);  // LEDを消す
    delay(500);              // 500ms待つ
}

// プログラム1  サンプルプログラム1 : 演習1,2 課題1
