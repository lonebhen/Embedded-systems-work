// LCD interfacing with the microcontroller

#include <reg51.h>

void delay(unsigned int i);
void lcd_cmd(unsigned char a);
void lcd_data(unsigned char b);
void lcd_init(void);
void lcd_str(unsigned char *str);
sbit rs = P2^0;
sbit en = P2^1;
sfr ldata = 0xB0;
	
void main(void){
	lcd_init();
	lcd_str("  WELCOME  \n");
	lcd_cmd(0xC0);
	lcd_str(" TO BENS ");
	while(1);
	
}


void lcd_init(){
	lcd_cmd(0x38);
	lcd_cmd(0x0C);
	lcd_cmd(0x01);
	lcd_cmd(0x80);
}
	



void delay(unsigned int itime){
	unsigned i,j;
	for(i=0;i<itime;i++)
	for(j=0;j<1275;j++);
}

void lcd_cmd(unsigned char a){
	rs = 0;
	ldata = a;
	en = 1;
	delay(5);
	en  = 0;
	delay(5);
}

void lcd_data(unsigned char b){
	rs = 1;
	ldata = b;
	en = 1;
	delay(5);
	en  = 0;
	delay(5);
}

void lcd_str(unsigned char *str){
	while(*str){
		lcd_data(*str++);
	}
}
	
	