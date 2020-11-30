// ピンのポートを配列に入れておく
const int LED[7] = { 8, 7, 6, 5, 4, 3, 2};

// 設定
void setup() {
  for (int i = 0; i < 7; i++)
    pinMode(LED[i], OUTPUT); // ピンの設定
}

// メインループ
void loop() {
  for (int i = 0; i < 7; i++)
    digitalWrite(LED[i], HIGH); // 全てのLEdを付ける
  delay(500);                   // 500ms待つ
  for (int i = 0; i < 7; i++)
    digitalWrite(LED[i], LOW);  // 全てのLEDを消す
  delay(500);                   // 500ms待つ
}

// プログラム2  LEDのすべてを点滅させるプログラム : 演習3
