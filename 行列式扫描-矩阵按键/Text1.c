	#include<reg52.h>
typedef unsigned int u16 ;
typedef unsigned char u8 ;
//ͨ��s1-s16���������������ʾ0-F 

#define KEY_MATRIX_PORT P1 //���󰴼��˿� 

#define SMG_A_DP_PORT P0 //����ܶ˿� 

//�������������ʾ0~F�Ķ�������
u8 gsmg_code[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
				0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};

//��ʱ���� 
void delay_us(u16 ten_us){//ten_us=1�����ʱ10us 
	while(ten_us--){
	}
} 

//����ʽɨ��ĺ��� 
u8 key_matrix_ranks_scan(void){
	u8 key_value=0; 
	
	//��һ�а������� 
	KEY_MATRIX_PORT=0xf7;//���һ��Ϊ�͵�ƽ P1^3Ϊ�͵�ƽ
	if(KEY_MATRIX_PORT!=0xf7){//�����а�������  ��ƽ�����ı� 
		delay_us(1000);//����
		switch(KEY_MATRIX_PORT){
			case 0x77:/*S1��������*/ key_value=1;break; 
			case 0xb7:/*S5��������*/ key_value=5;break;
			case 0xd7:/*S9��������*/ key_value=9;break;
			case 0xe7:/*S13��������*/ key_value=13;break;
		} 
	} 
	while(KEY_MATRIX_PORT!=0xf7);//�ȴ������ɿ� �������㼴�������ɿ�
	
	//�ڶ��а������� 
	KEY_MATRIX_PORT=0xfb;//��ڶ���Ϊ�͵�ƽ P1^3Ϊ�͵�ƽ
	if(KEY_MATRIX_PORT !=0xfb){//�����а�������  ��ƽ�����ı� 
		delay_us(1000);//����
		switch(KEY_MATRIX_PORT){
			case 0x7b:/*S2��������*/ key_value=2;break; 
			case 0xbb:/*S6��������*/ key_value=6;break;
			case 0xdb:/*S10��������*/ key_value=10;break;
			case 0xeb:/*S14��������*/ key_value=14;break;
		} 
	} 
	while(KEY_MATRIX_PORT !=0xfb);//�ȴ������ɿ� �������㼴�������ɿ�
	
	//�����а������� 
	KEY_MATRIX_PORT=0xfd;//�������Ϊ�͵�ƽ P1^3Ϊ�͵�ƽ
	if(KEY_MATRIX_PORT !=0xfd){//�����а�������  ��ƽ�����ı� 
		delay_us(1000);//����
		switch(KEY_MATRIX_PORT){
			case 0x7d:/*S3��������*/ key_value=3;break; 
			case 0xbd:/*S7��������*/ key_value=7;break;
			case 0xdd:/*S11��������*/ key_value=11;break;
			case 0xed:/*S15��������*/ key_value=15;break;
		} 
	} 
	while(KEY_MATRIX_PORT!=0xfd);//�ȴ������ɿ� �������㼴�������ɿ�

	//�����а������� 
	KEY_MATRIX_PORT=0xfe;//�������Ϊ�͵�ƽ P1^3Ϊ�͵�ƽ
	if(KEY_MATRIX_PORT !=0xfe){//�����а�������  ��ƽ�����ı� 
		delay_us(1000);//����
		switch(KEY_MATRIX_PORT){
			case 0x7e:/*S4��������*/ key_value=4 ;break; 
			case 0xbe:/*S8��������*/ key_value=8;break;
			case 0xde:/*S12��������*/ key_value=12;break;
			case 0xee:/*S16��������*/ key_value=16;break;
		} 
	} 
	while(KEY_MATRIX_PORT !=0xfe);//�ȴ������ɿ� �������㼴�������ɿ�
	
	return key_value; 
} 

main(){
	u8 key=0;
	while(1){
		key=key_matrix_ranks_scan();
		if(key!=0){
			SMG_A_DP_PORT=gsmg_code[key-1];
		}
	}	
}