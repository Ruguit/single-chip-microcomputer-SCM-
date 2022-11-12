#include<reg52.h>
#define SMG_A_DP_PORT P0

typedef unsigned char u8;
typedef unsigned int u16; 
//定义位选
sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4; 

//共阴极数码管显示0~7的段码数据
u8 gsmg_code[8]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,};
				
//延时函数				
void delay(u16 ten){
	while(ten--);
}
//位选函数+动态显示数字 
void smg_display(i)
{
	   	switch(i)//位选
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
		SMG_A_DP_PORT=gsmg_code[i];//传送段选数据
}		
main(){
	while(1){
		u8 i=0;
		for(i=0;i<8;i++)
		{
	 	 smg_display(i); 
	  	delay(100);//延时一段时间，等待显示稳定
		}
	}		
} 