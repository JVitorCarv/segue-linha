//Definição dos pinos de controle do motor
#define M1A 8 // Pino_Velocidade 1º Motor ( 0 a 255)_ Porta ATV_A ponte H;
#define M1B 9 //Pino_Velocidade 2º Motor ( 0 a 255) _ Porta ATV_B ponte H;
#define M2A 10 //Pino_Direção do 1º Motor: Para frente / Para trás (HIGH ou LOW)_ porta IN1 ponte H;
#define M2B 11 //Pino_Direção do 2º Motor: Para frente / Para trás (HIGH ou LOW)_ porta IN3 ponte H;
//Definição dos pinos dos sensores
#define pin_S1 7
#define pin_S2 6
bool Sensor1 = 0;
bool Sensor2 = 0;
//variável responsável por controlar a velocidade dos motores
int velocidade = 254;
void setup(){
  //Setamos os pinos de controle dos motores como saída
  pinMode(M1A, OUTPUT);
  pinMode(M1B, OUTPUT);
  pinMode(M2A, OUTPUT);
  pinMode(M2B, OUTPUT);
  //Setamos a direção inicial do motor como 0, isso fará com que ambos os motores girem para frente
  digitalWrite(M1A, LOW);
  digitalWrite(M1B, LOW);
  digitalWrite(M2A, LOW);
  digitalWrite(M2B, LOW);

  //Setamos os pinos dos sensores como entrada
  pinMode(pin_S1, INPUT);
  pinMode(pin_S2, INPUT);
}
void loop(){
   //Neste processo armazenamos o valor lido pelo sensor na variável que armazena tais dados.
  Sensor1 = digitalRead(pin_S1);
  Sensor2 = digitalRead(pin_S2);
  analogWrite(M1A, velocidade); // Ambos motores ligam na mesma velocidade
  analogWrite(M2A, velocidade);
  delay(2000);
  analogWrite(M1A, velocidade); // Ambos motores ligam na mesma velocidade
  digitalWrite(M2A, LOW);
  delay(2000);
  analogWrite(M2A, velocidade); // Ambos motores ligam na mesma velocidade
  digitalWrite(M1A, LOW);
  delay(2000);
  analogWrite(M1A, velocidade); // Ambos motores ligam na mesma velocidade
  analogWrite(M2A, velocidade);
  delay(2000);
  analogWrite(M1B, velocidade); // Ambos motores ligam na mesma velocidade
  analogWrite(M2B, velocidade);
  digitalWrite(M1A, LOW);
  digitalWrite(M2A, LOW);
  delay(2000);
  digitalWrite(M1A, LOW);
  digitalWrite(M2A, LOW);
  digitalWrite(M1B, LOW);
  digitalWrite(M2B, LOW);
  delay(2000);
  


  //Aqui está toda a lógica de comportamento do robô: Para a cor branca atribuímos o valor 0 e, para a cor preta, o valor 1.
//  if((Sensor1 == 0) && (Sensor2 == 0)){ // Se detectar na extremidade das faixas duas cores brancas
//    analogWrite(M1, velocidade); // Ambos motores ligam na mesma velocidade
//    analogWrite(M2, velocidade);
//    }
//  if((Sensor1 == 1) && (Sensor2 == 0)){ // Se detectar um lado preto e o outro branco
//    analogWrite(M1, 0); // O motor 1 desliga
//    analogWrite(M2, velocidade); // O motor 2 fica ligado, fazendo assim o carrinho virar
//  }
//  if((Sensor1 == 0) && (Sensor2 == 1)){ // Se detectar um lado branco e o outro preto
//    analogWrite(M1, velocidade); //O motor 1 fica ligado
//    analogWrite(M2, 0); // O motor 2 desliga, fazendo assim o carrinho virar no outro sentido
//  }
}
