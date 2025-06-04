// Incluir as bibliotecas que serão utilizadas, A biblioteca do LCD:
#include <LiquidCrystal_I2C.h>
#include <LiquidCrystal.h>
#include "DHT.h"


//Definimos os valores dos pinos utilizados para ligar o LCD 16x2
int rs = 6;
int e = 7;
int d4 = 2;
int d5 = 3;
int d6 = 4;
int d7 = 5;

//Definidos os Pinos Digitais do Led
int led = 8;

//E os pinos analógicos do sensor
#define DHTPIN A1
#define DHTTYPE DHT11 // DHT 11
DHT dht(DHTPIN, DHTTYPE);
int temp = 0;

//Inicializar o LCD chamando suas variaveis já definidas
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

void setup() {
  //pinMode(sensorPin, INPUT);//é definido o sensor como uma entrada
  pinMode(led, OUTPUT);//E o LED como uma saída dentro do arduino

  /*É definida o inicio do LCD configurando
  sua quantidade de linhas e colunas*/
  lcd.begin(16, 2);
  dht.begin();
}

void loop() {
  //é definida uma variável para receber os valores do sensor
  
      
  //float tmp = analogRead(sensorPin);
  float tmpCel = dht.readTemperature();

  //é defininida a primeira linha onde será iniciado o cursor 
  //e onde as primeiras linhas serão escritas
  lcd.setCursor(0, 0);
  lcd.print(tmpCel); //LCD irá imprimir o valor obtido pelo sensor
  lcd.print(" graus C"); //Linha que irá imprimir o simbolo ASCII "º" e a unidade de medida
  
  /*
  Inicio de condicional:
  
  Se tmpCel for maior que 0:
  -pisque o led vermelho
  -imprima a palavra : "Perigo!!!"
  
  */
  if (tmpCel > 40){
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
    lcd.setCursor(0,1);
    lcd.print("Perigo!!!");
  }
  if (tmpCel < 0){
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
    lcd.setCursor(0,1);
    lcd.print("Perigo!!!");
  }else{
    /*
    SENÃO (caso a tmpcel seja menor que zero)
    -apague a mensagem e não imprima nada além do contador de temperatura
    
    */
    
    lcd.setCursor(0,1);
    lcd.print("               ");//Forma de apagar a mensagem antiga no LCD 
    //é substituindo os caracteres antigos por caracteres "vazios"
  }
  
}
