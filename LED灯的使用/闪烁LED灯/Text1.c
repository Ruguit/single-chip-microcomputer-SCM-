#include<reg52.h>
sbit LED1=P2^0;
typedef  unsigned char u8;
typedef unsigned int u16;

void Keep(u16 ten){
	while(ten--);
}
main(){
	while(1){
		LED1=0;
		Keep(20000);
		LED1=1;
		Keep(20000);
	}
}