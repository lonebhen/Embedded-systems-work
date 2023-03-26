#include <reg51.h>

void MSDelay(unsigned int i);

void main(void){
	while(1){
	P2=0x3f;    //0
	MSDelay(25);
	P2=0x06;     //1
	MSDelay(25);
	P2=0x5b;     //2
	MSDelay(25);
	P2=0x4f; //3
	MSDelay(25);
	P2= 0x66; //4
	MSDelay(25);
	P2 = 0x6d; //5
	MSDelay(25);
	P2=0x7d ; //6
	MSDelay(25);
	P2=0x07; //7
	MSDelay(25);
	P2=0x7f; //8
	MSDelay(25);
	P2=0x67; //9
	MSDelay(25);
}
	}

	void MSDelay(unsigned int itime){
		unsigned i,j;
		for(i=0;i<itime;i++)
		for(j=0;j<1275;j++);
	}