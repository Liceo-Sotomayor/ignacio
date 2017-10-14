#define enableA  10
#define pinA1 2
#define pinA2 3
//Motor B
#define enableB 9
#define pinB1 4
#define pinB2 5
const int sensor1 = 11;
const int sensor2 = 12;
const int sensor3 = 6;
int historia[5][3];

void setup() {
  pinMode (enableA, OUTPUT);
  pinMode (pinA1, OUTPUT);
  pinMode (pinA2, OUTPUT);
  pinMode (enableB, OUTPUT);
  pinMode (pinB1, OUTPUT);
  pinMode (pinB2, OUTPUT);
  pinMode(sensor1 , INPUT);
  pinMode(sensor2 , INPUT);
  pinMode(sensor3 , INPUT);
}

void agregarMedida(int derecha, int centro, int izquierda) {
  for (int i = 3; i >= 0; i--) {
    historia[i+1][0] = historia[i][0];
    historia[i+1][1] = historia[i][1];
    historia[i+1][2] = historia[i][2]; 
  }
  historia[0][0] = derecha;
  historia[0][1] = centro;
  historia[0][2] = izquierda;
}

void definirSentidoA(int sentido){
  //Prendiendo el motor si el sentido es diferente a 0
  if (sentido == 0) {
    digitalWrite (enableA, LOW);
  } else {
    digitalWrite (enableA, HIGH);
  }

  //Definiendo el sentido en base al potencial de los pines
  if (sentido > 0) {
    digitalWrite (pinA1, HIGH);
    digitalWrite (pinA2, LOW); 
  }
  if (sentido < 0) {
    digitalWrite (pinA1, LOW);
    digitalWrite (pinA2, HIGH);
  }   
}

void definirSentidoB(int sentido){
  //Prendiendo el motor si el sentido es diferente a 0
  if (sentido == 0) {
    digitalWrite (enableB, LOW);
  } else {
    digitalWrite (enableB, HIGH);
  }

  //Definiendo el sentido en base al potencial de los pines
  if (sentido > 0) {
    digitalWrite (pinB1, HIGH);
    digitalWrite (pinB2, LOW); 
  }
  if (sentido < 0) {
    digitalWrite (pinB1, LOW);
    digitalWrite (pinB2, HIGH);
  }   
}

int calcularSentido(int fila) {
  return (historia[0][fila] + historia[1][fila] + historia[2][fila]) / 3;
}

void loop() {
  agregarMedida(digitalRead(sensor1), digitalRead(sensor2), digitalRead(sensor3));
  definirSentidoA(calcularSentido(0));
  definirSentidoB(calcularSentido(2));
}
