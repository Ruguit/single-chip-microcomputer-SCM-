#include<reg52.h>

typedef unsigned char u8;
typedef unsigned int u16;

//通过74HC595模块控制LED点阵以一行循环显示
 
//控制管脚  并将硬件的控制管脚 OE短接到GND 
sbit SRCLK =P3^6;//移位寄存器 
sbit rCLK =P3^5;//存储寄存器 
sbit SER =P3^4;//串行输入管脚 

//定义控制列的端口
#define LEDDZ_COL_PORT P0

//SER需要输入的数据
u8 ghc595_buf[8] ={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80}; 
  
/*
延时函数 ten_us =1000 大概延时10微秒 
*/
void delay_us(u16 ten_us){
	while(ten_us--);
}

void hc595_write_date(u8 dat){
	u8 i=0;
	for(i=0;i<8;i++){//从最低位开始识别 传输给最高位 所以要先将最高位位移到最低位 
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
			hc595_write_date(0x00);//消隐 
			hc595_write_date(ghc595_buf[i]);
			delay_us(50000);
		}
	}
}