#include<lpc21xx.h>
void delay_ms(unsigned int ms);
void delay_sec(unsigned int sec);
int main()
{
  delay_sec(2);
delay_ms(200);
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
