#include "Tank.h"
#include <string.h>
//�����޸�����ͷ�ļ�
/*

���������������������ͷ�ļ�

*/

/*

��������������������Զ��庯��

*/

//ƽ̨0�غ�ʱ���ô˺�����ȡAI���Ƽ�̹��������Ϣ�������޸Ĵ˺���������
extern "C" InitiateInfo chooseType()
{
	InitiateInfo Info;
	Info.tank[0]=Pioneer;
	Info.tank[1]=Striker;
	Info.tank[2]=Striker;
	Info.tank[3]=Sniper;
	Info.tank[4]=Sniper;
	strcpy(Info.aiName,"MyAIName"); //AI������ʹ�����ġ� 
	return Info;
}


//ƽ̨�ӵ�1�غϿ�ʼ���ô˺������ÿ�غ�ָ������޸Ĵ˺���������
extern "C" Order makeOrder(DataForAI data)
{
	Order order;
	order.type=STOP;
	return order;
}
