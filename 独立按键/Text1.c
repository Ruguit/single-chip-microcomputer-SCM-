#include<reg52.h>
//ͨ���ж����Ӧ�������Ƿ�Ϊ0��ʹ��  ��������һ���GND ��ͨʱ�����͵�ƽ��
sbit K1=P3^1;
sbit K2=P3^0;
sbit K3=P3^2;
sbit K4=P3^3;

sbit LED1=P2^0;
sbit LED2=P2^1; 
sbit LED3=P2^2; 
sbit LED4=P2^3;  

#define K1_PRESS 1
#define K2_PRESS 2
#define K3_PRESS 3
#define K4_PRESS 4
#define K_NOPRESS 0

//��ʱ����
void delay_us(unsigned int ten_us){
	while(ten_us--);
}

unsigned int key_scan(unsigned char mode){
	static key=1;
	if(mode)key=1;
	if(key==1&&(K1==0||K2==0||K3==0||K4==0)){//�а������� 
		delay_us(10000);//�����Ĵ���
		key=0; 
		if(K1==0)
			return K1_PRESS;
		else if(K2==0)
			return K2_PRESS;
		else if(K3==0)
			return K3_PRESS;
		else if(K4==0)
			return K4_PRESS;
	}else if(K1==1&&K2==1&&K3==1&&K4==1){//�ް�������
		{
			key=1;
		}
		return K_NOPRESS;	 //����
	}   
}

main(){
	unsigned char key=0;
	while(1){
		key=key_scan(0); 
		//��ֵΪ0ʱ��key��ʹ��һ�κ�����0����ʱ��һֱ���Ű�����Ҳ����ı�LED�Ƶ�״̬��ֱ���ɿ�������ʹkey��ֵ��1����һ��ʹ�ð����Ż���Ч�� 
		//��ֵΪ1ʱ��keyһֱΪ1����ʱһֱ���Ű�����;ED�Ƶ�״̬��һֱ�ı䣬�����ڵ�����������
		if(key==K1_PRESS){
			LED1=~LED1; 
		}if(key==K2_PRESS){
			LED2=~LED2; 
		}if(key==K3_PRESS){
			LED3=~LED3; 
		}if(key==K4_PRESS){
			LED4=~LED4; 
		} 
	} 
}
