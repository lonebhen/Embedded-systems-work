#include <reg51.h>


void delay(unsigned int itime);
void lcd_cmd(unsigned char a);
void lcd_data(unsigned char b);
void lcd_init(void);
void lcd_str(unsigned char *str);
void hex2ascii(unsigned char value);
sbit rs= P2^0;
sbit en = P2^1;
sfr port3 = 0xB0;

sbit rd = P2^2;
sbit wr = P2^3;
sbit intr = P2^4;
sfr adc = 0x90;

void main(void){
	lcd_init();
	lcd_str(" MY NAME IS \n");
	lcd_cmd(0xC0);
	lcd_str(" BENJAMIN ");
	
	delay(25);
	lcd_cmd(0x01);
	lcd_cmd(0x80);
	lcd_str("ADC VALUE:  ");
	
	while(1){
		rd=1;
		wr=0;
		delay(7);
		wr=1;
		while(intr==1);
		delay(5);
		rd=0;
			lcd_data(0x8A);
		hex2ascii(adc);
		intr =1;
		
		
		
		
			}
	
	
}
void hex2ascii(unsigned char value){
	unsigned char x,d1,d2,d3;
	x=value/10;
	d3=value%10;
	d2=x%10;
	d1=x/10;
	lcd_data(d1+0x30);
	lcd_data(d2+0x30);
	lcd_data(d3+0x30);
	
}

void delay(unsigned int itime){
	unsigned int i,j;
	for(i=0;i<itime;i++)
	for(j=0;j<1275;j++);
}

void lcd_init(){
	lcd_cmd(0x38);
	lcd_cmd(0x0C);
	lcd_cmd(0x01);
	lcd_cmd(0x80);
}

void lcd_cmd(unsigned char a){
	rs = 0;
	port3 = a;
	delay(5);
	en=0;
	delay(5);
	en=1;
	delay(5);
}

void lcd_data(unsigned char b){
	rs = 1;
	port3 = b;
	delay(5);
	en=0;
	delay(5);
	en=1;
	delay(5);
}

void lcd_str(unsigned char *str){
	while(*str){
		lcd_data(*str++);
	}
}