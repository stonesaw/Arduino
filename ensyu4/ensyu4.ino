const int LED = 7;
const int BUTTON = 12;
int buttonState = 0;

// 設定
void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

// メインループ
void loop() {
  buttonState = digitalRead(BUTTON);

  // ボタンが押されるとLEDを付ける
  if (buttonState == LOW)
    digitalWrite(LED, HIGH);
  else
     digitalWrite(LED, LOW);
}

// プログラム3  サンプルプログラム2 DigiralButton.ino : 演習4
