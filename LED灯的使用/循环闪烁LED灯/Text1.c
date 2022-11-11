#include<reg52.h>
#define LED_PROT	P2 //ºê¶¨ÒåP2¶Ë¿Ú
typedef  unsigned char u8;
typedef unsigned int u16;

void Keep(u16 ten){
	while(ten--);
}
main(){
	u8 i=0;
	while(1)
	{
		 for(i=0;i<8;i++)
		 {
		 	LED_PROT=~(0X01<<i);
			Keep(20000);
		 }
	}
}