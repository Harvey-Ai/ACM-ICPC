#include "Tank.h"
#include <cstring>
/* my code */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <queue>
using namespace std;

/* utility declare */
#define INF (MAP_WIDTH * MAP_HEIGHT * 10)

#define typec int		// type of cost

// Euclid distance
#define DIST(row1, col1, row2, col2) \
	(abs((row1) - (row2)) + abs((col1) - (col2)))

// get minest steps from point i to point j
#define POINT_TO_POINT_STEPS(point1, point2) \
	(getWaySteps((point1)->row, (point1)->col, (point2)->row, (point2)->col))

// get first step direction from point i to point j
#define POINT_TO_POINT_DIR(point1, point2) \
	(getWayDir((point1)->row, (point1)->col, (point2)->row, (point2)->col))

#define INVALID 0
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define DIRNUM 5

typedef int Direction;

typedef struct path
{
	int steps;
	Direction dir;
} path;

// two strategy to face 5 sn or st and pn
#define BEATsn	1
#define BEATstAndp	2
static int strategy;

const typec inf = 0x3f3f3f3f;		// max of cost

/* for 二分匹配 */
queue<int> que;
int pv[MAX_SOURCE_NUM + 1], vx[MAX_SOURCE_NUM + 1], vy[MAX_SOURCE_NUM + 1], mx[MAX_SOURCE_NUM + 1], my[MAX_SOURCE_NUM + 1];
typec cost[MAX_SOURCE_NUM + 1][MAX_SOURCE_NUM + 1], lx[MAX_SOURCE_NUM + 1], ly[MAX_SOURCE_NUM + 1], slk[MAX_SOURCE_NUM + 1];

/// four direction
static Direction dird[DIRNUM] = {INVALID, UP,DOWN,LEFT,RIGHT};
static int dirx[DIRNUM] = {0,-1, 1, 0, 0};
static int diry[DIRNUM] = {0, 0, 0, -1, 1};

// 0 source Unoccupied, 1 source occupied
static int sourceOccupied[MAX_SOURCE_NUM];

// way for point i to point j
static struct path ways[MAP_HEIGHT + 1][MAP_WIDTH + 1][MAP_HEIGHT + 1][MAP_WIDTH + 1];

// graph for A*
static int graph[MAP_HEIGHT + 1][MAP_WIDTH + 1];

/* round */
static int Round = 0;

/* ranker order */
static struct Order tankerOrder[MAX_TANK_NUM];

/* tank target */
static int tankerTarget[MAX_TANK_NUM];

// to every source , the time*2 i hold before
static int sourceHoldTime[MAX_SOURCE_NUM];

/**********var declare end **************/

/*************** utility function *************/
static int match(int n);
static void initGh(struct DataForAI *data);
static void initInfo(struct DataForAI *data);
static void initWayBuf(struct DataForAI *data);
static int findWay(struct DataForAI *data, struct TankData *myTanker, struct Point start, struct Point end);
static int getWaySteps(int row1, int col1, int row2, int col2);
static int getWayDir(int row1, int col1, int row2, int col2);
static int getRangeEN(struct DataForAI *data, int sPosx, int sPosy, int viewRange, int *enemyID,
		int *ENx, int *ENy);
static void fireWall(struct DataForAI *data,struct  TankData *myTanker);
static void fireEN(struct DataForAI *data, struct TankData *myTanker);
/**************utility function end***********/

/************* process function **************/
static void findOrder(struct DataForAI data,struct Order *order);
static void freshInfo(DataForAI *data);
static void initCost(DataForAI *data, int *sourceLostStep);
static void tankerOwnOrder(struct DataForAI *data, struct TankData *myTanker);
static void allocateOrder(struct DataForAI *data);
static void getSourceLostInfo(struct DataForAI *data, int *tankerLostStep);
static void getOptOrder(struct DataForAI *data, int *sourceLostStep);
static void Poinner(struct DataForAI *data, struct TankData *myTanker);
/***********process function end**************/

/* process function boday */
void
findOrder(DataForAI data, Order *order)
{
	TankData	myTanker = data.tank[data.myID];

	// init the statistic hold time && fight stratege
	if (data.round == 1)
		initInfo(&data);

	// if it is not my tanker or it's dead, return STOP	
	if (myTanker.flag != data.myFlag || myTanker.life <= 0 
		|| data.round <= 0)
	{
		order->type = STOP;
		return;
	}

	// module 1: allocate order for every tank, source target and move direction
	if (Round != data.round)
	{
		//printf("do round: %d\n", Round);
		memset(tankerOrder, 0, sizeof(tankerOrder));
		memset(tankerTarget, 0, sizeof(tankerTarget));
		// get move order for every tanker
		allocateOrder(&data);
		Round = data.round;
		//printf("do round: %d ok !\n", Round);
	}

	// module 2: get tank's own order, fire
	//printf("do own order\n");
	tankerOwnOrder(&data, &myTanker);
	//printf("do own order ok!\n");

	if (myTanker.ID == 3)
		printf("round: %d, order:%d, target: %d (%d %d), %d\n", data.round, tankerOrder[myTanker.ID].type,
		tankerTarget[myTanker.ID],
		data.source[tankerTarget[myTanker.ID]].row,
		data.source[tankerTarget[myTanker.ID]].col,
		data.map[data.source[tankerTarget[myTanker.ID]].row][data.source[tankerTarget[myTanker.ID]].col].isHereSource);
	order->type = tankerOrder[myTanker.ID].type;
	order->row = tankerOrder[myTanker.ID].row;
	order->col = tankerOrder[myTanker.ID].col;
}

// renew source
void
reNewSourceInfo(DataForAI *data)
{
	int i;

	for(i = 0;i < data->totalSource;i++)
		if (data->map[data->source[i].row][data->source[i].col].isHereSource 
			== (SourceType)(data->myFlag + 1))
		{
			sourceOccupied[i] = 1;
			sourceHoldTime[i] += 2;
		}
		else
		{
			sourceOccupied[i] = 0;
			if (data->map[data->source[i].row][data->source[i].col].isHereSource == 
				NeutralSource)
				sourceHoldTime[i]++;
		}
}

void
tankerOwnOrder(DataForAI *data, TankData *myTanker)
{
	// if there is an wall stop us, clear it
	fireWall(data, myTanker);

	// striker if there are enemy in attack range, fire it
	// poinner escape from the enemy in distance, if my location near my base, heat it
	switch(myTanker->type)
	{
		case Striker:
			fireEN(data, myTanker);
			break;
		case Pioneer:
			Poinner(data, myTanker);
			break;
	}
}

void
allocateOrder(DataForAI *data)
{
	int i, j;
	int sourceLostStep[MAX_SOURCE_NUM];

	// refresh source lost info and statistic source occupied time 
	freshInfo(data);
	
	// init source lost info
	getSourceLostInfo(data, sourceLostStep);

	// init way buf
	initWayBuf(data);

	// find shortest way between my tanker and source
	for(i = 0;i < MAX_TANK_NUM;i++)
		if (data->tank[i].flag == data->myFlag && data->tank[i].life > 0)
			for(j = 0;j < data->totalSource;j++)
			{
				Point start, end;
				start.row = data->tank[i].row;
				start.col = data->tank[i].col;
				end = data->source[j];

				// calculate shortest way to source
				findWay(data, &data->tank[i], start, end);
			}
	//printf("get ways\n");

	// get optical strategy, in one step
	getOptOrder(data, sourceLostStep);
	//printf("get optical ways\n");
}

// find min source lost time for every source
void
getSourceLostInfo(DataForAI *data, int *sourceLostStep)
{
	int i, j;
	int sPosX, sPosY;
	int ennemyNum;
	int ennemy[MAX_TANK_NUM];
	int ennemyX[MAX_TANK_NUM];
	int ennemyY[MAX_TANK_NUM];

	// init sourceLostStep info
	for(i = 0;i < data->totalSource;i++)
	{
		if (sourceOccupied[i] == 0)
			sourceLostStep[i] = 0;
		else
			sourceLostStep[i] = -1;
	}

	// init way data
	initWayBuf(data);

	// for every source
	// detect enemy tanker, and caculate the min step to lost the mine
	for(i = 0;i < data->totalSource;i++)
	{
		sPosX = data->source[i].row;
		sPosY = data->source[i].col;
		ennemyNum = getRangeEN(data, sPosX, sPosY, SOURCE_SIGHT, ennemy, ennemyX, ennemyY);

		for(j = 0;j < ennemyNum;j++)
		{
			TankData *enemy = &data->tank[ennemy[j]];
			Point start, end;
			start.row = ennemyX[ennemy[j]];
			start.col = ennemyY[ennemy[j]];
			end.row = sPosX;
			end.col = sPosY;

			findWay(data, enemy, start, end);
			if (sourceLostStep[i] == -1 ||
				sourceLostStep[i] > POINT_TO_POINT_STEPS(&start, &end))
				sourceLostStep[i] = POINT_TO_POINT_STEPS(&start, &end); 
		}
	}
}


void
getOptOrder(DataForAI *data, int *sourceLostStep)
{
	int i, j, k, l;
	int help[MAX_TANK_NUM];
	int	maxTemp;
	Point start;
	
	// init help info
	memset(help, 0, sizeof(help));

	// init tank target info
	for(i = 0;i < MAX_TANK_NUM;i++)
		tankerTarget[i] = -1;

	//带权最大二分匹配
	// assign every tanker's order in global
	initCost(data, sourceLostStep);
	maxTemp = MAX_TANK_NUM > data->totalSource ? MAX_TANK_NUM : data->totalSource;
	match(maxTemp);

	for(i = 0;i < MAX_TANK_NUM;i++)
		if (data->myFlag == data->tank[i].flag && data->tank[i].life > 0)
		{
			start.row = data->tank[i].row;
			start.col = data->tank[i].col;
			if (cost[i][mx[i]] != -INF)
			{
				tankerOrder[i].type = (OrderType)POINT_TO_POINT_DIR(&start, &data->source[mx[i]]);
				tankerTarget[i] = mx[i];
			}
		}

	// if no source need to go, what we should do????
	// help others, two tank go together at most
	/*
	for(i = 0;i < MAX_TANK_NUM;i++)
	{
		if (data->myFlag != data->tank[i].flag || data->tank[i].life <= 0)
			continue;

		start.row = data->tank[i].row;
		start.col = data->tank[i].col;

		if (tankerTarget[i] == -1)
		{
			for(j = 0;j < MAX_TANK_NUM;j++)
				if (data->myFlag != data->tank[j].flag ||data->tank[j].life <= 0)
					continue;
				else if (help[j] == 0 && tankerTarget[j] != -1)
				{
					help[j] = 1;
					tankerOrder[i].type = (OrderType)POINT_TO_POINT_DIR(&start, &data->source[tankerTarget[j]]);
					tankerTarget[i] = tankerTarget[j];
					break;
				}
		}
	}
	*/
	// if no need, stop
	for(i = 0;i < MAX_TANK_NUM;i++)
	{
		if (data->myFlag != data->tank[i].flag || data->tank[i].life <= 0)
			continue;

		if (tankerTarget[i] == -1)
			tankerOrder[i].type = STOP;
	}

	if (data->round == 166)
		printf("lostS: %d 1: %d 3: %d\n", sourceLostStep[tankerTarget[3]],
		sourceHoldTime[1], sourceHoldTime[3]);
}

void
Poinner(struct DataForAI *data, struct TankData *myTanker)
{
	int i, j;
	int enemyNum;
	int dist;
	int destX, destY;
	int minDis;
	int bestdir;
	int enemy[MAX_TANK_NUM];
	int enemyX[MAX_TANK_NUM];
	int enemyY[MAX_TANK_NUM];
	int hasSTSN = 0;
	Point start, end;

	// if near a source return
	start.row = myTanker->row;
	start.col = myTanker->col;
	if (POINT_TO_POINT_STEPS(&start, &data->source[tankerTarget[myTanker->ID]]) <= 2)
		return;

	// if no enemy type is Striker, return
	enemyNum = getRangeEN(data, myTanker->row, myTanker->col, SIGHT, enemy, enemyX, enemyY);
	for(j = 0;j < enemyNum;j++)
	{
		assert(data->tank[enemy[j]].flag != data->myFlag);
		if (data->tank[enemy[j]].type == Striker || data->tank[enemy[j]].type == Sniper)
		{
			hasSTSN = 1;
			break;
		}
	}
	if (!hasSTSN)
		return;
	
	start.row = myTanker->row;
	start.col = myTanker->col;
	minDis = -1;
	bestdir = -1;

	assert(tankerTarget[myTanker->ID] != -1);
	for(i = 0;i < enemyNum;i++)
	{
		end.row = enemyX[enemy[i]];
		end.col = enemyY[enemy[i]];

		if (data->tank[enemy[i]].type != Pioneer)
		{	
			findWay(data, myTanker,data->source[tankerTarget[myTanker->ID]], end);
			dist = POINT_TO_POINT_STEPS(&end, &data->source[tankerTarget[myTanker->ID]]);
			if (dist < minDis || minDis == -1)
			{
				minDis = dist;
				findWay(data, myTanker, start, end);
				bestdir = POINT_TO_POINT_DIR(&start, &end);
			}
		}
	}

	if (bestdir != -1)
		tankerOrder[myTanker->ID].type = (OrderType)dird[bestdir];
}
/************* process function boday end*****************/

/*******************utility function*************************/
void initCost(DataForAI *data, int *sourceLostStep)
{
	int i, j;
	int costSteps;
	Point start;

	// init
	for(i = 0;i < MAX_SOURCE_NUM;i++)
		for(j = 0;j < MAX_SOURCE_NUM;j++)
			cost[i][j] = -INF;

	for(i = 0;i < MAX_TANK_NUM;i++)
		if (data->myFlag == data->tank[i].flag && data->tank[i].life > 0)
		{
			start.row = data->tank[i].row;
			start.col = data->tank[i].col;

			for(j = 0;j < data->totalSource;j++)
			{					
				if (sourceLostStep[j] == -1)
					continue;

				// if my type is poinner, go to a enemy source
				else if (data->tank[i].type == Pioneer && sourceOccupied[j])
					continue;

				costSteps = POINT_TO_POINT_STEPS(&start, &data->source[j]);
				if (sourceLostStep[j] > costSteps)
					costSteps = sourceLostStep[j];
				costSteps = sourceHoldTime[j] - costSteps;
				cost[i][j] = costSteps;
			}
		}
}

// 二分最大权匹配
int bfs(int n)
{
	int i, p, t, u; typec ex;
	while (!que.empty()) {
		p = que.front(); que.pop(); u = p >> 1;
		if (p & 1) {
			if (-1 == my[u]) {
				for ( ; u != -1; u = t) {
					t = mx[ my[u] = pv[u] ];
					mx[ pv[u] ] = u;
				}
				return 1;
			} else {
				vx[ my[u] ] = 1; que.push(my[u] << 1);
			}
		} else {
			for (i = 0; i < n; i++) {
				if (vy[i]) continue;
				else if (lx[u] + ly[i] != cost[u][i]) {
// EQUAL
					ex = lx[u] + ly[i] - cost[u][i];
					if (slk[i] > ex) {
						slk[i] = ex; pv[i] = u;
					}
				} else {
					vy[i] = 1; pv[i] = u;
					que.push((i << 1) | 1);
				}
			}
		}
	}
	return 0;
}

typec match(int n)
{
	typec res = 0, ex;
	int agu = 1, mn, i, j;
	memset(ly, 0, sizeof(ly));
	memset(mx, -1, sizeof(mx));
	memset(my, -1, sizeof(my));
	for (i = 0; i < n; i++) {      // vertex: 0 ~ n-1
		lx[i] = - inf;
		for (j = 0; j < n; j++)
			if (lx[i] < cost[i][j]) lx[i] = cost[i][j];
	}
	for (mn = 0; mn < n; mn++) {
		if (agu) {
			memset(vx, 0, sizeof(vx));
			memset(vy, 0, sizeof(vy));
			for (i = 0; i < n; i++) slk[i] = inf;
			while (!que.empty()) que.pop();
			que.push(mn << 1); vx[mn] = 1;
		}
		if (bfs(n)) { agu = 1; continue; }
		ex = inf; mn--; agu = 0;
		for (i = 0; i < n; i++)
			if (!vy[i] && ex > slk[i]) ex = slk[i];
		for (i = 0; i < n; i++) {
			if (vx[i]) lx[i] -= ex;
			if (vy[i]) ly[i] += ex;
			slk[i] -= ex;
		}
		for (i = 0; i < n; i++)
			if (!vy[i] && 0 == slk[i]) {    // EQUAL
				vy[i] = 1; que.push((i << 1) | 1);
			}
	}
	for (i = 0; i < n; i++) res += cost[i][ mx[i] ];
	return res;
}

// A* algorithm
// find shortest way between point start and point end
int
findWay(struct DataForAI *data, struct TankData *myTanker,struct  Point start, struct Point end)
{
	int i, j;
	int open[MAP_HEIGHT + 1][MAP_WIDTH + 1], close[MAP_HEIGHT + 1][MAP_WIDTH + 1];
	int link[MAP_HEIGHT + 1][MAP_WIDTH + 1][2];
	int cost[MAP_HEIGHT + 1][MAP_WIDTH + 1];
	int FirstDir;
	int steps;
	int openNum;
	int tempPosx, tempPosy;

	for(i = 0;i <= MAP_HEIGHT;i++)
		for(j = 0;j <= MAP_WIDTH;j++)
		{
			open[i][j] = close[i][j] = -1;
			cost[i][j] = -1;
		}

	open[start.row][start.col] = DIST(end.row, end.col, start.row, start.col);
	link[start.row][start.col][0] = link[start.row][start.col][1] = -1;
	openNum = 1;
	cost[start.row][start.col] = 0;

	while (openNum > 0)
	{
		// estimate value
		int ff;
		int minF, minIDx, minIDy;
		minIDx = minIDy = -1;
		minF = INF + 1;

		// find min value in open
		for(i = 1;i <= MAP_HEIGHT;i++)
			for(j = 1;j <= MAP_WIDTH;j++)
				if (open[i][j] != -1 && open[i][j] < minF)
				{
					minF = open[i][j];
					minIDx = i;
					minIDy = j;
				}

		// if get target point, return
		if(minIDx == end.row && minIDy == end.col)
			break;
		
		// extend point
		for(i = 1;i <= 4;i++)
		{
			int nextPointx, nextPointy;
			int costTemp;

			// extend point
			nextPointx= minIDx + dirx[i];
			nextPointy = minIDy + diry[i];

			if (nextPointx < 1 || nextPointx > MAP_HEIGHT ||
				nextPointy < 1 || nextPointy > MAP_WIDTH)
				continue;

			costTemp = cost[minIDx][minIDy] + graph[nextPointx][nextPointy];
			if (data->map[nextPointx][nextPointy].type == BRICK)
				costTemp += 2 / (myTanker->attack);
			else if (data->map[nextPointx][nextPointy].type == BREAKBRICK)
				costTemp++;
			else if (data->map[nextPointx][nextPointy].type == STONE)
				continue;

			if (cost[nextPointx][nextPointy] == -1 || cost[nextPointx][nextPointy] > costTemp)
				cost[nextPointx][nextPointy] = costTemp;
			
			ff = cost[nextPointx][nextPointy] + DIST(end.row, end.col, nextPointx, nextPointy);
			if (open[nextPointx][nextPointy] != -1 &&
				open[nextPointx][nextPointy] > ff)
			{
				link[nextPointx][nextPointy][0] = minIDx;
				link[nextPointx][nextPointy][1] = minIDy;
				open[nextPointx][nextPointy] = ff;
			}

			else if (close[nextPointx][nextPointy] != -1 &&
					close[nextPointx][nextPointy] > ff)
			{
				link[nextPointx][nextPointy][0] = minIDx;
				link[nextPointx][nextPointy][1] = minIDy;
				close[nextPointx][nextPointy] = -1;
				open[nextPointx][nextPointy] = ff;
				openNum++;
			}
			else if (open[nextPointx][nextPointy] == -1 &&
					close[nextPointx][nextPointy] == -1)
			{
				link[nextPointx][nextPointy][0] = minIDx;
				link[nextPointx][nextPointy][1] = minIDy;
				open[nextPointx][nextPointy] = ff;
				openNum++;
			}
		}
		close[minIDx][minIDy] = open[minIDx][minIDy];
		open[minIDx][minIDy] = -1;
		openNum--;
	}

	tempPosx = end.row;
	tempPosy = end.col;

	// if stand on source
	if (link[tempPosx][tempPosy][0] == -1 && link[tempPosx][tempPosy][1] == -1)
	{
		ways[start.row][start.col][end.row][end.col].steps = 0;
		ways[start.row][start.col][end.row][end.col].dir = STOP;
		return STOP;
	}

	// find father recursive to get way
	steps = 1;
	while(link[tempPosx][tempPosy][0] != start.row ||
			link[tempPosx][tempPosy][1] != start.col)
	{
		int temp;
		temp = tempPosx;
		tempPosx = link[tempPosx][tempPosy][0];
		tempPosy = link[temp][tempPosy][1];
		steps++;
	}
	// next direction
	for(i = 1;i <= 4;i++)
		if (tempPosx == start.row + dirx[i] &&
			tempPosy == start.col + diry[i])
		{
			FirstDir = dird[i];
			break;
		}

	ways[start.row][start.col][end.row][end.col].steps = steps;
	ways[start.row][start.col][end.row][end.col].dir = FirstDir;

	return FirstDir;
}


void
initWayBuf(struct DataForAI *data)
{
	int i, j, k, l;
	for(i = 1;i <= MAP_HEIGHT;i++)
		for(j = 1;j <= MAP_WIDTH;j++)
			for(k = 1;k <= MAP_HEIGHT;k++)
				for(l = 1;l <= MAP_WIDTH;l++)
				{
					ways[i][j][k][l].steps = -1;
					ways[i][j][k][l].dir = INVALID;
				}
	// init graph
	initGh(data);
}

// init info
void initInfo(struct DataForAI *data)
{
	int SNnum = 0;
	int i;

	// init stratege
	for(i = 0;i< MAX_TANK_NUM;i++)
	{
		if (data->tank[i].flag != data->myFlag &&
			data->tank[i].type == Sniper)
			SNnum++;
	}
	if (SNnum >= 4)
		strategy = BEATsn;
	else
		strategy = BEATstAndp;

	// init statistic source hold time
	for(i = 0;i < data->totalSource;i++)
		sourceHoldTime[i] = 0;
}

// refresh source lost info and statistic source occupied time 
void freshInfo(struct DataForAI *data)
{
	int i;
	for(i = 0;i < data->totalSource;i++)
		if (data->map[data->source[i].row][data->source[i].col].isHereSource 
			== (SourceType)(data->myFlag + 1))
		{
			sourceOccupied[i] = 1;
			sourceHoldTime[i] += 2;
		}
		else
		{
			if (data->map[data->source[i].row][data->source[i].col].isHereSource 
				== NeutralSource)
				sourceHoldTime[i]++;
			sourceOccupied[i] = 0;
		}
}

// init graph
void
initGh(struct DataForAI *data)
{
	int i, j;
	int iSource;
	int posX, posY;

	for(i = 1;i <= MAP_HEIGHT;i++)
		for(j = 1;j <= MAP_WIDTH;j++)
			graph[i][j] = 1;

	// if we beat 5 sn or 4 sn, go round the source as far as possible
	if (strategy == BEATsn)
	{
		for(i = 0;i < data->totalSource;i++)
			if (data->map[data->source[i].row][data->source[i].col].isHereSource 
				== (SourceType)(data->myFlag + 1))
				graph[data->source[i].row][data->source[i].col] = 4;
	}
}

int
getWaySteps(int row1, int col1, int row2, int col2)
{
	return ways[row1][col1][row2][col2].steps;
}

int
getWayDir(int row1, int col1, int row2, int col2)
{
	return ways[row1][col1][row2][col2].dir;
}

// find enemy can be seen
// return enemy number, and save enmey ID in *tankerID
int
getRangeEN(struct DataForAI *data, int sPosx, int sPosy, int viewRange, int *enemyID,
			int *ENx, int *ENy)
{
	int enemyNum = 0;
	int Xoff, Yoff;
	int tankID;

	for(Xoff = -viewRange; Xoff <= viewRange;Xoff++)
		for(Yoff = -viewRange; Yoff <= viewRange;Yoff++)
			if (sPosx + Xoff > 0 &&
				sPosy + Yoff > 0 &&
				sPosx + Xoff <= MAP_WIDTH &&
				sPosy + Yoff <= MAP_HEIGHT &&
				(abs(Xoff) + abs(Yoff)) <= viewRange)
			{
				tankID = data->map[sPosx + Xoff][sPosy + Yoff].whoIsHere;

				if (tankID >= 0 && tankID < MAX_TANK_NUM &&
					data->tank[tankID].flag != data->myFlag)
				{
					enemyID[enemyNum] = tankID;
					ENx[tankID] = sPosx + Xoff;
					ENy[tankID] = sPosy + Yoff;
					enemyNum++;
				}
			}
//	printf("eNum: %d\n", enemyNum);
	return enemyNum;
}

// fire wall
void
fireWall(struct DataForAI *data, struct TankData *myTanker)
{
	int i;
	int tankID;
	int targetRow = myTanker->row + dirx[(int)(tankerOrder[myTanker->ID].type)];
	int targetCol = myTanker->col + diry[(int)(tankerOrder[myTanker->ID].type)];
	int Xoff, Yoff;

	// when move, meet a wall ahead, fire it
	if (tankerOrder[myTanker->ID].type != FIRE && tankerOrder[myTanker->ID].type != STOP)
	{
		// assert(data->map[targetRow][targetCol].type != STONE);

		if (data->map[targetRow][targetCol].type != PERVIOUS)
		{
			tankerOrder[myTanker->ID].row = targetRow;
			tankerOrder[myTanker->ID].col = targetCol;
			tankerOrder[myTanker->ID].type = FIRE;
			return;
		}
	}

	// if i am a Pioneer, go
	if (myTanker->type == Pioneer)
		return;

	// if a friend tank ahead, help him, fire an wall for him
	// assert(tankerOrder[myTanker->ID].type != FIRE);
	tankID = data->map[targetRow][targetCol].whoIsHere;

	if (tankID != -1 && data->tank[tankID].flag == data->myFlag)
	{
		int vectorx = dirx[(int)(tankerOrder[myTanker->ID].type)];
		int vextory = diry[(int)(tankerOrder[myTanker->ID].type)];

		// fire the wall ahead first
		if ((targetRow + vectorx > 0 &&
			targetRow + vectorx <= MAP_HEIGHT &&
			targetCol + vextory > 0 &&
			targetCol + vextory <= MAP_WIDTH) &&
			(data->map[targetRow + vectorx][targetCol + vextory].type == BRICK ||
			data->map[targetRow + vectorx][targetCol + vextory].type == BREAKBRICK))
		{
			int WallLife = data->map[targetRow + vectorx][targetCol + vextory].type == BRICK ? 2 : 1;
			// detect if an other tank has fire it
			for(i = 0;i < MAX_TANK_NUM;i++)
				if (data->tank[i].flag == data->myFlag &&
					data->tank[i].life > 0 &&
					tankerOrder[i].type == FIRE &&
					tankerOrder[i].row == targetRow + vectorx &&
					tankerOrder[i].col == targetCol + vextory &&
					(WallLife -= data->tank[i].attack) <= 0)
					break;
			if (i >= MAX_TANK_NUM)
			{
				tankerOrder[myTanker->ID].row = targetRow + vectorx;
				tankerOrder[myTanker->ID].col = targetCol + vextory;
				tankerOrder[myTanker->ID].type = FIRE;
				return;
			}
		}
		else
			for(i = 1;i <= 4;i++)
			{
				int vectorx = dirx[i];
				int vextory = diry[i];

				int WallLife = data->map[targetRow + vectorx][targetCol + vextory].type == BRICK ? 2 : 1;
				if ((targetRow + vectorx > 0 &&
					targetRow + vectorx <= MAP_HEIGHT &&
					targetCol + vextory > 0 &&
					targetCol + vextory <= MAP_WIDTH) && 
					(data->map[targetRow + vectorx][targetCol + vextory].type == BRICK ||
					data->map[targetRow + vectorx][targetCol + vextory].type == BREAKBRICK))
				{
					// detect if an other tank has fire it
					for(i = 0;i < MAX_TANK_NUM;i++)
						if (data->tank[i].flag == data->myFlag &&
							data->tank[i].life > 0 &&
							tankerOrder[i].type == FIRE &&
							tankerOrder[i].row == targetRow + vectorx &&
							tankerOrder[i].col == targetCol + vextory &&
							(WallLife -= data->tank[i].attack) <= 0)
							break;

					if (i >= MAX_TANK_NUM)
					{
						tankerOrder[myTanker->ID].row = targetRow + vectorx;
						tankerOrder[myTanker->ID].col = targetCol + vextory;
						tankerOrder[myTanker->ID].type = FIRE;
						return;
					}
				}
			}
	}
}


// fire enemy, find weakest on fire it
void
fireEN(struct DataForAI *data,struct  TankData *myTanker)
{
	int i, j;
	int enemyNum;
	int fireID[MAX_TANK_NUM];
	int fireENX[MAX_TANK_NUM];
	int fireENY[MAX_TANK_NUM];
	int ENlife[MAX_TANK_NUM];
	int minLife;
	int weakTankID;

	memset(fireID, 0, sizeof(fireID));
	memset(fireENX, 0, sizeof(fireENX));
	memset(fireENY, 0, sizeof(fireENY));

	// only striker will fire, enemy can be seen
	enemyNum = getRangeEN(data, myTanker->row, myTanker->col, STRIKER_RANGE, fireID, fireENX, fireENY);

	if (enemyNum == 0)
		return;

	for(i = 0;i < enemyNum;i++)
		ENlife[fireID[i]] = data->tank[fireID[i]].life;

	for(i = 0;i < enemyNum;i++)
		for(j = 0;j < MAX_TANK_NUM;j++)
			if (data->tank[j].flag == data->myFlag && data->tank[j].life > 0)
			{
				if (tankerOrder[j].type == FIRE &&
					tankerOrder[j].row == fireENX[fireID[i]] &&
					tankerOrder[j].col == fireENY[fireID[i]])
					ENlife[fireID[i]] -= data->tank[j].attack;
			}

	// find weakest tank
	minLife = 100;
	weakTankID = -1;
	for(i = 0;i < enemyNum;i++)
	{
		if (ENlife[fireID[i]] > 0 &&
			ENlife[fireID[i]] < minLife)
		{
			minLife = ENlife[fireID[i]];
			weakTankID = fireID[i];
		}
	}

	// fire weakest tank
	if (weakTankID != -1)
	{
		tankerOrder[myTanker->ID].row = fireENX[weakTankID];
		tankerOrder[myTanker->ID].col = fireENY[weakTankID];
		tankerOrder[myTanker->ID].type = FIRE;
	}
}

/*******************utility function end*************************/

//平台0回合时调用此函数获取AI名称及坦克类型信息，请勿修改此函数声明。
extern "C" InitiateInfo chooseType()
{
	InitiateInfo Info;
	Info.tank[0]=Striker;
	Info.tank[1]=Striker;
	Info.tank[2]=Striker;
	Info.tank[3]=Striker;
	Info.tank[4]=Striker;
	strcpy(Info.aiName,"ufo008ahw"); //AI名请勿使用中文。 
	return Info;
}

//平台从第1回合开始调用此函数获得每回合指令，请勿修改此函数声明。
extern "C" Order makeOrder(DataForAI data)
{
	Order order;
	findOrder(data, &order);
	return order;
}

