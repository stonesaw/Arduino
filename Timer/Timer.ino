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
const int LED = 2;
const int BUTTON = 12;
const int speakerPin = 10;

const int set_sec = 3; // �^�C�}�[�̕b��
int sec = 0;           // �^�C�}�[�̌o�ߎ��Ԃ�ۑ����邽�߂̕ϐ�
int state = -1;        // �^�C�}�[�̏��

// �ݒ�
void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
  pinMode(speakerPin, OUTPUT);
  Serial.begin(9600);
}

// ���C�����[�v
void loop() {
  if (digitalRead(BUTTON) == LOW && state == -1) {
    sec = set_sec;
    state = 0;
  }

  // �^�C�}�[���X�^�[�g���Ă���Ƃ�
  if (state == 0) {
    digitalWrite(LED, HIGH); // LED��_�ł�����
    delay(500);
    digitalWrite(LED, LOW);
    delay(500);
    sec--; // ���Ԃ��J�E���g
    
    if (sec <= 0)
      state = 1; // �^�C�}�[�̏�Ԃ�炷��Ԃ�
  }

  // �^�C�}�[��0�̂Ƃ�
  if (state == 1) {
    tone(speakerPin, NOTE_G4, 200); // ����炷
    delay(400);
    if (digitalRead(BUTTON) == LOW) { // �{�^���������ꂽ��ŏ��̏�Ԃɖ߂�
      state = -1;
      delay(1000);
    }
  }
}

// �v���O����8  Timer.ino : ���p����2
