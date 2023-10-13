#include "stdio.h"

long counter = 0;

//Rotina de interrupcao que incrementa o contador
void interrupt increment(){
	counter++;
	//O comando outportb informa ao controlador que novas interrupcoes podem acontecer em seguida
        outportb(0x20,0x20);

}

void main(){
	//Setvect seta a rotina increment na posicao 8 da tabela de vetores de interrupcao
	//A posicao 8 da tabela corresponde a IRQ0
	//IRQ0 corresponde a interrupcao gerada pelo temporizador do PC
	setvect(8,increment);
	while(counter < 100 && !kbhit()){
        	printf("%d\n",counter);
        }
	return 0;

}