
#include <reg51.h>

sbit port = P3^0;

void main(void){
	unsigned int z;
	for(z=0;z<5000;z++){
		port = 0;
		port = 1;
	}
}