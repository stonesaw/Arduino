const int LED = 7;
const int BUTTON = 12;
const int BUTTON2 = 13;
int buttonState = 0;
int sw = 0; // �X�C�b�`�̏�Ԃ�ۑ����邽�߂̕ϐ�

// �ݒ�
void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

// ���C�����[�v
void loop() {
  if (digitalRead(BUTTON) == LOW)
    sw = 1; // BUTTON�������ꂽ
  else if (digitalRead(BUTTON2) == LOW)
    sw = 0; // BUTTON2�������ꂽ

  // sw�̏�Ԃɂ����LED��t���邩�ǂ��������߂�
  if (sw == 0)
    digitalWrite(LED, LOW);
  else
     digitalWrite(LED, HIGH);
}

// �v���O����4  DigitalButton2.ino : �ۑ�2