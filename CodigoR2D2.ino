#include <Servo.> //inclusão biblioteca servomotor

Servo myservo; //declaraçâo do servomotor que move a cabeça

int pos = 0; //declaracao pos como posição zero do servo motor

//declaração motores dos pés
int motorA1 = 4;
int motorA2 = 5;
int motorB1 = 6;
int motorB2 = 7;

//declaração led RGB da cabeça
int ledAzul = 9;      
int ledVerde = 10;   
int ledVermelho = 11; 

void setup() { 
//qualquer código que estiver no setup() é executado uma única vez no inicio do seu programa
//Essa função é utilizada para as configurações iniciais do arduino 

  myservo.attach(8);  // Definindo pino 8 do arduino como porta de sinal do servo
  
  //definindo variaveis dos motores como saída 
   pinMode(motorA1, OUTPUT);
   pinMode(motorA2, OUTPUT);
   pinMode(motorB1, OUTPUT);
   pinMode(motorB2, OUTPUT);

//definindo variaveis do led RGB como saida
   pinMode(ledAzul,OUTPUT);   
   pinMode(ledVerde,OUTPUT);   
   pinMode(ledVermelho,OUTPUT);
}



void loop(){ 
// a funçâo loop será executada para sempre ou até que seja feito 
//tudo o que está aqui entre {} será repetido 
  motor1();
  servo();
  motor2();
  servo();
  }

void motor1() {
//função criada para fazer o R2D2 andar para frente por 3 segungod e para por um segundo

 digitalWrite(ledVerde,HIGH);//acende o led RGB da cor verde

//movimento do motor A para frente
 digitalWrite(motorA1,HIGH);
 digitalWrite(motorA2,LOW);
//movimento do motor B para frente
 digitalWrite(motorB1,HIGH);
 digitalWrite(motorB2,LOW);
 delay(3000);//por 3 segundos
 
 digitalWrite(ledVerde,LOW);//apaga led RGB da cor verde
 delay(2);
 
 //led RGB
 digitalWrite(ledAzul,LOW);//acende a cor amarela
 digitalWrite(ledVerde,HIGH);
 digitalWrite(ledVermelho,HIGH);

 //Para os motores por 1 segundo
 digitalWrite(motorA1,LOW);
 digitalWrite(motorA2,LOW); 
 digitalWrite(motorB1,LOW);
 digitalWrite(motorB2,LOW);
 delay(1000);
 
//desliga o led rgb
 digitalWrite(ledAzul,LOW);
 digitalWrite(ledVerde,LOW);
 digitalWrite(ledVermelho,LOW);
 
 }

 
void motor2(){
//função criada para fazer o R2D2 andar para trás por 3 segungod e para por um segundo
 digitalWrite(ledVermelho,HIGH);
 digitalWrite(motorA1,LOW);
 digitalWrite(motorA2,HIGH);
 digitalWrite(motorB1,LOW);
 digitalWrite(motorB2,HIGH);
 delay(3000);

 digitalWrite(ledVermelho,LOW);
 delay(2);

 digitalWrite(ledAzul,LOW);
 digitalWrite(ledVerde,HIGH);
 digitalWrite(ledVermelho,HIGH);
 
 digitalWrite(motorA1,LOW);
 digitalWrite(motorA2,LOW);
 digitalWrite(motorB1,LOW);
 digitalWrite(motorB2,LOW);
 delay(1000); 

 digitalWrite(ledAzul,LOW);
 digitalWrite(ledVerde,LOW);
 digitalWrite(ledVermelho,LOW);
 
}

void servo() {
// Criando servo motor
 for (pos = 0; pos <= 180; pos += 1) { //Acrecenta posição de um em um 
    myservo.write(pos);             
 
  digitalWrite(ledAzul,HIGH);     
  digitalWrite(ledVerde,HIGH);
  digitalWrite(ledVermelho,HIGH);
  delay(15);                       
 }
 for (pos = 180; pos >= 0; pos -= 1) { //Diminui posição de um em um
    myservo.write(pos);
//                  
  digitalWrite(ledAzul,HIGH);
  digitalWrite(ledVerde,LOW);
  digitalWrite(ledVermelho,HIGH);
  delay(15);                      
 }
}
