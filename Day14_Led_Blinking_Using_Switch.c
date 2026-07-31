#include<lpc21xx.h>
#define sw ((IOPIN0>>14)&1)
#define led (1<<17)
void delay_ms(unsigned int ms);
int main()
{
IODIR0=led;
IOSET0=led;
while(1)
{
if(sw==0)
{
IOCLR0=led;
	delay_ms(500);
	IOSET0=led;
	delay_ms(500);
}
else
{
IOSET0=led;
}
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
