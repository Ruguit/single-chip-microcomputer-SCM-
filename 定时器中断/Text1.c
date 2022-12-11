#include<reg52.h>
typedef unsigned char u8;
typedef unsigned int u16;

sbit led1=P2^0;

/*
	关于CPU时序：
	外接晶振为12MHZ时，震荡周期为 1/12us  状态周期为 1/6us 机器周期为 1us  指令周期为 1-4us 
*/

/*
	定时/计数器 T0 对应 P3.4   T1对应 P3.5 
*/ 

//延时函数 
void delay(u16 ten){
	while(ten--){
	}
} 

//定时器配置 
void time0_init(void){//晶振为11.0592MHZ 
	TMOD|=0X01;//选择定时器0模式 工作方式为1
	//给定时器赋初值 1ms=（fc18）H 
	TH0=0Xfc;
	TL0=0X66; 
	ET0=1;//打开定时器0中断允许
	EA=1;//打开总中断
	TR0=1;//打开定时器 
}

//通过定时器0中断控制D1指示灯间隔1秒闪烁 
void main(){
	time0_init();
	while(1){
		
	}
}

//定时器0外部中断服务函数 1 
void time0() interrupt 1 {
	static u16 i=0;
	
	//给定时器重新赋初值 1ms=（fc18）H 
	TH0=0Xfc;
	TL0=0X66; 
	
	i++;
	if(i==1000){
		i=0;
		led1=!led1;
	}
}