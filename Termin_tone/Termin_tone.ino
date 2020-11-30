// �h���~�̉��K (���g����ݒ�)
#define NOTE_C4 262
#define NOTE_D4 294
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_B4 492
#define NOTE_C5 523

// �s���̃|�[�g���`
const int speakerPin = 10;
const int sensorPin = 0;
const int threshold = 80;

// �ݒ�
void setup() {
  pinMode(speakerPin, OUTPUT);
  Serial.begin(9600); // ���j�^�o�͗p�̐ݒ�
}

// ���C�����[�v
void loop() {
  onPress();
  delay(10);
}

void onPress() {
  int value = analogRead(sensorPin);
  int range = (6787 / (value - 3)) - 4; // �󂯎�����l������[cm]�ɕϊ�
  Serial.println(range);

  // �Z���T�Ƃ̋����ɂ���Ė炷���̍�����ς���
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

// �v���O����5  �T���v���v���O����3 Termin_tone.ino : ���K5
