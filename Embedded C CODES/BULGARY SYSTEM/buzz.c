#include <reg51.h>

sbit buzzer_pin = P1^7;
sbit push_pin = P3^0;


void main(void){
	unsigned int i;
	
push_pin = 0;
while(1){	
	while(push_pin == 1);
	
		
	
		for(i=0;i<=30;i++){
			buzzer_pin =1;
			
			buzzer_pin = 0;
		}
	
}
}