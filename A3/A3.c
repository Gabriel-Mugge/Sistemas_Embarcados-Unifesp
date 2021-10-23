//configurando constantes
const int led1 = 11; 
const int led2 = 10; 
const int led3 = 6; 
const int led4 = 5; 
const int led5 = 3; 
const int led6 = 9; 
int pwm = 0; 
int count = 0;
int leds[6] = {led1, led2, led3, led4, led5, led6};
int FlagSubida = 1;


void setup(){
  //Configurando os pinos dos leds como saída
	pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
}


void loop(){

  //Se estiver em subida (acendendo gradualmente os leds)
  if (FlagSubida == 1){
    count = 0; //usado para saber qual led acender
    while (count < 6){
      for (pwm = 0; pwm <= 255; pwm++){
			   analogWrite(leds[count], pwm);
			   delay(10); //espera para acender gradualmente
		  }
      count++;
    }
  	
    FlagSubida = 0; //atualiza flag para descida
    //Se estiver em descida (apagando gradualmente os leds)
  }else{
    count = 5; //usado para saber qual led apagar
    while (count >= 0){
  		for (pwm = 255; pwm >= 0; pwm--){
			analogWrite(leds[count], pwm);
			delay(10); //espera para apagar gradualmente
		}
      count--;
    }
    FlagSubida = 1; //atualiza flag para subida
    delay(1000); //Espera para reiniciar o ciclo
     
  }
  
	
  
}







