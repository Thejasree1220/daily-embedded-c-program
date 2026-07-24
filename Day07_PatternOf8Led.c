#include<lpc21xx.h>
void delay_ms(unsigned int ms);
void delay_sec(unsigned int sec);
int main()
{
	int i;
  IODIR0=0xff;
  IOSET0=0xff;
  delay_ms(100);
  while(1)
    {
			for(i=0;i<8;i++)
			{
					IOCLR0=1<<i;
					delay_ms(100);	
					IOSET0=1<<i;
					delay_ms(100);
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
