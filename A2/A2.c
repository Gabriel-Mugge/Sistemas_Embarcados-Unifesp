//declarando constantes.
float sensorTemp = A0;
float tempCelsius = 0;
int pinoLed1 = 13;
int pinoLed2 = 12;
int pinoLed3 = 11;
int pinoLed4 = 10;
int pinoLed5 = 9;
int pinoLed6 = 8;
int pinoLed7 = 7;
int pinoLed8 = 6;
int pinoLed9 = 5;
int pinoLed10 = 4;
int buzzer = 2;
int botao = 3;
int estado_botao = LOW;
int ultimoEstado_botao = LOW;
int leitura_botao;


//variáveis de controle de debounce
unsigned long contadorTempoDebounce = 0;  
unsigned long TempoDebounce = 50;

//variáveis de controle para buzzer
unsigned long contadorTempoBuzzer = 0;  
unsigned long TempoBuzzer = 500;
int FlagBuzzer = 0;


void setup()
{
  //configurando pinos de entrada e saída
  pinMode(sensorTemp, INPUT);
  pinMode(pinoLed1, OUTPUT);
  pinMode(pinoLed2, OUTPUT);
  pinMode(pinoLed3, OUTPUT);
  pinMode(pinoLed4, OUTPUT);
  pinMode(pinoLed5, OUTPUT);
  pinMode(pinoLed6, OUTPUT);
  pinMode(pinoLed7, OUTPUT);
  pinMode(pinoLed8, OUTPUT);
  pinMode(pinoLed9, OUTPUT);
  pinMode(pinoLed10, OUTPUT);
  pinMode(botao, INPUT);
  pinMode(buzzer, OUTPUT);
  //configurando comunicação serial
  Serial.begin(9600);
}


void loop()
{
  
  //lendo a informação presente no sensor de tempoeratura com analogRead(sensorTemp)
  //e usando a função map para coverter o intervalo de 20 a 356 lido pelo sensor para
  //o intervalo de temperatura q o mesmo deve ser capaz de medir.
  tempCelsius = map(analogRead(sensorTemp), 20, 358, -40, 125);
 
  //Lendo a informação da chave1
  leitura_botao = digitalRead(botao);
  
  //Checa se houve uma troca de estado no botão
  if (leitura_botao != ultimoEstado_botao) {
    //Começa a contagem de tempo para debounce
    contadorTempoDebounce = millis();
    
  }
  

  //Checa se o tempo de debounce já foi atingido
  if ((millis() - contadorTempoDebounce) > TempoDebounce) {
    //Se ainda não houve a atualização do estado
    if (leitura_botao != estado_botao) {
      estado_botao = leitura_botao;
      
      //Se está em nível alto mostre a temperatura lida
      if (estado_botao == HIGH) {
        Serial.print("T = ");
        Serial.print(tempCelsius);
        Serial.println(" *C");
      }
    }

      
  }
  
    //Armazena o último estado do botão
    ultimoEstado_botao = leitura_botao;
  
  
  //Sequencia de intervalos para acender cada led
  if (tempCelsius >= 20 && tempCelsius < 22.22){
    digitalWrite(pinoLed1, HIGH);
    digitalWrite(pinoLed2, LOW);
    digitalWrite(pinoLed3, LOW);
    digitalWrite(pinoLed4, LOW);
    digitalWrite(pinoLed5, LOW);
    digitalWrite(pinoLed6, LOW);
    digitalWrite(pinoLed7, LOW);
    digitalWrite(pinoLed8, LOW);
    digitalWrite(pinoLed9, LOW);
    digitalWrite(pinoLed10, LOW);
    FlagBuzzer = 0;
    
  }
  else if (tempCelsius >= 22.22 && tempCelsius < 24.44){
    digitalWrite(pinoLed1, HIGH);
    digitalWrite(pinoLed2, HIGH);
    digitalWrite(pinoLed3, LOW);
    digitalWrite(pinoLed4, LOW);
    digitalWrite(pinoLed5, LOW);
    digitalWrite(pinoLed6, LOW);
    digitalWrite(pinoLed7, LOW);
    digitalWrite(pinoLed8, LOW);
    digitalWrite(pinoLed9, LOW);
    digitalWrite(pinoLed10, LOW);
    FlagBuzzer = 0;
  }
  else if (tempCelsius >= 24.44 && tempCelsius < 26.66){
    digitalWrite(pinoLed1, HIGH);
    digitalWrite(pinoLed2, HIGH);
    digitalWrite(pinoLed3, HIGH);
    digitalWrite(pinoLed4, LOW);
    digitalWrite(pinoLed5, LOW);
    digitalWrite(pinoLed6, LOW);
    digitalWrite(pinoLed7, LOW);
    digitalWrite(pinoLed8, LOW);
    digitalWrite(pinoLed9, LOW);
    digitalWrite(pinoLed10, LOW);
    FlagBuzzer = 0;
  }
  else if (tempCelsius >= 26.66 && tempCelsius < 28.88){
    digitalWrite(pinoLed1, HIGH);
    digitalWrite(pinoLed2, HIGH);
    digitalWrite(pinoLed3, HIGH);
    digitalWrite(pinoLed4, HIGH);
    digitalWrite(pinoLed5, LOW);
    digitalWrite(pinoLed6, LOW);
    digitalWrite(pinoLed7, LOW);
    digitalWrite(pinoLed8, LOW);
    digitalWrite(pinoLed9, LOW);
    digitalWrite(pinoLed10, LOW);
    FlagBuzzer = 0;
  }
  else if (tempCelsius >= 28.88 && tempCelsius < 31.1){
    digitalWrite(pinoLed1, HIGH);
    digitalWrite(pinoLed2, HIGH);
    digitalWrite(pinoLed3, HIGH);
    digitalWrite(pinoLed4, HIGH);
    digitalWrite(pinoLed5, HIGH);
    digitalWrite(pinoLed6, LOW);
    digitalWrite(pinoLed7, LOW);
    digitalWrite(pinoLed8, LOW);
    digitalWrite(pinoLed9, LOW);
    digitalWrite(pinoLed10, LOW);
    FlagBuzzer = 0;
  }
  else if (tempCelsius >= 31.1 && tempCelsius < 33.32){
    digitalWrite(pinoLed1, HIGH);
    digitalWrite(pinoLed2, HIGH);
    digitalWrite(pinoLed3, HIGH);
    digitalWrite(pinoLed4, HIGH);
    digitalWrite(pinoLed5, HIGH);
    digitalWrite(pinoLed6, HIGH);
    digitalWrite(pinoLed7, LOW);
    digitalWrite(pinoLed8, LOW);
    digitalWrite(pinoLed9, LOW);
    digitalWrite(pinoLed10, LOW);
    FlagBuzzer = 0;
  }
  else if (tempCelsius >= 32.32 && tempCelsius < 35.54){
    digitalWrite(pinoLed1, HIGH);
    digitalWrite(pinoLed2, HIGH);
    digitalWrite(pinoLed3, HIGH);
    digitalWrite(pinoLed4, HIGH);
    digitalWrite(pinoLed5, HIGH);
    digitalWrite(pinoLed6, HIGH);
    digitalWrite(pinoLed7, HIGH);
    digitalWrite(pinoLed8, LOW);
    digitalWrite(pinoLed9, LOW);
    digitalWrite(pinoLed10, LOW);
    FlagBuzzer = 0;
  }
  else if (tempCelsius >= 35.54 && tempCelsius < 37.78){
    digitalWrite(pinoLed1, HIGH);
    digitalWrite(pinoLed2, HIGH);
    digitalWrite(pinoLed3, HIGH);
    digitalWrite(pinoLed4, HIGH);
    digitalWrite(pinoLed5, HIGH);
    digitalWrite(pinoLed6, HIGH);
    digitalWrite(pinoLed7, HIGH);
    digitalWrite(pinoLed8, HIGH);
    digitalWrite(pinoLed9, LOW);
    digitalWrite(pinoLed10, LOW);
    FlagBuzzer = 0;
  }
  else if (tempCelsius >= 37.78 && tempCelsius < 39.00){
    digitalWrite(pinoLed1, HIGH);
    digitalWrite(pinoLed2, HIGH);
    digitalWrite(pinoLed3, HIGH);
    digitalWrite(pinoLed4, HIGH);
    digitalWrite(pinoLed5, HIGH);
    digitalWrite(pinoLed6, HIGH);
    digitalWrite(pinoLed7, HIGH);
    digitalWrite(pinoLed8, HIGH);
    digitalWrite(pinoLed9, HIGH);
    digitalWrite(pinoLed10, LOW);
    FlagBuzzer = 0;
  }
  else if (tempCelsius >= 40){
    digitalWrite(pinoLed1, HIGH);
    digitalWrite(pinoLed2, HIGH);
    digitalWrite(pinoLed3, HIGH);
    digitalWrite(pinoLed4, HIGH);
    digitalWrite(pinoLed5, HIGH);
    digitalWrite(pinoLed6, HIGH);
    digitalWrite(pinoLed7, HIGH);
    digitalWrite(pinoLed8, HIGH);
    digitalWrite(pinoLed9, HIGH);
    digitalWrite(pinoLed10, HIGH);
    if (FlagBuzzer == 0){
      contadorTempoBuzzer = millis();
    }
    
    FlagBuzzer = 1;
  }
  else{
    digitalWrite(pinoLed1, LOW);
    digitalWrite(pinoLed2, LOW);
    digitalWrite(pinoLed3, LOW);
    digitalWrite(pinoLed4, LOW);
    digitalWrite(pinoLed5, LOW);
    digitalWrite(pinoLed6, LOW);
    digitalWrite(pinoLed7, LOW);
    digitalWrite(pinoLed8, LOW);
    digitalWrite(pinoLed9, LOW);
    digitalWrite(pinoLed10, LOW);
    FlagBuzzer = 0;
  }
  
  //se a flag do buzzer estiver acionada e o tempo de tolerancia tiver esgotado,
  //acione o buzzer pois já passou de 40 *C.
  if (FlagBuzzer == 1 && (millis() - contadorTempoBuzzer) > TempoBuzzer){
    tone(buzzer, 226, 100);
    contadorTempoBuzzer = millis();
  }  
  
  
}