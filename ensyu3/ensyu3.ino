// �s���̃|�[�g��z��ɓ���Ă���
const int LED[7] = { 8, 7, 6, 5, 4, 3, 2};

// �ݒ�
void setup() {
  for (int i = 0; i < 7; i++)
    pinMode(LED[i], OUTPUT); // �s���̐ݒ�
}

// ���C�����[�v
void loop() {
  for (int i = 0; i < 7; i++)
    digitalWrite(LED[i], HIGH); // �S�Ă�LEd��t����
  delay(500);                   // 500ms�҂�
  for (int i = 0; i < 7; i++)
    digitalWrite(LED[i], LOW);  // �S�Ă�LED������
  delay(500);                   // 500ms�҂�
}

// �v���O����2  LED�̂��ׂĂ�_�ł�����v���O���� : ���K3
