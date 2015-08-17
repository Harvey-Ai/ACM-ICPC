#include "Tank.h"
#include <string.h>
//请勿修改以上头文件
/*

您可以在这里添加您所需头文件

*/

/*

您可以在这里添加您的自定义函数

*/

//平台0回合时调用此函数获取AI名称及坦克类型信息，请勿修改此函数声明。
extern "C" InitiateInfo chooseType()
{
	InitiateInfo Info;
	Info.tank[0]=Pioneer;
	Info.tank[1]=Striker;
	Info.tank[2]=Striker;
	Info.tank[3]=Sniper;
	Info.tank[4]=Sniper;
	strcpy(Info.aiName,"MyAIName"); //AI名请勿使用中文。 
	return Info;
}


//平台从第1回合开始调用此函数获得每回合指令，请勿修改此函数声明。
extern "C" Order makeOrder(DataForAI data)
{
	Order order;
	order.type=STOP;
	return order;
}
