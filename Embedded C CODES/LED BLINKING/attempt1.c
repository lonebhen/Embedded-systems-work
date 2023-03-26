#include <reg51.h>

void MSDelay(unsigned int i);

sbit sensor = P1^1;
sbit buzzer = P1^7;
void MSDelay(unsigned int i);
void main(void){
	while(1){
		if(sensor ==1){
			buzzer = 0;
			MSDelay(25);
			buzzer = 1;
			MSDelay(25);
		}
	}
}
	
	
void MSDelay(unsigned int itime){
		unsigned int i,j;
		for(i=0;i<itime;i++)
		for(j=0;j<1275;j++);
	}
	
