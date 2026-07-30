#include<lpc21xx.h>
#define sw ((IOPIN0>>14)&1)
#define led (1<<17)
int main()
{
IODIR0=led;
IOSET0=led;
while(1)
{
if(sw==0)
{
IOCLR0=led;
}
else
{
IOSET0=led;
}
}
}
