  #include<reg52.h>
typedef unsigned int u16 ;
typedef unsigned char u8 ;
//通过s1-s16按键，在数码管显示0-F 

#define KEY_MATRIX_PORT P1 //矩阵按键端口 

#define SMG_A_DP_PORT P0 //数码管端口 

//共阴极数码管显示0~F的段码数据
u8 gsmg_code[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
				0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};

//延时函数 
void delay_10us(u16 ten_us){//ten_us=1大概延时10us 
	while(ten_us--){
	}
} 

/*******************************************************************************
* 函 数 名       : key_matrix_flip_scan
* 函数功能		 : 使用线翻转扫描方法，检测矩阵按键是否按下，按下则返回对应键值
* 输    入       : 无
* 输    出    	 : key_value：1-16，对应S1-S16键，
				   0：按键未按下
*******************************************************************************/
u8 key_matrix_flip_scan(void)
{
	static u8 key_value=0;

	KEY_MATRIX_PORT=0x0f;//给所有行赋值0，列全为1
	if(KEY_MATRIX_PORT!=0x0f)//判断按键是否按下
	{
		delay_10us(1000);//消抖
		if(KEY_MATRIX_PORT!=0x0f)
		{
			//测试列
			KEY_MATRIX_PORT=0x0f;
			switch(KEY_MATRIX_PORT)//保存行为0，按键按下后的列值	
			{
				case 0x07: key_value=1;break;
				case 0x0b: key_value=2;break;
				case 0x0d: key_value=3;break;
				case 0x0e: key_value=4;break;
			}
			//测试行
			KEY_MATRIX_PORT=0xf0;
			switch(KEY_MATRIX_PORT)//保存列为0，按键按下后的键值	
			{
				case 0x70: key_value=key_value;break;
				case 0xb0: key_value=key_value+4;break;
				case 0xd0: key_value=key_value+8;break;
				case 0xe0: key_value=key_value+12;break;
			}
			while(KEY_MATRIX_PORT!=0xf0);//等待按键松开	
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