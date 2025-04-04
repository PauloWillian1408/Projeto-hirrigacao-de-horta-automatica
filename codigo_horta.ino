// Código de Funcionamento para Sistema de Monitoramento e Irrigação com Arduino
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#define pinoAnalog A0 // Define o pino A0 como "pinoAnalog" pino de dados do sensor
#define pinoRele 8 // Define o pino 8 como "pinoRele"
#define pino5V 7 // Define o pino 7 como "pino5V" pino de alimentação do sensor
#define pinoL5 9 // define o pino 9 como "pinoL5" pino de alimentação do LCD

int ValAnalogIn; // Introduz o valor analógico ao código
const int LCD_ADDRESS = 0x27; //define o endereço/tipo da tela lcd como uma variavel int
const int LCD_COLUMNS = 16; //define a quantidade de colunas da tela lcd
const int LCD_ROWS = 2; //define a quantidade de fileiras da tela lcd

LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);



void setup() {
Serial.begin(9600); // Declara o BaundRate em 9600
Serial.println("Hort escolar"); // Imprime a frase no monitor serial
pinMode(pinoL5, OUTPUT); // declara o pinoL5 como saida
pinMode(pinoRele, OUTPUT); // Declara o pinoRele como Saída
pinMode(pino5V, OUTPUT); // Declara o pino5V como Saída
digitalWrite(pinoL5, HIGH); // Põem o pinoL5 em estado Alto = 5V
digitalWrite(pino5V, HIGH); // Põem o pino5V em estado Alto = 5V

  lcd.init(); //inicia a tela LCD
  lcd.setCursor(0, 0); //posiciona o cursor na coluna 0 e fileira 0
  lcd.backlight(); //ativa o backlight do LCD
  lcd.display(); //atualiza o LCD
}
void loop() {
ValAnalogIn = analogRead(pinoAnalog); // Relaciona o valor analógico com o recebido do sensor
int Porcento = map(ValAnalogIn, 1023, 0, 0, 100); // Relaciona o valor analógico à porcentagem
lcd.setCursor(0, 1);// posiciona o cursor na coluna 0 fileira 1

lcd.print(Porcento); // Imprime o valor em Porcento no monitor Serial
lcd.print("% de umidade"); // Imprime o símbolo junto ao valor encontrado

if (Porcento <= 45) { // Se a porcentagem for menor ou igual à
lcd.setCursor(0, 0); //posiciona o cursor na coluna 0 e fileira 0
lcd.print("Irrigando"); // Imprime a frase no monitor serial
digitalWrite(pinoRele, HIGH); // Altera o estado do pinoRele para nível Alto
delay(400);// define um delay de 400 milisegundos para limpar a LCD
lcd.clear();//Limpa a tela LCD
}
else { // Se não …
lcd.setCursor(0, 0);//posiciona o cursor na coluna 0 e fileira 0
lcd.print("Planta Irrigada"); // Imprime a frase no monitor serial
digitalWrite(pinoRele, LOW); // Altera o estado do pinoRele para nível Baixo
delay(400);// define um delay de 400 milisegundos para limpar a LCD
lcd.clear();//Limpa a tela LCD
}
delay (500); // Estabelece o tempo de 5ms para reinicializar a leitura
}
