#include <reg51.h>

void MSDelay(unsigned int i);

void main(void){
	while(1){
		P2=0x55;
		P1=0xAA;
		MSDelay(250);
		P2=0xAA;
		P1=0x55;
		MSDelay(250);
	}
}

void MSDelay(unsigned int itime){
	unsigned i,j;
	for(i=0;i<itime;i++);
	for(j=0;j<1275;j++);
}