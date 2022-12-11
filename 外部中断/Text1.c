#include<reg52.h>

/*
ʹ��K3��ģ���ⲿ�жϴ����� K3������P32Ĭ��Ϊ1 
������K3��ʱ��K3����ͨGND �� ����P32��1ת��Ϊ0 ʵ�������ش��� 
*/
typedef unsigned char u8;
typedef unsigned int u16;

sbit key3=P3^2;
#define LED_PORT P2

void delay (u16 ten){
	while(ten--);
} 

//�ⲿ�ж�0�������� 
void exti0_init(void){
	IT0=1;//�½��ش���
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