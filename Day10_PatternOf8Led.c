#include<lpc21xx.h>
void delay_ms(unsigned int ms);
void delay_sec(unsigned int sec);
int main()
{
int i,temp;
  IODIR0=0xff;
  IOSET0=0xff;
  delay_ms(100);
  while(1)
    {
			temp=0;
			for(i=7;i>=0;i--)
			{
				temp=temp*2+1;
					IOCLR0=temp<<i;
					delay_ms(100);	
					IOSET0=temp<<i;
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
