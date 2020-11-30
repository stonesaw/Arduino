const int LED = 7;
const int BUTTON = 12;
const int BUTTON2 = 13;
int buttonState = 0;
int sw = 0; // スイッチの状態を保存するための変数

// 設定
void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

// メインループ
void loop() {
  if (digitalRead(BUTTON) == LOW)
    sw = 1; // BUTTONが押された
  else if (digitalRead(BUTTON2) == LOW)
    sw = 0; // BUTTON2が押された

  // swの状態によってLEDを付けるかどうかを決める
  if (sw == 0)
    digitalWrite(LED, LOW);
  else
     digitalWrite(LED, HIGH);
}

// プログラム4  DigitalButton2.ino : 課題2