#include "Tank.h"
#include <string.h>
//请勿修改以上头文件
/*

您可以在这里添加您所需头文件

*/
#include <math.h>
#include <time.h>
#include <queue>
#include <vector>
using namespace std;
/*

您可以在这里添加您的自定义函数

*/
#define MAX 5000
struct Node
{
	Point p;
	int cost;

};

bool operator <(const Node &n1,const Node &n2)
{
	return n1.cost>n2.cost;
}

//计算两个点间的距离
short disPoint(Point p1,Point p2)
{
	return abs(p1.col-p2.col)+abs(p1.row-p2.row);
}

//计算两坦克的距离
short disTank(TankData tank1,TankData tank2)
{
	return abs(tank1.col-tank2.col)+abs(tank1.row-tank2.row);
}
Order decide(DataForAI data);
//判断id的坦克在射击范围是否有敌军坦克
short getAttackEnemy(short id,TankData tank[])
{
	short low,up;
	if(id<5){low=MAX_TANK_NUM/2;up=MAX_TANK_NUM;}
	else{low=0;up=MAX_TANK_NUM/2;}
	for(short i=low;i<up;i++)
	{
		if(abs(tank[i].col-tank[id].col)+abs(tank[i].row-tank[id].row)<=tank[id].range)
			return i;
	}
	return -1;
}

//判断视野为range范围是否有敌军坦克，返回最近的敌军坦克id
short getRangeEnemy(DataForAI data,short id,short range,short &step)
{
	FlagType ft=data.tank[id].flag;
	Point p;
	p.col=data.tank[id].col;
	p.row=data.tank[id].row;

	for(short k=1;k<=range;k++)
	{
		step=k;
		for(short i=-k;i<=k;i++)
		{
			short j=k-abs(i);
			if(p.row+i>=MAP_HEIGHT+2||p.row+i<=0)continue;
			if(p.col+j>=MAP_WIDTH+2||p.col+j<=0)continue;
			if(data.map[p.row+i][p.col+j].whoIsHere==-1)continue;
			if(data.tank[data.map[p.row+i][p.col+j].whoIsHere].flag!=ft)return data.map[p.row+i][p.col+j].whoIsHere;
			if(j)j=-j;
			if(p.row+i>=MAP_HEIGHT+2||p.row+i<=0)continue;
			if(p.col+j>=MAP_WIDTH+2||p.col+j<=0)continue;
			if(data.map[p.row+i][p.col+j].whoIsHere==-1)continue;
			if(data.tank[data.map[p.row+i][p.col+j].whoIsHere].flag!=ft)return data.map[p.row+i][p.col+j].whoIsHere;
		}
	}
	return -1;
}


bool isMySource(MapCell mp,FlagType ft)
{
	if((mp.isHereSource==RedSource&&ft==RED)||(mp.isHereSource==BlueSource&&ft==BLUE))
		return true;
	return false;
}
//判断视野为2的距离是否有需要占领的矿,有则返回矿号否则返回-1
short getMyNeedSource(DataForAI data, short curId)
{
	Point p;
	p.col=data.tank[curId].col;
	p.row=data.tank[curId].row;
	for(short i=0;i<data.totalSource;i++)
	{
		if(disPoint(p,data.source[i])>2)
			continue;
		if(isMySource(data.map[data.source[i].row][data.source[i].col],data.tank[curId].flag))
			continue;
		if(disPoint(p,data.source[i])<2)
			return i;
		if(data.source[i].col<p.col){
			if(data.source[i].row<p.row&&(data.map[p.row][p.col-1].type==PERVIOUS||data.map[p.row-1][p.col].type==PERVIOUS))
				return i;
			else if(data.source[i].row==p.row&&data.map[p.row][p.col-1].type==PERVIOUS)
				return i;
			else if(data.source[i].row>p.row&&(data.map[p.row][p.col-1].type==PERVIOUS||data.map[p.row+1][p.col].type==PERVIOUS))
				return i;
		}
		else if(data.source[i].col==p.col){
			if(data.source[i].row<p.row&&(data.map[p.row][p.col-1].type==PERVIOUS||data.map[p.row+1][p.col].type==PERVIOUS))
				return i;
			else if(data.source[i].row>p.row&&data.map[p.row+1][p.col].type==PERVIOUS)
				return i;
		}
		else{
			if(data.source[i].row<p.row&&(data.map[p.row][p.col+1].type==PERVIOUS||data.map[p.row-1][p.col].type==PERVIOUS))
				return i;
			else if(data.source[i].row==p.row&&data.map[p.row][p.col+1].type==PERVIOUS)
				return i;
			else if(data.source[i].row>p.row&&(data.map[p.row][p.col+1].type==PERVIOUS||data.map[p.row+1][p.col].type==PERVIOUS))
				return i;
		}
	}
	return -1;
}
//判断视野为range范围是否有敌军坦克
bool getRangeEnemy(MapCell map[][MAP_WIDTH +2],Point p,short range,FlagType ft,TankData tank[])
{
	for(short i=-range;i<=range;i++)
	{
		for(short j=-range;j<=range;j++)
		{
			if(abs(i)+abs(j)>range)continue;
			if(p.row+i>=MAP_HEIGHT+2||p.row+i<=0)continue;
			if(p.col+j>=MAP_WIDTH+2||p.col+j<=0)continue;
			if(map[p.row+i][p.col+j].whoIsHere==-1)continue;
			if(tank[map[p.row+i][p.col+j].whoIsHere].flag!=ft)return true;
		}
	}
	return false;
}
//金矿如果是敌方的或者中立的或者 敌军临近的己方的时候表示要救援
int FindAimSource(short aimSource[][MAP_WIDTH +2],DataForAI data)
{
	int i,sum=0;
	for(i=0;i<data.totalSource;i++)
	{
		if(isMySource(data.map[data.source[i].row][data.source[i].col],data.myFlag))
		{		
			if(!getRangeEnemy(data.map,data.source[i],2,data.myFlag,data.tank))
				continue;
		}

		sum++;
		aimSource[data.source[i].row][data.source[i].col]=i;
	} 
	return sum;
}

int Arrange(int costForTank[][MAX_SOURCE_NUM],int id,int aimSource)
{
	bool tankk[MAX_TANK_NUM/2];
	short sourceTank[MAX_SOURCE_NUM];
	memset(tankk,0,sizeof(tankk));
	memset(sourceTank,0,sizeof(sourceTank));
	short bound;
	if(aimSource>=5)bound=1;
	else if(aimSource>=3)bound=2;
	else if(aimSource>=2)bound=3;
	else bound=MAX_TANK_NUM/2;
	int i,j;
/*	for(i=0;i<MAX_TANK_NUM/2;i++){
		for(j=0;j<MAX_SOURCE_NUM;j++)
			printf("%3d",costForTank[i][j]);
		printf("\n");
	}
*/	while(!tankk[id])
	{
		int itank,jsource,mincost=MAX;
		for(i=0;i<MAX_TANK_NUM/2;i++)
		{
			if(tankk[i])continue;
			for(j=0;j<MAX_SOURCE_NUM;j++){
			//	printf("%3d",costForTank[i][j]);
				if(costForTank[i][j]!=-1&&costForTank[i][j]<mincost)
				{
					mincost=costForTank[i][j];
					itank=i;
					jsource=j;
				}
			}
		}
		if(mincost==MAX)return -1;
		if(itank==id)return jsource;
		tankk[itank]=1;sourceTank[jsource]++;
		if(sourceTank[jsource]==bound)
			for(i=0;i<MAX_TANK_NUM/2;i++)
				costForTank[i][jsource]=-1;

	}
	return -1;
}

Order fire(TankData target)
{
	Order order;
	order.type=FIRE;
	order.col=target.col;
	order.row=target.row;
	return order;
}
bool path(MapCell map[][MAP_WIDTH +2],Point p1,Point p2)
{
	if(map[p1.row][p1.col].type==STONE||map[p1.row][p1.col].type==BRICK)return false;
	if(p1.col==p2.col&&p1.row==p2.row)return true;
	if(p1.row>p2.row){	Point p=p1;p.row-=1;if(path(map,p,p2))return true;}
	else if(p1.row<p2.row){Point p=p1;p.row+=1;if(path(map,p,p2))return true;}
	if(p1.col>p2.col){Point p=p1;p.col-=1;if(path(map,p,p2))return true;}
	else if(p1.col<p2.col){Point p=p1;p.col-=1;if(path(map,p,p2))return true;}
	return false;
}
Order hit(DataForAI data,short myId, short eId)
{
	Order order;
	order.type=STOP;

	Point p1,p2;
	p1.col=data.tank[myId].col;p1.row=data.tank[myId].row;
	p2.col=data.tank[eId].col;p2.row=data.tank[eId].row;

	if(p1.col>p2.col){
		p1.col-=1;
		if(path(data.map,p1,p2)){order.type=GOLEFT;return order;}
		p1.col+=1;
	}
	else if(p1.col<p2.col){
		p1.col+=1;
		if(path(data.map,p1,p2)){order.type=GORIGHT;return order;}
		p1.col-=1;
	}

	if(p1.row>p2.row){
		p1.row-=1;
		if(path(data.map,p1,p2)){order.type=GOUP;return order;}
		p1.row+=1;
	}
	else if(p1.row<p2.row){
		p1.row+=1;
		if(path(data.map,p1,p2)){order.type=GODOWN;return order;}
		p1.row-=1;
	}
	return order;
}
short getAttackedLife(TankData tank[],short myId)
{
	short sum=0;
	short low,up;
	if(myId>5){low=MAX_TANK_NUM/2;up=MAX_TANK_NUM;}
	else{low=0;up=MAX_TANK_NUM/2;}
	for(int i=low;i<up;i++)
	{
		if(tank[i].col<0)continue;
		if(tank[i].range>=disTank(tank[i],tank[myId]))
			sum+=tank[i].attack;
	}
	return sum;
}

Order aroundDeal(DataForAI data)
{
	Order order;
	order.type=STOP;

	int myId=data.myID;
	TankData curTank=data.tank[myId];    //当前坦克信息
	short needSource=getMyNeedSource(data,myId);  //周围视野为2内有未占领的矿点
	short eID=getAttackEnemy(myId,data.tank);    //攻击范围能打到的敌人的标号
	short attackedLife=getAttackedLife(data.tank,myId);  //受到的敌人的最大的攻击

	switch(curTank.type)
	{
	case Striker:
		if(eID+1)return fire(data.tank[eID]);  //附近有敌人则攻击敌人
		break;
	case Sniper:
		if(eID+1)return fire(data.tank[eID]);  //附近有敌人则攻击敌人
		break;
	case Pioneer:
		if(eID+1){
			if(curTank.life>data.tank[eID].life)return hit(data,myId,eID);  //相邻有敌人且血多时候撞击敌人
			if(data.tank[eID].type!=Pioneer)return hit(data,myId,eID); //相邻且敌人不是Pioneer撞击
			if(needSource<0)return hit(data,myId,eID);
		}
		if(needSource>=0)return order;   //附近2以内有矿点则找矿点
		//视野范围3内如果有敌人且如果前去撞击敌人并能撞死对方则前去撞敌
		short step;
		short eneId=getRangeEnemy(data,myId,3,step);
		if(eneId>=0&&curTank.life>data.tank[eneId].life+attackedLife+(eneId-1)*data.tank[eneId].attack)
			return hit(data,myId,eneId);
		break;
	}

	return order;
	/*
	short eID=getAttackEnemy(data.myID,data.tank);
	 //如果攻击范围有敌人则射击敌人
	if(eID+1)
	{
		if(curTank.type==Pioneer&&curTank.life>data.tank[eID].life)
		{
			if(curTank.col>data.tank[eID].col)order.type=GOLEFT;
			else if(curTank.col<data.tank[eID].col)order.type=GORIGHT;
			else if(curTank.row>data.tank[eID].row)order.type=GODOWN;
			else order.type=GOLEFT;
		}
		else{
		order.type=FIRE;
		order.col=data.tank[eID].col;
		order.row=data.tank[eID].row;	
		}
		return order;
	}
	*/
}



int BreadFirstSearchRed(DataForAI data)
{
	bool flag[MAP_HEIGHT+2][MAP_WIDTH +2];
	int tag[MAP_HEIGHT+2][MAP_WIDTH +2];
	int move[MAP_HEIGHT+2][MAP_WIDTH +2];
	short aimSource[MAP_HEIGHT+2][MAP_WIDTH +2];
	int costForTank[MAX_TANK_NUM/2][MAX_SOURCE_NUM];
	memset(aimSource,-1,sizeof(aimSource));
	memset(costForTank,-1,sizeof(costForTank));
	Point p;

	int aimSourceNum=FindAimSource(aimSource,data);
	if(aimSourceNum==0)return -1;

	short maxAimSource=aimSourceNum>=5?5:aimSourceNum;

	short i,idtank[MAX_TANK_NUM/2];
	for(i=0;i<data.myID;i++)
		idtank[i]=i;
	for(i=data.myID;i<MAX_TANK_NUM/2-1;i++)
		idtank[i]=i+1;
	idtank[MAX_TANK_NUM/2-1]=data.myID;
	for(i=0;i<MAX_TANK_NUM/2;i++)
	{

		/*-`-`-`-`-`-`-`-`-`-`-`-`-`-`-`-`-`-`-`-*/
	
		TankData curTank=data.tank[idtank[i]]; 
		memset(flag,0,sizeof(flag));
		for(int ii=0;ii<MAP_HEIGHT+2;ii++)
			for(int jj=0;jj<MAP_WIDTH +2;jj++)
				tag[ii][jj]=MAX;  

		priority_queue<Node> q;

		p.col=curTank.col;p.row=curTank.row;

		Node node;
		node.p=p;
		node.cost=0;

		short sourceCount=0;
		q.push(node);

		move[p.row][p.col]=-1;
		while(!q.empty())
		{
			node=q.top();
			q.pop();
			p=node.p;

			if(node.cost<tag[p.row][p.col])
				tag[p.row][p.col]=node.cost;
			if(flag[p.row][p.col])continue;
			flag[p.row][p.col]=1;

		//	printf("%d %d: %d %d---%d\n",data.myID,q.size(),p.row,p.col,node.cost);
		//	if(data.map[p.row][p.col].isHereSource!=NotSource&&!isMySource(data.map[p.row][p.col],data.myFlag))
		//		break;

			if(aimSource[p.row][p.col]+1){
				sourceCount++;
				costForTank[idtank[i]][aimSource[p.row][p.col]]=tag[p.row][p.col];
				if(sourceCount>=maxAimSource)break;
			}

			if(p.row>1&&!flag[p.row-1][p.col]&&tag[p.row-1][p.col]>node.cost)  //up
			{
				if(data.map[p.row-1][p.col].type!=STONE){
					int c=node.cost+1;
					if(data.map[p.row-1][p.col].type==BREAKBRICK)
						c+=1;
					else if(data.map[p.row-1][p.col].type==BRICK)
						c+=curTank.attack>1?1:2;
					if(c<tag[p.row-1][p.col]){
						Node nod=node;
						nod.p.row-=1;
						nod.cost=c;
						q.push(nod);
						move[p.row-1][p.col]=1;
						tag[p.row-1][p.col]=c;
					}
				}
			}
			if(p.row<MAP_HEIGHT&&!flag[p.row+1][p.col]&&tag[p.row+1][p.col]>node.cost)  //down
			{
				if(data.map[p.row+1][p.col].type!=STONE){
					int c=node.cost+1;
					if(data.map[p.row+1][p.col].type==BREAKBRICK)
						c+=1;
					else if(data.map[p.row+1][p.col].type==BRICK)
						c+=curTank.attack>1?1:2;
					if(c<tag[p.row+1][p.col]){
						Node nod=node;
						nod.p.row+=1;
						nod.cost=c;
						q.push(nod);
						move[p.row+1][p.col]=2;
						tag[p.row+1][p.col]=c;
					}
				}
			}
			if(p.col>1&&!flag[p.row][p.col-1]&&tag[p.row][p.col-1]>node.cost)
			{
				if(data.map[p.row][p.col-1].type!=STONE){
					int c=node.cost+1;
					if(data.map[p.row][p.col-1].type==BREAKBRICK)
						c+=1;
					else if(data.map[p.row][p.col-1].type==BRICK)
						c+=curTank.attack>1?1:2;
					if(c<tag[p.row][p.col-1]){
						Node nod=node;
						nod.p.col-=1;
						nod.cost=c;
						q.push(nod);
						move[p.row][p.col-1]=3;
						tag[p.row][p.col-1]=c;
					}
				}
			}
			if(p.col<MAP_WIDTH&&!flag[p.row][p.col+1]&&tag[p.row][p.col+1]>node.cost)
			{
				if(data.map[p.row][p.col+1].type!=STONE){
					int c=node.cost+1;
					if(data.map[p.row][p.col+1].type==BREAKBRICK)
						c+=1;
					else if(data.map[p.row][p.col+1].type==BRICK)
						c+=curTank.attack>1?1:2;
					if(c<tag[p.row][p.col+1]){
						Node nod=node;
						nod.p.col+=1;
						nod.cost=c;
						q.push(nod);
						move[p.row][p.col+1]=4;
						tag[p.row][p.col+1]=c;
					}
				}
			}
		}
		while(!q.empty())q.pop();
		/*-`-`-`-`-`-`-`-`-`-`-`-`-`-`-`-`-`-`-`-*/
	}
	int idS=Arrange(costForTank,data.myID,maxAimSource);
	//printf("%d  ||",idS);

	if(idS==-1)return -1;
	p=data.source[idS];
	int o=move[p.row][p.col];
	//printf("---over-------------%d\n",o);
	while(move[p.row][p.col]+1)
	{
		o=move[p.row][p.col];
		switch(move[p.row][p.col])
		{
		case 1:
			p.row+=1;
			break;
		case 2:
			p.row-=1;
			break;
		case 3:
			p.col+=1;
			break;
		case 4:
			p.col-=1;
			break;
		}
	}
	return o;
}

int BreadFirstSearchBlue(DataForAI data)
{
	bool flag[MAP_HEIGHT+2][MAP_WIDTH +2];
	int tag[MAP_HEIGHT+2][MAP_WIDTH +2];
	int move[MAP_HEIGHT+2][MAP_WIDTH +2];
	short aimSource[MAP_HEIGHT+2][MAP_WIDTH +2];
	int costForTank[MAX_TANK_NUM/2][MAX_SOURCE_NUM];
	memset(aimSource,-1,sizeof(aimSource));
	memset(costForTank,-1,sizeof(costForTank));
	Point p;

	int aimSourceNum=FindAimSource(aimSource,data);
	if(aimSourceNum==0)return -1;

	short maxAimSource=aimSourceNum>=5?5:aimSourceNum;

	short i,idtank[MAX_TANK_NUM/2];
	for(i=0;i<data.myID-5;i++)
		idtank[i]=i+5;
	for(i=data.myID-5;i<MAX_TANK_NUM/2-1;i++)
		idtank[i]=i+6;
	idtank[MAX_TANK_NUM/2-1]=data.myID;
	for(i=0;i<MAX_TANK_NUM/2;i++)
	{

		/*-`-`-`-`-`-`-`-`-`-`-`-`-`-`-`-`-`-`-`-*/
	
		TankData curTank=data.tank[idtank[i]]; 
		memset(flag,0,sizeof(flag));
		for(int ii=0;ii<MAP_HEIGHT+2;ii++)
			for(int jj=0;jj<MAP_WIDTH +2;jj++)
				tag[ii][jj]=MAX;  

		priority_queue<Node> q;

		p.col=curTank.col;p.row=curTank.row;

		Node node;
		node.p=p;
		node.cost=0;

		short sourceCount=0;
		q.push(node);

		move[p.row][p.col]=-1;
		while(!q.empty())
		{
			node=q.top();
			q.pop();
			p=node.p;

			if(node.cost<tag[p.row][p.col])
				tag[p.row][p.col]=node.cost;
			if(flag[p.row][p.col])continue;
			flag[p.row][p.col]=1;

		//	printf("%d %d: %d %d---%d\n",data.myID,q.size(),p.row,p.col,node.cost);
		//	if(data.map[p.row][p.col].isHereSource!=NotSource&&!isMySource(data.map[p.row][p.col],data.myFlag))
		//		break;

			if(aimSource[p.row][p.col]+1){
				sourceCount++;
				costForTank[idtank[i]-5][aimSource[p.row][p.col]]=tag[p.row][p.col];
				if(sourceCount>=maxAimSource)break;
			}

			if(p.row<MAP_HEIGHT&&!flag[p.row+1][p.col]&&tag[p.row+1][p.col]>node.cost)  //down
			{
				if(data.map[p.row+1][p.col].type!=STONE){
					int c=node.cost+1;
					if(data.map[p.row+1][p.col].type==BREAKBRICK)
						c+=1;
					else if(data.map[p.row+1][p.col].type==BRICK)
						c+=curTank.attack>1?1:2;
					if(c<tag[p.row+1][p.col]){
						Node nod=node;
						nod.p.row+=1;
						nod.cost=c;
						q.push(nod);
						move[p.row+1][p.col]=2;
						tag[p.row+1][p.col]=c;
					}
				}
			}
			if(p.row>1&&!flag[p.row-1][p.col]&&tag[p.row-1][p.col]>node.cost)  //up
			{
				if(data.map[p.row-1][p.col].type!=STONE){
					int c=node.cost+1;
					if(data.map[p.row-1][p.col].type==BREAKBRICK)
						c+=1;
					else if(data.map[p.row-1][p.col].type==BRICK)
						c+=curTank.attack>1?1:2;
					if(c<tag[p.row-1][p.col]){
						Node nod=node;
						nod.p.row-=1;
						nod.cost=c;
						q.push(nod);
						move[p.row-1][p.col]=1;
						tag[p.row-1][p.col]=c;
					}
				}
			}
			if(p.col<MAP_WIDTH&&!flag[p.row][p.col+1]&&tag[p.row][p.col+1]>node.cost)  //right
			{
				if(data.map[p.row][p.col+1].type!=STONE){
					int c=node.cost+1;
					if(data.map[p.row][p.col+1].type==BREAKBRICK)
						c+=1;
					else if(data.map[p.row][p.col+1].type==BRICK)
						c+=curTank.attack>1?1:2;
					if(c<tag[p.row][p.col+1]){
						Node nod=node;
						nod.p.col+=1;
						nod.cost=c;
						q.push(nod);
						move[p.row][p.col+1]=4;
						tag[p.row][p.col+1]=c;
					}
				}
			}
			if(p.col>1&&!flag[p.row][p.col-1]&&tag[p.row][p.col-1]>node.cost)  //left
			{
				if(data.map[p.row][p.col-1].type!=STONE){
					int c=node.cost+1;
					if(data.map[p.row][p.col-1].type==BREAKBRICK)
						c+=1;
					else if(data.map[p.row][p.col-1].type==BRICK)
						c+=curTank.attack>1?1:2;
					if(c<tag[p.row][p.col-1]){
						Node nod=node;
						nod.p.col-=1;
						nod.cost=c;
						q.push(nod);
						move[p.row][p.col-1]=3;
						tag[p.row][p.col-1]=c;
					}
				}
			}
			
		}
		while(!q.empty())q.pop();
		/*-`-`-`-`-`-`-`-`-`-`-`-`-`-`-`-`-`-`-`-*/
	}
	int idS=Arrange(costForTank,data.myID-5,maxAimSource);
	//printf("%d  ||",idS);

	if(idS==-1)return -1;
	p=data.source[idS];

	int o=move[p.row][p.col];
	//printf("---over-------------%d\n",o);
	while(move[p.row][p.col]+1)
	{
		o=move[p.row][p.col];
		switch(move[p.row][p.col])
		{
		case 1:
			p.row+=1;
			break;
		case 2:
			p.row-=1;
			break;
		case 3:
			p.col+=1;
			break;
		case 4:
			p.col-=1;
			break;
		}
	}
	return o;
}
//平台0回合时调用此函数获取AI名称及坦克类型信息，请勿修改此函数声明。
extern "C" InitiateInfo chooseType()
{
	InitiateInfo Info;
	Info.tank[0]=Striker;
	Info.tank[1]=Striker;
	Info.tank[2]=Striker;
	Info.tank[3]=Pioneer;
	Info.tank[4]=Pioneer;
/*	Info.tank[0]=Pioneer;
	Info.tank[1]=Pioneer;
	Info.tank[2]=Pioneer;
	Info.tank[3]=Striker;
	Info.tank[4]=Striker;
*/	strcpy(Info.aiName,"twenz_v6"); //AI名请勿使用中文。 
	return Info;
}

//平台从第1回合开始调用此函数获得每回合指令，请勿修改此函数声明。
extern "C" Order makeOrder(DataForAI data)
{
	int tmp=clock();

	Order order;
	
//	TankData curTank=data.tank[data.myID];    //当前坦克信息

	order=aroundDeal(data);
/*	short eID=getAttackEnemy(data.myID,data.tank);
	 //如果攻击范围有敌人则射击敌人
	if(eID+1)
	{
		if(curTank.type==Pioneer&&curTank.life>data.tank[eID].life)
		{
			if(curTank.col>data.tank[eID].col)order.type=GOLEFT;
			else if(curTank.col<data.tank[eID].col)order.type=GORIGHT;
			else if(curTank.row>data.tank[eID].row)order.type=GODOWN;
			else order.type=GOLEFT;
		}
		else{
		order.type=FIRE;
		order.col=data.tank[eID].col;
		order.row=data.tank[eID].row;	
		}
		return order;
	}
*/
	if(order.type==STOP)
		order=decide(data);
	
//	if(data.round<20)
//	printf("%d: %d---- %d ms  ***blue:%d  red:%d\n",data.myID,x,clock()-tmp,data.blueTime,data.redTime);
	return order;
}

Order decide(DataForAI data)
{
	Order order;

	TankData curTank=data.tank[data.myID];
	int x;
	if(data.myFlag==RED)
		x=BreadFirstSearchRed(data);
	else
		x=BreadFirstSearchBlue(data);
	switch(x)
	{
	case 1:
		if(data.map[curTank.row-1][curTank.col].type==PERVIOUS)
			order.type=GOUP;
		else{
			order.type=FIRE;
			order.col=curTank.col;
			order.row=curTank.row-1;
		}
		break;
	case 2:
		if(data.map[curTank.row+1][curTank.col].type==PERVIOUS)
			order.type=GODOWN;
		else{
			order.type=FIRE;
			order.col=curTank.col;
			order.row=curTank.row+1;
		}
		break;
	case 3:
		if(data.map[curTank.row][curTank.col-1].type==PERVIOUS)
			order.type=GOLEFT;
		else{
			order.type=FIRE;
			order.col=curTank.col-1;
			order.row=curTank.row;
		}
		break;
	case 4:
		if(data.map[curTank.row][curTank.col+1].type==PERVIOUS)
			order.type=GORIGHT;
		else{
			order.type=FIRE;
			order.col=curTank.col+1;
			order.row=curTank.row;
		}
		break;
	default:
		order.type=STOP;
	}
	return order;
}