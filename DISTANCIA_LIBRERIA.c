#BYTE TRISA = 0x85       //SENSOR ULTRA 
#BYTE PORTA = 0x05
#BYTE T1CON = 0X10
#BYTE TMR1H = 0X0F
#BYTE TMR1L = 0X0E
#bit PINA1 = PORTA.1
#bit PINA2 = PORTA.2

//NIVEL BY FN
void INICIAR_TIMER(){ 
 T1CON = 0x01; //cambia el primer bit del registro t1con para activar el timer 1 del pic
 TMR1H=0x0; //Pone en cero el registro del timer 1 part1
 TMR1L=0x0; //Pone en cero el registro del timer 1 part 2
}
int16 OBTENER_VALOR(){
int16 Valor_16bits;
valor_16bits=(TMR1H*256)+TMR1L;
return valor_16bits  ;  //Extrae el valor almacenado en los registros parte 1 y parte dos que son de 8 bits y los convierte en una variable de 16 bits
}
void SET_TIMER1_0(){ //vuelve a poner los valores de los registros en cero.
 TMR1H=0x0;
 TMR1L=0x0;
}
void INICIALIZAR_LIBRERIA(){ 
 INICIAR_TIMER();
 TRISA =0XFD;
 }
float OBTENER_DISTANCIA(){
INT16 TIEMPO;
FLOAT DISTANCIA;
PINA1=0x01;
 delay_us(10);
 PINA1=0X0;
 WHILE(PINA2==0){}
  SET_TIMER1_0();
 WHILE(PINA2==1){}
 TIEMPO=OBTENER_VALOR();
 DISTANCIA=((tiempo/2)/29.1375);


RETURN (FLOAT) DISTANCIA;
 
 


}
