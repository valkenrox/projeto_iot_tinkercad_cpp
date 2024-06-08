// Carrega a Biblioteca LiquidCrystal
#include <LiquidCrystal.h>

// Define os pinos que serão utilizados para ligação ao display
LiquidCrystal LCD(12,11,5,4,3,2);

// Variáveis

int SensorTempPino=0;
int SensorUmidPino=1;
int porcem=0;


// Define o pino 12 para o alerta de temperatura baixa
int AlertaTempBaixa=12;
// Define o pino 19 para o alerta de temperatura alta
int AlertaTempAlta=25;

// Define temperatura baixa como 10 graus Celsius
int TempBaixa=10;
// Define temperatura alta como acima de 26 graus Celsius
int TempAlta=27;


void setup() 
{
  // Informa se os pinos dos LEDs são de entrada ou saída
  pinMode(AlertaTempBaixa, OUTPUT);  
  pinMode(AlertaTempAlta, OUTPUT);
	
  // Define LCD 16 colunas por 2 linhas
  LCD.begin(16,2);
  
  //Posiciona o cursor na coluna 0, linha 0;
  LCD.setCursor(0,0);
  
  // Imprime a mensagem no LCD
  LCD.print("Temper.:");
  
  // Imprime a mensagem no LCD
  LCD.print("Umidad.:");
  
  // Muda o cursor para a primeira coluna e segunda linha do LCD
  LCD.setCursor(0,1);
  
  // Imprime a mensagem no LCD
  LCD.print("      C      ");
  
  // Imprime a mensagem no LCD
  LCD.setCursor(14,1);
  LCD.print("%");
}

void loop()
{
   // Faz a leitura da tensao no Sensor de Temperatura
   int SensorTempTensao=analogRead(SensorTempPino);

   // Converte a tensao lida
   float Tensao=SensorTempTensao*5;
   Tensao/=1024;

   // Converte a tensao lida em Graus Celsius
   float TemperaturaC=(Tensao-0.5)*100;

   // Muda o cursor para a primeira coluna e segunda linha do LCD
   LCD.setCursor(0,1);

   // Imprime a temperatura em Graus Celsius
   LCD.print(TemperaturaC);
  
    
    // Faz a leitura da tensao no Sensor de Umidade 
    int SensorUmidTensao=analogRead(SensorUmidPino);
        
    // Converte a tensao lida em porcentagem
    float porcem=map(SensorUmidTensao,0,1023,0,100);
    
    // Muda o cursor para a segunda coluna e nona linha do LCD
    LCD.setCursor(8,1);
     
    // Imprime a umidade em porcentagem
    LCD.print(porcem);
     
  
  // Acende ou apaga os alertas luminosos de temperatura baixa e alta
  	if (TemperaturaC>=TempAlta) {
  		digitalWrite(AlertaTempBaixa, LOW);
  		digitalWrite(AlertaTempAlta, HIGH);
    }
  	else if (TemperaturaC<=TempBaixa) {
  		digitalWrite(AlertaTempBaixa, HIGH);
  		digitalWrite(AlertaTempAlta, LOW);
  	}
  	else {
  		digitalWrite(AlertaTempBaixa, LOW);
  		digitalWrite(AlertaTempAlta, LOW);
    }

  // Aguarda 1 segundo
  	delay(1000);
}  
  
   
   
 
   
