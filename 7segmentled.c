#include<reg51.h>
sfr seven_seg=0x80; // 7segment at port 0 
sfr led=0xa0; // led at port 2
sfr lcd=0x90; // data of lcd at port 1 
sbit rs=P3^5; // rs pin at P3.5
sbit rw=P3^6; // rw pin at P3.6 
sbit en=P3^7; // en pin at P3.7 
void delay(); // delay function 
void cmd();
void display(); 
void main()
{
	int data1[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90}; // data of common anode 
	int i,j;
	IE=0x85; // extrnal interrupt are enabled 
	while(1)
		{
		if(i==10) 
		i=0;
		seven_seg=data1[i]; 
		delay();
		delay();
		delay(); 
		i++;
		}
}
void led_control() interrupt 0 // interrupt(INT0) 0
	{
	led=0x00;
	delay(); 
	led=0xff; 
	delay();
	}
void lcd_control() interrupt 4 // interrupt(INT1) 1
	{
	lcd=0x38;
	cmd(); 
	lcd=0x0e; 
	cmd(); 
	lcd=0x01; 
	cmd(); 
	lcd=0x06; 
	cmd();
	lcd=0x80; 
	cmd();
	lcd='T'; 
	display(); 
	lcd='E'; 
	display(); 
	lcd='A'; 
	display(); 
	lcd='M'; 
	display(); 
	lcd=' ';  
	display(); 
	lcd='0'; 
	display(); 
	lcd='3'; 
	display();
	 lcd=' '; 
	display(); 
	lcd='E'; 
	display(); 
	lcd='C'; 
	display(); 
	lcd='E'; 
	display(); 
	lcd=0xc0; 
	cmd();
	lcd='Y'; 
	display(); 
	lcd='I'; 
	display();
	lcd='T'; 
	display(); 
	}
void delay() // delay function
	{
	unsigned int i,j; 
	for(i=0;i<100;i++) 
	for(j=0;j<153;j++);
	}
void cmd()
	{
		unsigned char i;
		rs=0; rw=0; 
		en=1; 
		for(i=0;i<2;i++); 
		en=0;
		delay();
	}
void display()
	{
		unsigned char i; 
		rs=1; rw=0; 
		en=1; 
		for(i=0;i<2;i++); 
		en=0;
		delay();
	}