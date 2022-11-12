#include<reg52.h>
#define SMG_A_DP_PORT P0

typedef unsigned char u8;
typedef unsigned int u16; 
//����λѡ
sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4; 

//�������������ʾ0~7�Ķ�������
u8 gsmg_code[8]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,};
				
//��ʱ����				
void delay(u16 ten){
	while(ten--);
}
//λѡ����+��̬��ʾ���� 
void smg_display(i)
{
	   	switch(i)//λѡ
		{
			case 0: LSC=1;LSB=1;LSA=1;break;
			case 1: LSC=1;LSB=1;LSA=0;break;
			case 2: LSC=1;LSB=0;LSA=1;break;
			case 3: LSC=1;LSB=0;LSA=0;break;
			case 4: LSC=0;LSB=1;LSA=1;break;
			case 5: LSC=0;LSB=1;LSA=0;break;
			case 6: LSC=0;LSB=0;LSA=1;break;
			case 7: LSC=0;LSB=0;LSA=0;break;
		}
		SMG_A_DP_PORT=gsmg_code[i];//���Ͷ�ѡ����
}		
main(){
	while(1){
		u8 i=0;
		for(i=0;i<8;i++)
		{
	 	 smg_display(i); 
	  	delay(100);//��ʱһ��ʱ�䣬�ȴ���ʾ�ȶ�
		}
	}		
} 