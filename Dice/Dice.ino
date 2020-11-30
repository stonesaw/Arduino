// �s���̃|�[�g
const int LED[7] = { 8, 7, 6, 5, 4, 3, 2};
const int BUTTON = 12;

const int seed = 0; // �ϐ��̃V�[�h�l
int r = 0; // random()�Ŏ擾�����l�����邽�߂̕ϐ�

// �T�C�R���̏o���ڂɂ���Č���ʒu��ς��邽�߂̔z��
int light[6][6] = {
  {7},                // �T�C�R���̖ڂ�1�̂Ƃ�
  {2, 5},             // �T�C�R���̖ڂ�2�̂Ƃ�
  {2, 7, 5},          //        .
  {1, 3, 4, 6},       //        .
  {1, 3, 4, 6, 7},    //        .
  {1, 2, 3, 4, 5, 6}
};

// �ݒ�
void setup() {
  randomSeed(analogRead(seed));
  for (int i = 0; i < 7; i++)
    pinMode(LED[i], OUTPUT);
  pinMode(BUTTON, INPUT);
  Serial.begin(9600);
}

// ���C�����[�v
void loop() {
  if (digitalRead(BUTTON) == LOW) {
    for (int i = 0; i < 7; i++)
      digitalWrite(LED[i], LOW); // �S�Ă�LED������
    
    r = random(0, 6); // 0 ~ 5 �̗���
    
    // �o���ڂ�LED�����点��
    for (int i = 0; i < 6; i++) {
      if (light[r][i] != 0)
        digitalWrite(LED[light[r][i] - 1], HIGH);
    }
  }
}

// �v���O����7  Dice.ino : ���p����1
