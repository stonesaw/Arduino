// 音階の定義 (周波数)
#define NOTE_C4 262
#define NOTE_D4 294
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_B4 492
#define NOTE_C5 523

// ピンのポート
const int LED = 2;
const int BUTTON = 12;
const int speakerPin = 10;

const int set_sec = 3; // タイマーの秒数
int sec = 0;           // タイマーの経過時間を保存するための変数
int state = -1;        // タイマーの状態

// 設定
void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
  pinMode(speakerPin, OUTPUT);
  Serial.begin(9600);
}

// メインループ
void loop() {
  if (digitalRead(BUTTON) == LOW && state == -1) {
    sec = set_sec;
    state = 0;
  }

  // タイマーがスタートしているとき
  if (state == 0) {
    digitalWrite(LED, HIGH); // LEDを点滅させる
    delay(500);
    digitalWrite(LED, LOW);
    delay(500);
    sec--; // 時間をカウント
    
    if (sec <= 0)
      state = 1; // タイマーの状態を鳴らす状態に
  }

  // タイマーが0のとき
  if (state == 1) {
    tone(speakerPin, NOTE_G4, 200); // 音を鳴らす
    delay(400);
    if (digitalRead(BUTTON) == LOW) { // ボタンが押されたら最初の状態に戻す
      state = -1;
      delay(1000);
    }
  }
}

// プログラム8  Timer.ino : 応用実験2
