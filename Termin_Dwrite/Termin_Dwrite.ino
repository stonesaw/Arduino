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
const int speakerPin = 10;
const int sensorPin = 0;
const int threshold = 80;
double d;

// 設定
void setup() {
  pinMode(speakerPin, OUTPUT);
  Serial.begin(9600);
}

// メインループ
void loop() {
  onPress();
}

// 距離の計算と音を鳴らす処理
void onPress() {
  int value = analogRead(sensorPin);
  int range = (6787 / (value - 3)) - 4;
  
  if (range < 10)
    d = 500000.0 / NOTE_C4;
  else if (range < 20)
    d = 500000.0 / NOTE_D4;
  else if (range < 30)
    d = 500000.0 / NOTE_E4;
  else if (range < 40)
    d = 500000.0 / NOTE_F4;
  else if (range < 50)
    d = 500000.0 / NOTE_G4;
  else if (range < 60)
    d = 500000.0 / NOTE_A4;
  else if (range < 70)
    d = 500000.0 / NOTE_B4;
  else if (range < 79)
    d = 500000.0 / NOTE_C5;
  else
    return;

  // Serial.println(d);

  for (int i = 0; i < 50; i++) {
    digitalWrite(speakerPin, LOW); // 音を止める
    delayMicroseconds(d); // d[ms]待つ dが変わることで音階が変わる
    digitalWrite(speakerPin, HIGH); // 音を鳴らす
    delayMicroseconds(d); // d[ms]待つ
  }
}

// プログラム6  Termin_Dwrite.ino : 課題3
