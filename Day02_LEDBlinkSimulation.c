#include<lpc21xx.h>
void delay_ms(unsigned int ms);
void delay_sec(unsigned int sec);
int main()
{
  IODIR0=0xff;
  IOSET0=0xff;
  delay_ms(500);
  while(1)
    {
      IOCLR0=0xff;
      delay_ms(500);
      IOSET0=0xff;
      delay_ms(500);
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
void delay_ms(unsigned int sec)
{
  T0PR=15000-1;
T0PC=T0TC=0;
T0TCR=1;
while(T0TC<ms);
T0TCR=0;
}
