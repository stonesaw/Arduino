// ピンのポート
const int LED[7] = { 8, 7, 6, 5, 4, 3, 2};
const int BUTTON = 12;

const int seed = 0; // 変数のシード値
int r = 0; // random()で取得した値を入れるための変数

// サイコロの出た目によって光る位置を変えるための配列
int light[6][6] = {
  {7},                // サイコロの目が1のとき
  {2, 5},             // サイコロの目が2のとき
  {2, 7, 5},          //        .
  {1, 3, 4, 6},       //        .
  {1, 3, 4, 6, 7},    //        .
  {1, 2, 3, 4, 5, 6}
};

// 設定
void setup() {
  randomSeed(analogRead(seed));
  for (int i = 0; i < 7; i++)
    pinMode(LED[i], OUTPUT);
  pinMode(BUTTON, INPUT);
  Serial.begin(9600);
}

// メインループ
void loop() {
  if (digitalRead(BUTTON) == LOW) {
    for (int i = 0; i < 7; i++)
      digitalWrite(LED[i], LOW); // 全てのLEDを消す
    
    r = random(0, 6); // 0 ~ 5 の乱数
    
    // 出た目のLEDを光らせる
    for (int i = 0; i < 6; i++) {
      if (light[r][i] != 0)
        digitalWrite(LED[light[r][i] - 1], HIGH);
    }
  }
}

// プログラム7  Dice.ino : 応用実験1
