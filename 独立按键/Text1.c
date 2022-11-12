#include<reg52.h>
//通过判断相对应的引脚是否为0来使用  独立按键一般接GND 导通时产生低电平。
sbit K1=P3^1;
sbit K2=P3^0;
sbit K3=P3^2;
sbit K4=P3^3;

sbit LED1=P2^0;
sbit LED2=P2^1; 
sbit LED3=P2^2; 
sbit LED4=P2^3;  

#define K1_PRESS 1
#define K2_PRESS 2
#define K3_PRESS 3
#define K4_PRESS 4
#define K_NOPRESS 0

//延时函数
void delay_us(unsigned int ten_us){
	while(ten_us--);
}

unsigned int key_scan(unsigned char mode){
	static key=1;
	if(mode)key=1;
	if(key==1&&(K1==0||K2==0||K3==0||K4==0)){//有按键按下 
		delay_us(10000);//消抖的处理
		key=0; 
		if(K1==0)
			return K1_PRESS;
		else if(K2==0)
			return K2_PRESS;
		else if(K3==0)
			return K3_PRESS;
		else if(K4==0)
			return K4_PRESS;
	}else if(K1==1&&K2==1&&K3==1&&K4==1){//无按键按下
		{
			key=1;
		}
		return K_NOPRESS;	 //保持
	}   
}

main(){
	unsigned char key=0;
	while(1){
		key=key_scan(0); 
		//当值为0时，key在使用一次后变成了0，这时即一直按着按键，也不会改变LED灯的状态，直到松开按键，使key的值变1，下一次使用按键才会生效。 
		//当值为1时，key一直为1，这时一直按着按键，;ED灯的状态会一直改变，类似于电视音量键。
		if(key==K1_PRESS){
			LED1=~LED1; 
		}if(key==K2_PRESS){
			LED2=~LED2; 
		}if(key==K3_PRESS){
			LED3=~LED3; 
		}if(key==K4_PRESS){
			LED4=~LED4; 
		} 
	} 
}
