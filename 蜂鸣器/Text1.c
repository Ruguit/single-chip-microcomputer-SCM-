#include<reg52.h>

typedef unsigned char u8;
typedef unsigned int u16;

sbit BEEP=P2^5;

void Keep(u16 ten){
	while(ten--){}
}

main(){
	u16 i=2000; 
	while(1){
		while(i--){
//BEEP=!BEEP;	 使用一定频率的01脉冲才能时蜂鸣器响应
//Keep(1000);	   
				BEEP=0;
				Keep(0.1);
				BEEP=1;
				Keep(250) ;
		}
		i=0;
		BEEP=0;
	}
}