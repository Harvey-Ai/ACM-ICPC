#include <stdio.h>

double getProbability(int waitTime, int walkTime, int lateTime, int bestArrival, int worstArrival)
	{
		int circleTime, beginTime, sumOut, circleNum, firstBegin, firstEnd, temp;
		double a = 1.0;

		circleTime = waitTime + walkTime;
		sumOut = 0;

		if (lateTime >= walkTime)
			return 0;

		if (bestArrival == worstArrival)
		{
			beginTime = (worstArrival / circleTime)* circleTime;

			if (beginTime + circleTime >= worstArrival + lateTime && beginTime + waitTime < worstArrival)
				return 1;
			else
				return 0;
		}

		beginTime = bestArrival / circleTime * circleTime;
		firstEnd = beginTime + circleTime - lateTime < worstArrival ? beginTime + circleTime - lateTime : worstArrival;
		firstBegin = bestArrival > beginTime + waitTime ? bestArrival : beginTime + waitTime;
		if (firstEnd > firstBegin)
			sumOut = firstEnd - firstBegin;

		beginTime += circleTime;

		circleNum = (worstArrival - beginTime) / circleTime;

		sumOut += circleNum * (circleTime - lateTime - waitTime);

		beginTime += circleNum * circleTime;

		if (beginTime + waitTime < worstArrival && beginTime + circleTime >= worstArrival)
		{
			temp = worstArrival < beginTime + circleTime - lateTime ? worstArrival : beginTime + circleTime - lateTime;
			if (temp > beginTime + waitTime)
				sumOut += temp - beginTime + waitTime;
		}

		return a * sumOut / (worstArrival - bestArrival);
	}

int main()
{
	printf("%ld\n", getProbability(10, 100, 50, 59, 60));
	return 0;
}
