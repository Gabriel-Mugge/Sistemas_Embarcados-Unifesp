sbit LCD_RS at RE2_bit;   // PINO 2 DO PORTD LIGADO AO RS DO DISPLAY
sbit LCD_EN at RE1_bit;   // PINO 3 DO PORTD LIGADO AO EN DO DISPLAY
sbit LCD_D7 at RD7_bit;  // PINO 7 DO PORTD LIGADO AO D7 DO DISPLAY
sbit LCD_D6 at RD6_bit;  // PINO 6 DO PORTD LIGADO AO D6 DO DISPLAY
sbit LCD_D5 at RD5_bit;  // PINO 5 DO PORTD LIGADO AO D5 DO DISPLAY
sbit LCD_D4 at RD4_bit;  // PINO 4 DO PORTD LIGADO AO D4 DO DISPLAY

// Selecionando direção de fluxo de dados dos pinos utilizados para a comunicação com display LCD
sbit LCD_RS_Direction at TRISE2_bit;  // SETA DIREÇÃO DO FLUXO DE DADOS DO PINO 2 DO PORTD
sbit LCD_EN_Direction at TRISE1_bit;  // SETA DIREÇÃO DO FLUXO DE DADOS DO PINO 3 DO PORTD
sbit LCD_D7_Direction at TRISD7_bit;  // SETA DIREÇÃO DO FLUXO DE DADOS DO PINO 7 DO PORTD
sbit LCD_D6_Direction at TRISD6_bit;  // SETA DIREÇÃO DO FLUXO DE DADOS DO PINO 6 DO PORTD
sbit LCD_D5_Direction at TRISD5_bit;  // SETA DIREÇÃO DO FLUXO DE DADOS DO PINO 5 DO PORTD
sbit LCD_D4_Direction at TRISD4_bit;  // SETA DIREÇÃO DO FLUXO DE DADOS DO PINO 4 DO PORTD

char pot1_string [8]; // STRING PARA RECEBER O VALOR CONVERTIDO DA LEITURA DO POTENCIÔMETRO 1


void main(){
   // Variavel que armazena o valor do A/D.
  unsigned int  valorAD;

  //configurando tds os pinos da porta A como entrada e com o nível alto.
  PORTA = 255;
  TRISA = 255;
  TRISB =0;            // Define todos os pinos do PORTB como saída.
   PORTB = 0;           // Colocar todos os pinos em nível baixo.
   TRISC.RC1 = 0;      //PORT C configurado como saída (Buzzer)
  // Configura conversor A/D Canal 0
  ADCON0 = 0b00000001;
  // Configura todos canais como Digital menos AN0
  ADCON1 = 0b11001110;
  // Configura conversor A/D para resultado justificado a direita, tempo de conversão de 20 TAD, clock de Fosc/64.
  ADCON2 = 0b10111110;
  // Inicializa módulo PWM com 5Khz
  PWM1_Init(5000);
  PWM1_Start();
  
  Lcd_Init();                               //Inicializa módulo LCD
  Lcd_Cmd(_LCD_CURSOR_OFF);                 //Apaga cursor
  Lcd_Cmd(_LCD_CLEAR);                      //Limpa display
  

  
  while(1){
    // Lê Canal AD An0
    //valor varia de 0 a 1023
    valorAD = ADC_Read(0);
    
    Lcd_Cmd(_LCD_CLEAR);
    IntToStr(valorAD, pot1_string);//CONVERTE O VALOR DO TIPO INTEIRO OBTIDO PELO CONVERSOR AD NA PORTA AN0 PARA UMA STRING
    Ltrim(pot1_string);//REMOVE TODOS OS ESPAÇOS EM BRANCO LOCALIZADOS A ESQUERDA DO PRIMEIRO CHAR DA STRING COM O VALOR DE AN0
    Lcd_Out(1,1,"AD: ");
    Lcd_Out_Cp(pot1_string);//ESCREVE O VALOR OBTIDO DO CONVERSOR A/D NA POSIÇÃO EM QUE SE ENCONTRA O CURSOR DO DISPLAY
    
    // Converte valor para o duty cycle, pois o mesmo n varia de 0 255 e não de 0 1023, precisamos fazer ele caber dentro da faixa correta
    valorAD *= 0.2493;
    
    IntToStr(valorAD, pot1_string);//CONVERTE O VALOR DO TIPO INTEIRO OBTIDO PELO CONVERSOR AD NA PORTA AN0 PARA UMA STRING
    Ltrim(pot1_string);//REMOVE TODOS OS ESPAÇOS EM BRANCO LOCALIZADOS A ESQUERDA DO PRIMEIRO CHAR DA STRING COM O VALOR DE AN0
    Lcd_Out(2,1,"PWM: ");
    Lcd_Out_Cp(pot1_string);//ESCREVE O VALOR OBTIDO DO CONVERSOR A/D NA POSIÇÃO EM QUE SE ENCONTRA O CURSOR DO DISPLAY
    // configura o pwm da bentoinha
    PWM1_Set_Duty(valorAD);
    
    if (valorAD == 255){
        PORTB=0b11111111;
        PORTC.RC1 = 1;
    }else{
           PORTB=0b00000000;
           PORTC.RC1 = 0;
    }
    delay_ms(100);
    





  }
}