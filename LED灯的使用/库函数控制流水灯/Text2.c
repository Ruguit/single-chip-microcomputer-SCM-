#include<reg52.h>
#include<intrins.h> 
#define LED_PROT	P2 //�궨��P2�˿�
typedef  unsigned char u8;
typedef unsigned int u16;
//��ʱ���� 
void Keep(u16 ten){
	while(ten--);
}
main(){
	u8 i=0;
	LED_PROT=0xfe;//���λΪ0������Ϊ1  0xfe:1111 1110 
	Keep(20000);
	while(1)
	{
		 for(i=0;i<7;i++)
		 {
		 	LED_PROT=_crol_(LED_PROT,1);//�����ƶ� �ڰ�λ���� ������������1λ �ڰ�λ�����һλ
		 	Keep(20000);
		 }
		 Keep(20000);
		 for(i=0;i<7;i++)
		 {
		 	LED_PROT=_cror_(LED_PROT,1);//������ĺ����෴������ԭ��
		 	Keep(20000);
		 }
	}
}