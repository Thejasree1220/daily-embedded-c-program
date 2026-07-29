#include<lpc21xx.h>
void delay_ms(unsigned int ms);
void delay_sec(unsigned int sec);
int main()
{
unsigned char pattern[] = {0x81, 0xC3, 0xE7, 0xFF,0xE7, 0xC3, 0x81, 0x00};
 int i;
  IODIR0=0xff;
  IOSET0=0xff;
  delay_ms(100);
  while(1)
    {
		 for(i = 0; i < 8; i++)
        {
            IOCLR0 = pattern[i];   // Active-low LEDs
            delay_ms(200);

            IOSET0 = pattern[i];
            delay_ms(200);
        }
	  }
}

void delay_sec(unsigned int sec)
{
  T0PR=15000000-1;
T0PC=T0TC=0;
T0TCR=1;
while(T0TC<sec);
T0TCR=0;
}
void delay_ms(unsigned int ms)
{
  T0PR=15000-1;
T0PC=T0TC=0;
T0TCR=1;
while(T0TC<ms);
T0TCR=0;
}
