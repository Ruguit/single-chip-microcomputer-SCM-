#include<reg52.h>

/*
使用K3键模拟外部中断触发， K3键引脚P32默认为1 
当按下K3键时，K3键接通GND 故 引脚P32由1转变为0 实现下跳沿触发 
*/
typedef unsigned char u8;
typedef unsigned int u16;

sbit key3=P3^2;
#define LED_PORT P2

void delay (u16 ten){
	while(ten--);
} 

//外部中断0触发函数 
void exti0_init(void){
	IT0=1;//下降沿触发
	EX0=1;
	EA=1; 
}

void exti0() interrupt 0 {
	delay(1000);
	if(key3==0){
		LED_PORT=!LED_PORT;
	}
}

void main(){
	exti0_init();
	while(1){
		
	}
}