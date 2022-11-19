#include<reg52.h>

typedef unsigned char u8;
typedef unsigned int u16;

//ͨ��74HC595ģ�����LED������һ��ѭ����ʾ
 
//���ƹܽ�  ����Ӳ���Ŀ��ƹܽ� OE�̽ӵ�GND 
sbit SRCLK =P3^6;//��λ�Ĵ��� 
sbit rCLK =P3^5;//�洢�Ĵ��� 
sbit SER =P3^4;//��������ܽ� 

//��������еĶ˿�
#define LEDDZ_COL_PORT P0

//SER��Ҫ���������
u8 ghc595_buf[8] ={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80}; 
  
/*
��ʱ���� ten_us =1000 �����ʱ10΢�� 
*/
void delay_us(u16 ten_us){
	while(ten_us--);
}

void hc595_write_date(u8 dat){
	u8 i=0;
	for(i=0;i<8;i++){//�����λ��ʼʶ�� ��������λ ����Ҫ�Ƚ����λλ�Ƶ����λ 
		SER=dat>>7;
		dat<<=1;
		SRCLK=0;
		delay_us(1);
		SRCLK=1; 
		delay_us(1);
	}
	rCLK=0;
	delay_us(1);
	rCLK=1;
} 

void main(){
	u8 i=0;
	LEDDZ_COL_PORT=0x00; 
	while(1){
		for(i=0;i<8;i++){
			hc595_write_date(0x00);//���� 
			hc595_write_date(ghc595_buf[i]);
			delay_us(50000);
		}
	}
}