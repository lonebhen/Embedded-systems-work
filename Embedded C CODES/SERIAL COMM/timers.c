#include <reg51.h>

sbit pin = P1^5;
void timer(void);
void main(void){
	while(1){
	pin = 0;
	timer();
	pin = 1;
	timer();
	}
		
}

void timer(void){
	TMOD =0x01;
	TL0 = 0XFD;
	TH1 = 0X4B;
	TR0 = 1;
	while(TF0==0);
	TR0 = 0;
	TF0 = 0;
}
	 