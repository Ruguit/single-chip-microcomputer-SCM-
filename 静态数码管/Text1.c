#include<reg52.h>
#define SMG_A_DP_PORT P0

typedef unsigned char u8;
typedef unsigned int u16; 

//共阴极数码管显示0~F的段码数据
u8 gsmg_code[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
				0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
void delay(u16 ten){
	while(ten--);
}				
main(){
	u8 i=0;
	while(1){
		for(i=0;i<17;i++){
			SMG_A_DP_PORT=gsmg_code[i];	//循环显示0-F
			delay(20000);
		}
	}
} 