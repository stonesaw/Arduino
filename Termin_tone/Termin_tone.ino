// ドレミの音階 (周波数を設定)
#define NOTE_C4 262
#define NOTE_D4 294
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_B4 492
#define NOTE_C5 523

// ピンのポートを定義
const int speakerPin = 10;
const int sensorPin = 0;
const int threshold = 80;

// 設定
void setup() {
  pinMode(speakerPin, OUTPUT);
  Serial.begin(9600); // モニタ出力用の設定
}

// メインループ
void loop() {
  onPress();
  delay(10);
}

void onPress() {
  int value = analogRead(sensorPin);
  int range = (6787 / (value - 3)) - 4; // 受け取った値を距離[cm]に変換
  Serial.println(range);

  // センサとの距離によって鳴らす音の高さを変える
  if (range < 10)
    tone(speakerPin, NOTE_C4, 500);
  else if (range < 20)
    tone(speakerPin, NOTE_D4, 500);
  else if (range < 30)
    tone(speakerPin, NOTE_E4, 500);
  else if (range < 40)
    tone(speakerPin, NOTE_F4, 500);
  else if (range < 50)
    tone(speakerPin, NOTE_G4, 500);
  else if (range < 60)
    tone(speakerPin, NOTE_A4, 500);
  else if (range < 70)
    tone(speakerPin, NOTE_B4, 500);
  else if (range < 79)
    tone(speakerPin, NOTE_C5, 500);
}

// プログラム5  サンプルプログラム3 Termin_tone.ino : 演習5
