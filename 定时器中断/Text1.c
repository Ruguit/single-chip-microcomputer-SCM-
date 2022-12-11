#include<reg52.h>
typedef unsigned char u8;
typedef unsigned int u16;

sbit led1=P2^0;

/*
	����CPUʱ��
	��Ӿ���Ϊ12MHZʱ��������Ϊ 1/12us  ״̬����Ϊ 1/6us ��������Ϊ 1us  ָ������Ϊ 1-4us 
*/

/*
	��ʱ/������ T0 ��Ӧ P3.4   T1��Ӧ P3.5 
*/ 

//��ʱ���� 
void delay(u16 ten){
	while(ten--){
	}
} 

//��ʱ������ 
void time0_init(void){//����Ϊ11.0592MHZ 
	TMOD|=0X01;//ѡ��ʱ��0ģʽ ������ʽΪ1
	//����ʱ������ֵ 1ms=��fc18��H 
	TH0=0Xfc;
	TL0=0X66; 
	ET0=1;//�򿪶�ʱ��0�ж�����
	EA=1;//�����ж�
	TR0=1;//�򿪶�ʱ�� 
}

//ͨ����ʱ��0�жϿ���D1ָʾ�Ƽ��1����˸ 
void main(){
	time0_init();
	while(1){
		
	}
}

//��ʱ��0�ⲿ�жϷ����� 1 
void time0() interrupt 1 {
	static u16 i=0;
	
	//����ʱ�����¸���ֵ 1ms=��fc18��H 
	TH0=0Xfc;
	TL0=0X66; 
	
	i++;
	if(i==1000){
		i=0;
		led1=!led1;
	}
}