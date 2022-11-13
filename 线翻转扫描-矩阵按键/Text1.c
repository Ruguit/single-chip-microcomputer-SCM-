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
void delay_10us(u16 ten_us){//ten_us=1�����ʱ10us 
	while(ten_us--){
	}
} 

/*******************************************************************************
* �� �� ��       : key_matrix_flip_scan
* ��������		 : ʹ���߷�תɨ�跽���������󰴼��Ƿ��£������򷵻ض�Ӧ��ֵ
* ��    ��       : ��
* ��    ��    	 : key_value��1-16����ӦS1-S16����
				   0������δ����
*******************************************************************************/
u8 key_matrix_flip_scan(void)
{
	static u8 key_value=0;

	KEY_MATRIX_PORT=0x0f;//�������и�ֵ0����ȫΪ1
	if(KEY_MATRIX_PORT!=0x0f)//�жϰ����Ƿ���
	{
		delay_10us(1000);//����
		if(KEY_MATRIX_PORT!=0x0f)
		{
			//������
			KEY_MATRIX_PORT=0x0f;
			switch(KEY_MATRIX_PORT)//������Ϊ0���������º����ֵ	
			{
				case 0x07: key_value=1;break;
				case 0x0b: key_value=2;break;
				case 0x0d: key_value=3;break;
				case 0x0e: key_value=4;break;
			}
			//������
			KEY_MATRIX_PORT=0xf0;
			switch(KEY_MATRIX_PORT)//������Ϊ0���������º�ļ�ֵ	
			{
				case 0x70: key_value=key_value;break;
				case 0xb0: key_value=key_value+4;break;
				case 0xd0: key_value=key_value+8;break;
				case 0xe0: key_value=key_value+12;break;
			}
			while(KEY_MATRIX_PORT!=0xf0);//�ȴ������ɿ�	
		}
	}
	else
		key_value=0;		
	
	return key_value;		
 }

main(){
	u8 key=0;
	while(1){
		key=key_matrix_flip_scan();
		if(key!=0){
			SMG_A_DP_PORT=gsmg_code[key-1];
		}
	}	
}