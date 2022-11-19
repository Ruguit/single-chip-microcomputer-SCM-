#include<reg52.h>

typedef unsigned char u8;
typedef unsigned int u16;

//通过4块74HC595模块控制16*16 LED点阵以一行循环显示
 
//控制管脚  并将硬件的控制管脚 OE短接到GND 
sbit SRCLK =P3^6;//移位寄存器 
sbit rCLK =P3^5;//存储寄存器 
sbit SER =P3^4;//串行输入管脚 



//SER需要输入的数据
u8 ghc595_buf[8] ={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80}; 
  
/*
延时函数 ten_us =1000 大概延时10微秒 
*/
void delay_us(u16 ten_us){
	while(ten_us--);
}

void hc595_write_date(u8 dat1,u8 dat2,u8 dat3,u8 dat4){
	u8 i=0;
	//从最低位开始识别 传输给最高位 所以要先将最高位位移到最低位 
	for(i=0;i<8;i++){
		SER=dat4>>7;
		dat4<<=1;
		SRCLK=0;
		delay_us(1);
		SRCLK=1; 
		delay_us(1);
	}
	for(i=0;i<8;i++){
		SER=dat3>>7;
		dat3<<=1;
		SRCLK=0;
		delay_us(1);
		SRCLK=1; 
		delay_us(1);
	}
	for(i=0;i<8;i++){
		SER=dat1>>7;
		dat2<<=1;
		SRCLK=0;
		delay_us(1);
		SRCLK=1; 
		delay_us(1);
	}
	for(i=0;i<8;i++){
		SER=dat1>>7;
		dat1<<=1;
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
	while(1){
		for(i=0;i<8;i++){
			hc595_write_date(ghc595_buf[i],0,0,0); 
			delay_us(50000);
		}
		for(i=0;i<8;i++){
			hc595_write_date(0,ghc595_buf[i],0,0); 
			delay_us(50000);
		}
	}
}