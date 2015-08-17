//Astar 2010 ̹�˴�ս
//Tank.h
//�����޸Ĵ�ͷ�ļ� 

#pragma once

#define MAP_WIDTH      21        //ս���Ŀ��
#define MAP_HEIGHT     21		 //ս���ĸ߶�
#define MAX_TANK_NUM 10	     //��ͼ��һ��ʮ��̹�� һ�����̹��
#define MAX_SOURCE_NUM 13		 //������ ��������ӵ�ͼ����
#define GOLD_ONE_ROUND 1		 //��ÿ�غ��ṩ������
#define MAX_GOLD_NUM   1000       //�ж�ʤ���Ľ�����
#define REVIVE_ROUND 2		 //�����󸴻�����Ҫ�Ļغ���
#define MAX_NOHARM_ROUND 2		//�޵лغ���
#define MAX_ROUND  400
//*****************************************************
#define STRIKER_ATTACK	2		//Striker������
#define PIONEER_ATTACK	1		//Pioneer������
#define SNIPER_ATTACK	1		//Sniper������
#define STRIKER_LIFE	3		//Striker����ֵ
#define PIONEER_LIFE	9		//Pioneer����ֵ
#define SNIPER_LIFE		2		//Sniper����ֵ
#define STRIKER_RANGE	3		//Strike���
#define PIONEER_RANGE	1		//Pioneer���
#define SNIPER_RANGE	 5		//Sniper���
#define SIGHT 4					//̹����Ұ
#define SOURCE_SIGHT   2        //�����Ұ


////////////////////////////////////////////////////////////////////////////////////////



typedef enum {RED,BLUE} FlagType;                                  //0 �췽 1 ����

typedef enum {PERVIOUS,		BRICK,		BREAKBRICK,      STONE} CellType;			 //���������
//0--			1--				2--			  3--	
//����ͨ����	ש�飺��ը  ���𻵵�ש�飺��ը  ʯͷ������ը	

typedef enum {STOP,GOUP,GODOWN,GOLEFT,GORIGHT,FIRE} OrderType;//����ָ�������
//0  ����	 1-4  �ֱ������������ĸ�������		5 ����

struct  Order  //����ָ��
{
	OrderType type;  //����ָ�������
	short row,col;       //rowΪ�������µ����� colΪ�������ҵ����� ����typeΪfireʱ��Ч
};

typedef enum { NotSource,RedSource, BlueSource, NeutralSource }SourceType; //���Ĺ���
//0 ���ǽ�� 1 �췽 2 ���� 3 ����

typedef enum {Striker, Pioneer, Sniper} TankType;//̹�˵�����
//Striker: ��������2   ����ֵ��3   ��̣�3   ��Ұ��4
//Pioneer: ��������1   ����ֵ��9   ��̣�1   ��Ұ��4
//Sniper:  ��������1   ����ֵ��2   ��̣�5   ��Ұ��4

struct InitiateInfo //���ڷ��س�ʼ��������Ϣ
{
	TankType tank[MAX_TANK_NUM/2];
	char aiName[21];
};

struct Point//����
{
	short row,col;
};

struct MapCell
{
	CellType type;          //��ǰ��ĵ������� 
	SourceType isHereSource;//�жϴ˸��Ƿ�Ϊ��� 0 ���ǽ�� 1 �췽�� 2 ������ 3 ������
	short whoIsHere;        //ռ�ݴ˸��̹��AI�ı��[0,MAX_TANK_NUM)����Ϊ-1��ʾ����
	//ϵͳ�Զ��ж����Ƿ�����ڵ�ǰ��
};

struct TankData		     //װ��̹����Ϣ
{
	short ID;				 //��¼̹�˱�ţ���̹��������±�һ�£�
	FlagType flag;		 //������һ��
	short row,col;           //��¼̹���������е�λ�ã�row�������£�col�������ң�����1��ʼ
	//̹�˲��ڳ��ϻ�����Ұ��ʱ����ֵΪ(-2,-2)
	TankType type;    //��¼̹�˵�����
	short StartRow,StartCol; //̹�˳�����λ�ã��ڱ��������ʼ�������̹�������󸴻���ڴ�λ�ó���
	short attack;            //������
	short life;	             //����ֵ life = 0 ��������
	short range;             //������Χ
	long revive;		 //���̹�˴�������״̬��revive=round + REVIVE_ROUND (����ǰ�غϼӸ�������Ҫ�Ļغ�����Ҳ����̹�˸���Ļغ�);����revive=-1; 
	short noharm;           //ʣ����޵лغ��� Ĭ��Ϊ0 ̹�˸ո���ʱΪMAX_NOHARM_ROUND �˺�ÿ�غϼ�1
};

struct DataForAI									 //װ�ش��ݸ�̹��AI����Ϣ
{
	struct MapCell map[MAP_HEIGHT+2][MAP_WIDTH +2];		 //��ǰ��������ͼ�����ϵ��£������ң�������
	//��������Ч����ͷβ����һ�У����Ҹ���һ�У����ڱ�д�㷨
	struct TankData tank[MAX_TANK_NUM];				 //���в���̹�˵���Ϣ
	struct Point source[MAX_SOURCE_NUM];                 //���λ����Ϣ �������ң����ϵ��µ�˳����Ϊ0��totalSource-1
	FlagType myFlag;								 //�Լ�������һ��
	short myID;										 //�Լ���ID�Ƕ���
	short round;									     //��ǰ�غ�������0�غϳ�ʼ����ͼ��AI̹��������Ϣ�����ж��ĵ�һ�غ�Ϊ1	
	short redGoldNum,blueGoldNum;                    //��ǰ˫���Ľ�����
	short redScore,blueScore;                     //��ǰ˫���ȷ�
	short redSource,blueSource,totalSource;          //��ǰ˫��ռ�п���� ��ǰ�ܿ����
	int redTime,blueTime;                       //��ǰ˫��AI����ʱ��
};	

extern "C" Order makeOrder(DataForAI data);
extern "C" InitiateInfo chooseType();
