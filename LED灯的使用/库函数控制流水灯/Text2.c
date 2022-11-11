#include<reg52.h>
#include<intrins.h> 
#define LED_PROT	P2 //宏定义P2端口
typedef  unsigned char u8;
typedef unsigned int u16;
//延时函数 
void Keep(u16 ten){
	while(ten--);
}
main(){
	u8 i=0;
	LED_PROT=0xfe;//最低位为0，其余为1  0xfe:1111 1110 
	Keep(20000);
	while(1)
	{
		 for(i=0;i<7;i++)
		 {
		 	LED_PROT=_crol_(LED_PROT,1);//向左移动 第八位挤出 其余依次左移1位 第八位顶替第一位
		 	Keep(20000);
		 }
		 Keep(20000);
		 for(i=0;i<7;i++)
		 {
		 	LED_PROT=_cror_(LED_PROT,1);//与上面的函数相反的运行原理；
		 	Keep(20000);
		 }
	}
}