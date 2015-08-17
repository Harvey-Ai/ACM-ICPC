#include <vector>
#include <math.h>
using namespace std;
#define N 60


		int getMinimum(vector <int> holes, int largeJump)
		{
			int dp[N][2];
			int i, j, k;
			int res;
			int min;
			int pre1;
			int ppre1, jj;
			int holeNum, dpNum;

			dp[0][0] = 0;
			if (largeJump % 2)
				dp[0][1] = 1;
			else
				dp[0][1] = -1;

			dpNum = 1;
			for(i = 2;i < holes.size();i += 2)
			{
				dp[dpNum][0] = dp[dpNum][1] = -1;
				for(j = holes[i - 1] + 1;j < holes[i];j++)
				{
					pre1 = j - largeJump;
					min = -1;

					holeNum = 0;
					for(k = 0;k < holes.size();k += 2)
						if (pre1 < holes[k])
							break;
						else
							holeNum++;
					
					for(k = 1;k < holes.size();k += 2)
						if (pre1 >= holes[k - 1] &&
							pre1 <= holes[k])
							break;
					
					ppre1 = abs(pre1 & 0x01);
					if (k >= holes.size() && dp[holeNum][ppre1] != -1)
						min = dp[holeNum][ppre1] + 1;
	
				//	if (dpNum == 2)
				//	{
				//		printf("pre:%d %d\n", pre1, min);
				//	}
					jj = j & 0x01;
					dp[dpNum][jj] = min;
	
					if (dp[dpNum][0] != -1 && dp[dpNum][1] != -1)
						break;
				}
				if (dp[dpNum][0] == -1 && dp[dpNum][1] == -1)
					return -1;
				dpNum++;
			}

			dp[dpNum][0] = dp[dpNum][1] = -1;
			for(j = holes[holes.size() - 1] + 1;;j++)
			{
				pre1 = j - largeJump;
				min = -1;

				if (pre1 >= holes[holes.size() - 2])
					break;

				holeNum = 0;
				for(k = 0;k < holes.size();k += 2)
					if (pre1 < holes[k])
						break;
					else
						holeNum++;

				ppre1 = abs(pre1 % 2);
				for(k = 1;k < holes.size();k += 2)
					if (pre1 >= holes[k - 1] &&
						pre1 <= holes[k])
						break;

				if (k >= holes.size() && dp[holeNum][ppre1] != -1)
					min = dp[holeNum][ppre1] + 1;

				jj = j % 2;
				dp[dpNum][jj] = min;

				if (dp[dpNum][0] != -1 && dp[dpNum][1] != -1)
					break;
			}

			res = dp[dpNum][1];
			if ((res == -1 || res > dp[dpNum][0] + 1) && dp[dpNum][0] != -1 && largeJump % 2 == 1)
				res = dp[dpNum][0] + 1;
			return res;
		}
int main()
{
	vector <int> a(20, 5, 17, 27, 35, 37, 63, 83, 88, 182, 188, 207, 219, 359, 415, 435, 464, 479, 528, 532, 545, 584,
		598, 610, 699, 723, 754, 757, 814, 854, 855, 867, 877, 894, 916, 958, 962, 995, 1001, 1022,
		1038, 1084, 1109, 1152, 1275, 1309, 1355, 1449, 1489);


	printf("%d\n", getMinimum(a, 155));
}


