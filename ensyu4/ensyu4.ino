const int LED = 7;
const int BUTTON = 12;
int buttonState = 0;

// �ݒ�
void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

// ���C�����[�v
void loop() {
  buttonState = digitalRead(BUTTON);

  // �{�^������������LED��t����
  if (buttonState == LOW)
    digitalWrite(LED, HIGH);
  else
     digitalWrite(LED, LOW);
}

// �v���O����3  �T���v���v���O����2 DigiralButton.ino : ���K4
