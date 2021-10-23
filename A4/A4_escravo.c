#include <LiquidCrystal.h> 
#include <Wire.h>

//Configurando pinos do lcd
LiquidCrystal lcd(5, 4, 9, 8, 7, 6);

//declarando variáveis e contantes importantes
int pinoLed = 11;
int buzzer = 10;
int botao1 = 13;
int botao2 = 12;
int estado_botao1 = LOW;
int ultimoEstado_botao1 = LOW;
int estado_botao2 = LOW;
int ultimoEstado_botao2 = LOW;
int leitura_botao;
int flagLcd = 0;



//variáveis de controle de debounce
unsigned long contadorTempoDebounce = 0;  
unsigned long TempoDebounce = 50;



void setup()
{
  lcd.begin(16, 2);
  //configurando pinos de entrada e saída
  pinMode(pinoLed, OUTPUT);
  pinMode(botao1, INPUT);
  pinMode(botao2, INPUT);
  pinMode(buzzer, OUTPUT);
  //indicando q este arduíno é escravo e seu endereço é 1
  Wire.begin(1);
  //qual função deve ser executada quando o mestre manda dados
  Wire.onReceive(receiveEvent);
  //qual função deve ser executada quando o mestre solicita dados
  Wire.onRequest(requestEvent);
  //configurando comunicação serial
  Serial.begin(9600);
}


void loop()
{
  
  //Lendo a informação da chave1
  leitura_botao = digitalRead(botao1);
  
  //Checa se houve uma troca de estado no botão
  if (leitura_botao != ultimoEstado_botao1) {
    //Começa a contagem de tempo para debounce
    contadorTempoDebounce = millis();
    
  }
  

  //Checa se o tempo de debounce já foi atingido
  if ((millis() - contadorTempoDebounce) > TempoDebounce) {
    //Se ainda não houve a atualização do estado
    if (leitura_botao != estado_botao1) {
      estado_botao1 = leitura_botao;
      //Serial.print(estado_botao1);
    }      
  }
  
    //Armazena o último estado do botão
  ultimoEstado_botao1 = leitura_botao;
  
  
  //Lendo a informação da chave1
  leitura_botao = digitalRead(botao2);
  
  //Checa se houve uma troca de estado no botão
  if (leitura_botao != ultimoEstado_botao2) {
    //Começa a contagem de tempo para debounce
    contadorTempoDebounce = millis();
    
  }
  

  //Checa se o tempo de debounce já foi atingido
  if ((millis() - contadorTempoDebounce) > TempoDebounce) {
    //Se ainda não houve a atualização do estado
    if (leitura_botao != estado_botao2) {
      estado_botao2 = leitura_botao;
      //Serial.print(estado_botao2);
    }      
  }
  
    //Armazena o último estado do botão
  ultimoEstado_botao2 = leitura_botao;
  
}

void receiveEvent(int howmany){
  
  String comando = "";
  //desempacotando a informação passada pelo mestre
  while(0 < Wire.available()){
    char c = Wire.read();
  	comando += c;
  }
  delay(100);

 
  comando.toLowerCase();
  if (comando != ""){
    //identificando comando passado e tomando ações
    if (comando == "ligarled"){
      digitalWrite(pinoLed, HIGH);
    }else if (comando == "desligarled"){
      digitalWrite(pinoLed, LOW);
    }else if (comando == "ligarbuzzer"){
      digitalWrite(buzzer, HIGH);
    }else if (comando == "desligarbuzzer"){
      digitalWrite(buzzer, LOW);
    }else if (comando == "display lcd"){
      flagLcd = 1;
    }
  }

  //Primeira passagem informou que o lcd irá atualizar,
  //a segunda passagem (segundo valor em comando), será
  //a mensagem efetivamente.
  if (flagLcd == 1){
    flagLcd += 1;
  }else if (flagLcd == 2){
    flagLcd = 0;
  	lcd.setCursor(0,0);
    lcd.clear();
  	lcd.print(comando);
  }
}


//Manda um código para o mestre referente a qual botão mudou de estado:
//1 - para botão 1
//2 - para botão 2
void requestEvent(){
  if (estado_botao1 == 1){
    Wire.write(1);
  }
  
  if (estado_botao2 == 1){
    Wire.write(2);
  }
  	
}