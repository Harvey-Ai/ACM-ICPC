//Astar 2010 坦克大战
//Tank.h
//请勿修改此头文件 

#pragma once

#define MAP_WIDTH      21        //战场的宽度
#define MAP_HEIGHT     21		 //战场的高度
#define MAX_TANK_NUM 10	     //地图上一共十架坦克 一方五架坦克
#define MAX_SOURCE_NUM 13		 //最大矿数 具体矿数视地图而定
#define GOLD_ONE_ROUND 1		 //矿每回合提供金子数
#define MAX_GOLD_NUM   1000       //判定胜利的金子数
#define REVIVE_ROUND 2		 //死亡后复活所需要的回合数
#define MAX_NOHARM_ROUND 2		//无敌回合数
#define MAX_ROUND  400
//*****************************************************
#define STRIKER_ATTACK	2		//Striker攻击力
#define PIONEER_ATTACK	1		//Pioneer攻击力
#define SNIPER_ATTACK	1		//Sniper攻击力
#define STRIKER_LIFE	3		//Striker生命值
#define PIONEER_LIFE	9		//Pioneer生命值
#define SNIPER_LIFE		2		//Sniper生命值
#define STRIKER_RANGE	3		//Strike射程
#define PIONEER_RANGE	1		//Pioneer射程
#define SNIPER_RANGE	 5		//Sniper射程
#define SIGHT 4					//坦克视野
#define SOURCE_SIGHT   2        //矿点视野


////////////////////////////////////////////////////////////////////////////////////////



typedef enum {RED,BLUE} FlagType;                                  //0 红方 1 蓝方

typedef enum {PERVIOUS,		BRICK,		BREAKBRICK,      STONE} CellType;			 //地面的类型
//0--			1--				2--			  3--	
//可以通过的	砖块：可炸  半损坏的砖块：可炸  石头：不可炸	

typedef enum {STOP,GOUP,GODOWN,GOLEFT,GORIGHT,FIRE} OrderType;//返回指令的类型
//0  不动	 1-4  分别向上下左右四个方向走		5 开火

struct  Order  //返回指令
{
	OrderType type;  //返回指令的类型
	short row,col;       //row为从上至下的行数 col为从左至右的列数 仅当type为fire时有效
};

typedef enum { NotSource,RedSource, BlueSource, NeutralSource }SourceType; //金矿的归属
//0 不是金矿 1 红方 2 蓝方 3 中立

typedef enum {Striker, Pioneer, Sniper} TankType;//坦克的类型
//Striker: 攻击力：2   生命值：3   射程：3   视野：4
//Pioneer: 攻击力：1   生命值：9   射程：1   视野：4
//Sniper:  攻击力：1   生命值：2   射程：5   视野：4

struct InitiateInfo //用于返回初始化所需信息
{
	TankType tank[MAX_TANK_NUM/2];
	char aiName[21];
};

struct Point//点类
{
	short row,col;
};

struct MapCell
{
	CellType type;          //当前格的地面属性 
	SourceType isHereSource;//判断此格是否为金矿 0 不是金矿 1 红方矿 2 蓝方矿 3 中立矿
	short whoIsHere;        //占据此格的坦克AI的编号[0,MAX_TANK_NUM)，若为-1表示无人
	//系统自动判断人是否可以在当前格
};

struct TankData		     //装载坦克信息
{
	short ID;				 //记录坦克编号（与坦克数组的下标一致）
	FlagType flag;		 //属于哪一方
	short row,col;           //记录坦克在赛场中的位置，row从上向下，col从左向右，均从1开始
	//坦克不在场上或不在视野内时，赋值为(-2,-2)
	TankType type;    //记录坦克的类型
	short StartRow,StartCol; //坦克出发的位置，在比赛最初初始化，如果坦克死亡后复活，则在此位置出现
	short attack;            //攻击力
	short life;	             //生命值 life = 0 代表死亡
	short range;             //攻击范围
	long revive;		 //如果坦克处于死亡状态，revive=round + REVIVE_ROUND (即当前回合加复活所需要的回合数，也就是坦克复活的回合);否则revive=-1; 
	short noharm;           //剩余的无敌回合数 默认为0 坦克刚复活时为MAX_NOHARM_ROUND 此后每回合减1
};

struct DataForAI									 //装载传递给坦克AI的信息
{
	struct MapCell map[MAP_HEIGHT+2][MAP_WIDTH +2];		 //当前的赛场地图，从上到下，从左到右，行优先
	//比赛场有效区域头尾各多一行，左右各多一列，便于编写算法
	struct TankData tank[MAX_TANK_NUM];				 //所有参赛坦克的信息
	struct Point source[MAX_SOURCE_NUM];                 //矿点位置信息 从左至右，从上到下的顺序标号为0到totalSource-1
	FlagType myFlag;								 //自己属于哪一方
	short myID;										 //自己的ID是多少
	short round;									     //当前回合数，第0回合初始化地图与AI坦克类型信息，可行动的第一回合为1	
	short redGoldNum,blueGoldNum;                    //当前双方的金子数
	short redScore,blueScore;                     //当前双方比分
	short redSource,blueSource,totalSource;          //当前双方占有矿点数 当前总矿点数
	int redTime,blueTime;                       //当前双方AI总用时数
};	

extern "C" Order makeOrder(DataForAI data);
extern "C" InitiateInfo chooseType();
