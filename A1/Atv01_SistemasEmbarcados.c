// C++ code

//configurando ctes, pinos e variáveis
#define RA_penultimo 2
#define RA_ultimo 7

//pinos
const int Buzzer = 10;
const int chave1 = 5;
const int chave2 = 3;
const int chave3 = 2;
const int led_verde = 11;
const int led_vermelho = 9;
const int led_amarelo = 12;
//estados iniciais
int estado_ch1 = LOW;
int estado_ch2 = LOW;
int estado_ch3 = LOW;
int ultimoEstado_ch1 = LOW;
int ultimoEstado_ch2 = LOW;
int ultimoEstado_ch3 = LOW;
int qtd_ch1 = 0;
int qtd_ch2 = 0;
int estado_led_amarelo = HIGH;
int estado_led_vermelho = LOW;
int estado_led_verde = HIGH;
//variavel de leitura de botão
int leitura;


//variáveis de controle de debounce
unsigned long contadorTempoDebounce = 0;  
unsigned long TempoDebounce = 50;

void setup()
{
  //configurando a serial
  Serial.begin(9600);
  //Configurando entradas e saídas
  pinMode(Buzzer, OUTPUT);
  pinMode(chave1, INPUT);
  pinMode(chave2, INPUT);
  pinMode(chave3, INPUT);
  pinMode(led_vermelho, OUTPUT);
  pinMode(led_verde, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  
  Serial.print("Ch1: ");
  Serial.print(qtd_ch1);
  Serial.print("  Ch2: ");
  Serial.println(qtd_ch2);


}

/*
obs: o código de debounce foi construído em cima
do exemplo oficial da documentação:
https://www.arduino.cc/en/Tutorial/BuiltInExamples/Debounce
*/

void loop()
{
  //----------Bloco associado a chave1 (ini)----------------//
  
  //Lendo a informação da chave1
  leitura = digitalRead(chave1);
  
  //Checa se houve uma troca de estado no botão
  if (leitura != ultimoEstado_ch1) {
    //Começa a contagem de tempo para debounce
    contadorTempoDebounce = millis();
    
  }
  
  

  //Checa se o tempo de debounce já foi atingido
  if ((millis() - contadorTempoDebounce) > TempoDebounce) {
    //Se ainda não houve a atualização do estado
    if (leitura != estado_ch1) {
      estado_ch1 = leitura;
      
      //Se está em nível alto atualize o contador
      if (estado_ch1 == HIGH) {
          qtd_ch1++;
          
          Serial.print("Ch1: ");
          Serial.print(qtd_ch1);
          Serial.print("  Ch2: ");
          Serial.println(qtd_ch2);
          
          //Acenda o led amarelo se for multiplo do penultimo 
          //digito do meu RA
          if (qtd_ch1 % RA_penultimo == 0){
            estado_led_amarelo = !estado_led_amarelo;
          }else{
            estado_led_amarelo = LOW;
          }
      }
    }

      
  }
  
    //Armazena o último estado do botão
    ultimoEstado_ch1 = leitura;
  
    
  
    //Apaga/acende led amarelo
    digitalWrite(led_amarelo, estado_led_amarelo);
  
  //----------Bloco associado a chave1 (fini)----------------//
  
  
  
  //----------Bloco associado a chave2 (ini)----------------//
  
  //Lendo a informação da chave2
  leitura = digitalRead(chave2);
  
  //Checa se houve uma troca de estado no botão
  if (leitura != ultimoEstado_ch2) {
    //Começa a contagem de tempo para debounce
    contadorTempoDebounce = millis();
    
  }
  
  

  //Checa se o tempo de debounce já foi atingido
  if ((millis() - contadorTempoDebounce) > TempoDebounce) {
    //Se ainda não houve a atualização do estado
    if (leitura != estado_ch2) {
      estado_ch2 = leitura;
      
      //Se está em nível alto atualize o contador
      if (estado_ch2 == HIGH) {
          qtd_ch2++;
          
          Serial.print("Ch1: ");
          Serial.print(qtd_ch1);
          Serial.print("  Ch2: ");
          Serial.println(qtd_ch2);
      }
    } 
  }
  
  //Armazena o último estado do botão
  ultimoEstado_ch2 = leitura;
  
    
  //Acenda o led verde se for multiplo do ultimo 
  //digito do meu RA
  if (qtd_ch2 % RA_ultimo == 0){
    estado_led_verde = !estado_led_verde;
  }else{
    estado_led_verde = LOW;
  }
  
  //Apaga/acende led verde
  digitalWrite(led_verde, estado_led_verde);
  
  //----------Bloco associado a chave2 (fini)----------------//
  

      
  
  //----------Bloco associado a chave3 (ini)----------------//
   //Lendo a informação da chave3
  leitura = digitalRead(chave3);
  
  //Checa se houve uma troca de estado no botão
  if (leitura != ultimoEstado_ch3) {
    //Começa a contagem de tempo para debounce
    contadorTempoDebounce = millis();
    
  }
  
  

  //Checa se o tempo de debounce já foi atingido
  if ((millis() - contadorTempoDebounce) > TempoDebounce) {
    //Se ainda não houve a atualização do estado
    if (leitura != estado_ch3) {
      estado_ch3 = leitura;
      
      //Se está em nível alto atualize o contador
      if (estado_ch3 == HIGH) {
          //Acende led vermelho
          digitalWrite(led_vermelho, HIGH);
          tone(Buzzer, 226, 1000);
          delay(1000);
          digitalWrite(led_vermelho, LOW);
          delay(1000);
          digitalWrite(led_vermelho, HIGH);
          tone(Buzzer, 226, 1000);
          delay(1000);
          digitalWrite(led_vermelho, LOW);
          //resetando valores originais          
          estado_ch1 = LOW;
          estado_ch2 = LOW;
          estado_ch3 = LOW;
          ultimoEstado_ch1 = LOW;
          ultimoEstado_ch2 = LOW;
          ultimoEstado_ch3 = LOW;
          qtd_ch1 = 0;
          qtd_ch2 = 0;
          estado_led_amarelo = HIGH;
          estado_led_vermelho = LOW;
          estado_led_verde = HIGH;
          Serial.print("Ch1: ");
          Serial.print(qtd_ch1);
          Serial.print("  Ch2: ");
          Serial.println(qtd_ch2);  
      }
    }

      
  }
  
  ultimoEstado_ch3 = leitura;
  
  //----------Bloco associado a chave3 (fini)----------------//
}