//bibliotecas
#include <DHT11.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPINO A1 //definimos qual será o pino para o sensor
#define DHTTYPE DHT11 //Variavel do tipo DHT

DHT dht(DHTPINO, DHT11); //Inicializa o objeto - DHT - com - o - pino


//Variáveis globais são função 
const int PIR = 2;  // Pino Digital que o PIR está plugado
const int ledAmarelo = 13;

//Variáveis globais são função
const int MQ135 = A0; // pino Analogico do mq-135
const int buzzer = 12;

void acenderLEDAoDetectarPresenca() {
int estadoPIR = digitalRead(PIR);  //Lê o pino Digital 2

if (estadoPIR == HIGH) {
digitalWrite(ledAmarelo, HIGH);
Serial.println("LED ligado");
} else {
digitalWrite(ledAmarelo, LOW);
Serial.println("LED apagado");
}

}

void verificarVazamentoDeGas(){
int estadoMQ135 = analogRead(MQ135);

//if - verificar a intensidade do valor do estadoMQ135 .= 600
//sim - ativar o alarme - alarme_dois_tons();
//nao - dasativar alarme - noTone(buzzer);
Serial.println(estadoMQ135);
delay(5000);

if (estadoMQ135 >= 600){
alarme_dois_tons();
} else {
noTone(buzzer);
}

}


void alarme_dois_tons() {
int freqAlta = 2000;
int freqBaixa = 800;
int duracaoTom = 250;

tone(buzzer, freqAlta, duracaoTom);
delay(duracaoTom);
tone(buzzer, freqBaixa, duracaoTom);
delay(duracaoTom);
}

void verificarTemperaturaEUmidade(){
float umidade = dht.readHumidity(); //lê a umidade
float temperatura = dht.readTemperature();//lê a temperatura em Celcius

Serial.println("Umidade: " + String(umidade) + "%");
Serial.println("Temperatura: " + String(temperatura) + "C");
delay(1000);


}


void setup() {
Serial.begin(9600);

pinMode(ledAmarelo, OUTPUT);
pinMode(MQ135, INPUT);
pinMode(buzzer, OUTPUT);

//Inicializar o sensor DHT
dht.begin();


Serial.println("Calibrando os sensores");
delay(1000);
Serial.println("Sensores calibrados!!! ;) Pode testas hehe");
}

void loop() {
//As instruções no loop será somente chamada de funções
//acenderLEDAoDetectarPresenca();
//verificarVazamentoDeGas();
verificarTemperaturaEUmidade();
}
