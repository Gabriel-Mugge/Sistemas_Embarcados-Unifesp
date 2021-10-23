#include <Wire.h>

//variáveis importantes
String leitura_serial;
int statusBotao = 0;
int flagLcd = 0;
int count = 0;
int statusBotao1 = LOW;
int statusBotao2 = LOW;

void setup()
{
  Serial.begin(9600);
  //indicando q este arduíno é o mestre
  Wire.begin();
}

void loop()
{
  
  //iniciando a transmissão para o escravo cujo endereço é 1
  Wire.beginTransmission(1);
  leitura_serial = "";
  //lendo comando digitado no serial, salvando em uma variável e trasmitindo
  //os caracteres pelo i2c.
  while(Serial.available() > 0){
  	char c = Serial.read();
    Wire.write(c);
    leitura_serial += c;
    
    
    //colocando o comando td em minusculo para que se ao menos os carateres
    //forem os mesmos ele seja entendido
    leitura_serial.toLowerCase();
    //Identificando qual comando foi digitado
    if (leitura_serial == "ligarled"){
      Serial.println("Led Ligado");
  	}else if (leitura_serial == "desligarled"){
      Serial.println("Led desligado");
    }else if (leitura_serial == "ligarbuzzer"){
      Serial.println("Buzzer ligado");
  	}else if (leitura_serial == "desligarbuzzer"){
      Serial.println("Buzzer desligado");
  	}else if (leitura_serial == "display lcd"){
      flagLcd = 1;
      
    }
  }
  //Para garantir que dê tempo para a leitura do serial.
  delay(100);
  Wire.endTransmission();
  
  if (flagLcd == 1){
  	msg_diplay();
    flagLcd = 0;
    Serial.println("Mensagem alterada");
  }
 
  
  //Recebendo informações do escravo para monitorar
  //estados dos botões.
  Wire.requestFrom(1, 1);
  while(Wire.available()){
  	statusBotao = Wire.read();
  }
  
  //Se botão 1 estiver precionado, atualize seu estado.
  if (statusBotao == 1){
  	statusBotao1 = !statusBotao1;
    if (statusBotao1 == HIGH){
    	Serial.println("Chave 1: ON");
    }else{
    	Serial.println("Chave 1: OFF");
    }
    if (statusBotao2 == HIGH){
    	Serial.println("Chave 2: ON");
    }else{
    	Serial.println("Chave 2: OFF");
    }
    //indica que nenhum botão mudou de estado.
    statusBotao = 0;
  }
  //Se botão 2 estiver precionado, atualize seu estado.
  if (statusBotao == 2){
  	statusBotao2 = !statusBotao2;
    if (statusBotao1 == HIGH){
    	Serial.println("Chave 1: ON");
    }else{
    	Serial.println("Chave 1: OFF");
    }
    if (statusBotao2 == HIGH){
    	Serial.println("Chave 2: ON");
    }else{
    	Serial.println("Chave 2: OFF");
    }
    statusBotao = 0;
  }
  
}


//Função para ler e trasmitir a nova mensagem do lcd
void msg_diplay(){
	Serial.println("Digite a mensagem desejada");
    
  String leitura_serial = "";
  Wire.beginTransmission(1);
  int flag = 0;
  while(1){
    while (Serial.available() > 0){
      char c = Serial.read();
   		Wire.write(c);
    	leitura_serial += c;
      delay(100);
      flag = 1;   
    }

    if (flag == 1){
      break;
    }
  }
  Wire.endTransmission();
}