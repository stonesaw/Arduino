const int LED = 13;

// �ݒ�
void setup() {
    pinMode(LED, OUTPUT); // 13�Ԃ�LED���o�͗p�ɐݒ�
}

// ���C�����[�v
void loop() {
    digitalWrite(LED, HIGH); // LED������
    delay(500);              // 500ms�҂�
    degitalWrite(LED, LOW);  // LED������
    delay(500);              // 500ms�҂�
}

// �v���O����1  �T���v���v���O����1 : ���K1,2 �ۑ�1
