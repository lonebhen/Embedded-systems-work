#include <reg51.h>

void delay(unsigned int i);
void lcd_init(void);
void lcd_cmd(unsigned char a);
void lcd_data(unsigned char b);
void lcd_str(unsigned char *str);
sbit rs = P2^0;
sbit en = P2^1;
sfr port3 = 0xB0;

sbit r1 = P1^0;
sbit r2 = P1^1;
sbit r3 = P1^2;
sbit r4 = P1^3;

sbit c1 = P1^4;
sbit c2 = P1^5;
sbit c3 = P1^6;
void main(void){
	lcd_init();
	lcd_str(" WELCOME TO \n");
	lcd_cmd(0xC0);
	lcd_str(" QUANTICO ");
	lcd_cmd(0x01);
	lcd_str("PRESS ANY KEY ");
	lcd_cmd(0xC0);
	
while(1){
	delay(10);
	r1=r2=r3=r4=0;
	c1=c2=c3=1;
	
	
	if(c1==0){
		r1=r2=r3=r4=1;
		c1=c2=c3=0;
		
		if(r1==0)
			lcd_data('1');
		if(r2==0)
			lcd_data('4');
		if(r3==0)
			lcd_data('7');
		if(r4==0)
			lcd_data('*');
		
	}
	else if(c2==0){
		r1=r2=r3=r4=1;
		c1=c2=c3=0;
		
		if(r1==0)
			lcd_data('2');
		if(r2==0)
			lcd_data('5');
		if(r3==0)
			lcd_data('8');
		if(r4==0)
			lcd_data('0');
		
	}
	else if(c3==0){
		r1=r2=r3=r4=1;
		c1=c2=c3=0;
		
		if(r1==0)
			lcd_data('3');
		if(r2==0)
			lcd_data('6');
		if(r3==0)
			lcd_data('9');
		if(r4==0)
			lcd_data('#');
		
	}
}
}

	
	
	


void delay(unsigned int itime){
	unsigned i,j;
	for(i=0;i<itime;i++)
	for(j=0;j<1275;j++);
}

void lcd_cmd(unsigned char a){
	rs = 0;
	port3 = a;
	en = 0;
	delay(5);
	en = 1;
	delay(5);
}

void lcd_data(unsigned char b)
{
	rs = 1;
	port3 = b;
	en = 0;
	delay(5);
	en = 1;
	delay(5);
}

void lcd_init(){
	lcd_cmd(0x38);
	lcd_cmd(0x0C);
	lcd_cmd(0x01);
	lcd_cmd(0x80);
}

void lcd_str(unsigned char *str){
	while(*str){
		lcd_data(*str++);
	}
}
