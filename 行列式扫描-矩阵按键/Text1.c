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
void delay_us(u16 ten_us){//ten_us=1大概延时10us 
	while(ten_us--){
	}
} 

//行列式扫描的函数 
u8 key_matrix_ranks_scan(void){
	u8 key_value=0; 
	
	//第一列按键按下 
	KEY_MATRIX_PORT=0xf7;//设第一列为低电平 P1^3为低电平
	if(KEY_MATRIX_PORT!=0xf7){//代表有按键按下  电平发生改变 
		delay_us(1000);//消抖
		switch(KEY_MATRIX_PORT){
			case 0x77:/*S1按键按下*/ key_value=1;break; 
			case 0xb7:/*S5按键按下*/ key_value=5;break;
			case 0xd7:/*S9按键按下*/ key_value=9;break;
			case 0xe7:/*S13按键按下*/ key_value=13;break;
		} 
	} 
	while(KEY_MATRIX_PORT!=0xf7);//等待按键松开 条件满足即代表按键松开
	
	//第二列按键按下 
	KEY_MATRIX_PORT=0xfb;//设第二列为低电平 P1^3为低电平
	if(KEY_MATRIX_PORT !=0xfb){//代表有按键按下  电平发生改变 
		delay_us(1000);//消抖
		switch(KEY_MATRIX_PORT){
			case 0x7b:/*S2按键按下*/ key_value=2;break; 
			case 0xbb:/*S6按键按下*/ key_value=6;break;
			case 0xdb:/*S10按键按下*/ key_value=10;break;
			case 0xeb:/*S14按键按下*/ key_value=14;break;
		} 
	} 
	while(KEY_MATRIX_PORT !=0xfb);//等待按键松开 条件满足即代表按键松开
	
	//第三列按键按下 
	KEY_MATRIX_PORT=0xfd;//设第三列为低电平 P1^3为低电平
	if(KEY_MATRIX_PORT !=0xfd){//代表有按键按下  电平发生改变 
		delay_us(1000);//消抖
		switch(KEY_MATRIX_PORT){
			case 0x7d:/*S3按键按下*/ key_value=3;break; 
			case 0xbd:/*S7按键按下*/ key_value=7;break;
			case 0xdd:/*S11按键按下*/ key_value=11;break;
			case 0xed:/*S15按键按下*/ key_value=15;break;
		} 
	} 
	while(KEY_MATRIX_PORT!=0xfd);//等待按键松开 条件满足即代表按键松开

	//第四列按键按下 
	KEY_MATRIX_PORT=0xfe;//设第四列为低电平 P1^3为低电平
	if(KEY_MATRIX_PORT !=0xfe){//代表有按键按下  电平发生改变 
		delay_us(1000);//消抖
		switch(KEY_MATRIX_PORT){
			case 0x7e:/*S4按键按下*/ key_value=4 ;break; 
			case 0xbe:/*S8按键按下*/ key_value=8;break;
			case 0xde:/*S12按键按下*/ key_value=12;break;
			case 0xee:/*S16按键按下*/ key_value=16;break;
		} 
	} 
	while(KEY_MATRIX_PORT !=0xfe);//等待按键松开 条件满足即代表按键松开
	
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