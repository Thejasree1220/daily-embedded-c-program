#include<lpc21xx.h>
#include<stdio.h>
void lcd_init(void);
void lcd_data(unsigned char data);
void lcd_cmd(unsigned int cmd);
void lcd_string(char *ptr);
void delay_ms(unsigned int ms);
int main()
{
char ch;
	lcd_init();
	lcd_cmd(0x80);
	lcd_string("enter character:");
	while(1)
	{
        ch = getchar();   

        lcd_cmd(0xC0);          
        lcd_data(ch);           
		
	}
}
void delay_ms(unsigned int ms)
{
	T0PR=15000-1;
	T0PC=T0TC=0;
	T0TCR=1;
	while(T0TC<ms);
	T0TCR=0;
}
void lcd_data(unsigned char data)
{
	unsigned int temp;
	IOCLR0 = 0xFE << 16;   
	temp = (data & 0xF0) << 16;     
	IOSET0 = temp;
	IOSET0= 1 << 17;
	IOCLR0 = 1 << 18;
	IOSET0 = 1 << 19;
	delay_ms(2);
	IOCLR0 = 1 << 19;
		
	IOCLR0 = 0xFE << 16; // Clear LCD data and control pins
	IOSET0 = (data & 0x0F) << 20; // Mask lower nibble & send to P1.20-P1.23
	IOSET0 = 1 << 17; // RS = 1 (data)
	IOCLR0 = 1 << 18; // RW = 0 (write)
	IOSET0 = 1 << 19; // EN = 1 (Enable pulse)
	delay_ms(2);
	IOCLR0 = 1 << 19; // EN = 0
}
void lcd_cmd(unsigned int cmd)
{
	unsigned int temp;
	IOCLR0 = 0xFE << 16; // Clear data pins and control pins
	temp = (cmd & 0xF0) << 16; // Mask upper nibble & shift to P1.20-P1.23
	IOSET0 = temp; // Output upper nibble first
	IOCLR0 = 1 << 17; // RS = 0 -> Command register
	IOCLR0 = 1 << 18; // RW = 0 -> Write operation
	IOSET0 = 1 << 19; // EN = 1 -> Generate latch pulse
	delay_ms(2);
	IOCLR0 = 1 << 19; // EN = 0

	IOCLR0 = 0xFE << 16; // Clear pins
	IOSET0 = (cmd & 0x0F) << 20; // Send lower nibble
	IOCLR0 = 1 << 17; // RS = 0
	IOCLR0 = 1 << 18; // RW = 0
	IOSET0 = 1 << 19; // EN = 1
	delay_ms(2);
	IOCLR0 = 1 << 19; // EN = 0
}
void lcd_init()
{
	 IODIR0 = 0xFE << 16; // Configure P1.16 - P1.23 as output
	 IOCLR0 = 1 << 19; // Ensure EN = 0 initially
	 lcd_cmd(0x02); // Return home / Reset LCD in 4-bit mode
	 lcd_cmd(0x28); // 4-bit, 2-line display, 5x7 dots format
	 lcd_cmd(0x0E); // Display ON, cursor ON
	 lcd_cmd(0x01); // Clear LCD display
}
	
void lcd_string(char *ptr)
{
	while(*ptr!=0)
	{
		lcd_data(*ptr);
		ptr++;
	}
}



