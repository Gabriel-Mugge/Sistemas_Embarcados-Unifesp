//Esse daqui


void main() {
     //  "0"  "1"  "2"  "3"  "4"  "5"  "6"  "7"  "8"  "9"
   unsigned char ucMask[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
   /* Variavel do tipo vetor que armazena os valores correspondentes ao numero
   para ser mostrado no display de 7 segmentos */

   unsigned char tratamento_botao = 0; // Variavel de tratamento do incremento.
   unsigned int  contador = -1;   // Variavel de armazenamento do contador.
   unsigned int  aux_contador = 0;      // Variavel auxiliar para exibir o contador.
   unsigned int penultimo_digitoRA = 2;
   unsigned int ultimo_digitoRA = 7;

   ADCON1 = 0x0f;       // Configura todos canais como Digital.

   TRISB.RB0 = 1;         // Define o pino RB0 do PORTB como entrada.

   //configurando pinos do display como saída
   TRISA.RA2 = 0;
   TRISA.RA3 = 0;
   TRISA.RA4 = 0;
   TRISA.RA5 = 0;

   // Define todos os pinos Do PORTD como saida, pois é onde estarei apresentando os numeros, ou seja,
   //displays de 7 segmentos.
   TRISD = 0;

   //configurando os leds
   TRISB.RB7 = 0;         // Define o pino RB7 do PORTA como saida
   TRISB.RB6 = 0;         // Define o pino RB6 do PORTA como saida

   //para o buzzer:
   TRISC.RC1 = 0;      //PORT C configurado como saída

   //while infinito para simular o loop do arduino
   while(1){


      // Incrementa somente uma vez quando a tecla for pressionada.
      if( (PORTB.RB0 == 0) && (tratamento_botao == 0) ){
         tratamento_botao = 1;                       // Variavel de tratamento do incremento.
         contador++;
         if(contador > 9999){ // Define o valor maximo a ser mostrado no displays como 9999.
            contador = 9999;
         }
      }

      // Volta a disponibilizar a opção de incremento quando a tecla for solta.
      if( (PORTB.RB0 == 1) && (tratamento_botao == 1)){
         tratamento_botao = 0;
      }


      aux_contador = contador;                   // Coloca o conteudo da variavel do contador na varaivel auxiliar.

      // Mostra valor da unidade.
      PORTD = ucMask[aux_contador % 10];              // Pega modulo da divisao por 10 e coloca o valor no PORTD.
      PORTA.RA5 = 1;                           // Liga o transistor associado ao display 1.
      Delay_ms(2);                             // Delay para escrita no display.
      PORTA.RA5 = 0;                           // Desliga o transistor associado ao display 1.
      aux_contador /= 10;                             // Divide variavel por 10 para definir a dezena.
      // Mostra valor da dezena.
      PORTD = ucMask[aux_contador % 10];
      PORTA.RA4 = 1;
      Delay_ms(2);
      PORTA.RA4 = 0;
      aux_contador /= 10;
      // Mostra valor da centena.
      PORTD = ucMask[aux_contador % 10];
      PORTA.RA3 = 1;
      Delay_ms(2);
      PORTA.RA3 = 0;
      aux_contador /= 10;
      // Mostra valor do milhar.
      PORTD = ucMask[aux_contador % 10];
      PORTA.RA2 = 1;
      Delay_ms(2);
      PORTA.RA2 = 0;

      //Checa se o contador é um multiplo do penultimo digito do RA e liga o led
      if (contador % penultimo_digitoRA == 0){
         PORTB.RB6 = 1;
      }else{
         PORTB.RB6 = 0;
      }

      //Checa se o contador é um multiplo do ultimo digito do RA e liga o led
      if (contador % ultimo_digitoRA == 0){
         PORTB.RB7 = 1;
      }else{
            PORTB.RB7 = 0;
      }

      //Se qualquer um dos led estiver acesso ative o buzzer
      if (PORTB.RB7 == 1 || PORTB.RB6 == 1){
            PORTC.RC1 = 1;
      }else{
          PORTC.RC1 = 0;
      }
   }
}

