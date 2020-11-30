// ���K�̒�` (���g��)
#define NOTE_C4 262
#define NOTE_D4 294
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_B4 492
#define NOTE_C5 523

// �s���̃|�[�g
const int speakerPin = 10;
const int sensorPin = 0;
const int threshold = 80;
double d;

// �ݒ�
void setup() {
  pinMode(speakerPin, OUTPUT);
  Serial.begin(9600);
}

// ���C�����[�v
void loop() {
  onPress();
}

// �����̌v�Z�Ɖ���炷����
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
    digitalWrite(speakerPin, LOW); // �����~�߂�
    delayMicroseconds(d); // d[ms]�҂� d���ς�邱�Ƃŉ��K���ς��
    digitalWrite(speakerPin, HIGH); // ����炷
    delayMicroseconds(d); // d[ms]�҂�
  }
}

// �v���O����6  Termin_Dwrite.ino : �ۑ�3
