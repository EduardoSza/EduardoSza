// Pinos dos Motores
int revEsquerda4 = 9;
int fwdEsquerda5 = 8;
int revDireita6 = 10;
int fwdDireita7 = 11;

// Pinos do Sensor Ultrassônico HC-SR04
int pinoTrig = 12;
int pinoEcho = 13;

long duracao, distancia;

void setup() {
  Serial.begin(9600);

  // Configuração dos pinos dos motores como saída
  pinMode(revEsquerda4, OUTPUT);
  pinMode(fwdEsquerda5, OUTPUT);
  pinMode(revDireita6, OUTPUT);
  pinMode(fwdDireita7, OUTPUT);

  // Configuração dos pinos do sensor ultrassônico
  pinMode(pinoTrig, OUTPUT);
  pinMode(pinoEcho, INPUT);
}

void loop() {
  digitalWrite(pinoTrig, LOW);
  delayMicroseconds(2);

  digitalWrite(pinoTrig, HIGH);
  delayMicroseconds(10);
  duracao = pulseIn(pinoEcho, HIGH);
  distancia = duracao / 58.2;
  delay(10);

  // Condição para ausência de obstáculos
  if (distancia > 20) {
    digitalWrite(fwdDireita7, HIGH);
    digitalWrite(revDireita6, LOW);
    digitalWrite(fwdEsquerda5, HIGH);
    digitalWrite(revEsquerda4, LOW);
  }

  // Condição para presença de obstáculos
  if (distancia < 20) {
    // Parar por um curto período
    digitalWrite(fwdDireita7, LOW);
    digitalWrite(revDireita6, LOW);
    digitalWrite(fwdEsquerda5, LOW);
    digitalWrite(revEsquerda4, LOW);
    delay(500);

    // Virar para a esquerda
    digitalWrite(fwdDireita7, LOW);
    digitalWrite(revDireita6, LOW);
    digitalWrite(fwdEsquerda5, HIGH);
    digitalWrite(revEsquerda4, LOW);
    delay(400);

    // Parar por um curto período
    digitalWrite(fwdDireita7, LOW);
    digitalWrite(revDireita6, LOW);
    digitalWrite(fwdEsquerda5, LOW);
    digitalWrite(revEsquerda4, LOW);
    delay(200);
  }
}