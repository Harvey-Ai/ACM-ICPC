#include <iostream>
#include <vector>
using namespace std;

struct machineType
{
	int num, time;
	machineType(int n, int t)
	{
		num = n;
		time = t;
	}
};

int main()
{
	int k, n1, n2, n3, t1, t2, t3;
	cin >> k >> n1 >> n2 >> n3 >> t1 >> t2 >> t3;
	int left1 = k, left2 = 0, left3 = 0;
	vector<machineType> p1, p2, p3;
	int leftM1 = n1, leftM2 = n2, leftM3 = n3;
	int res = 0;
	if (k > n1)
	{
		p1.push_back(machineType(n1, 0));
		leftM1 -= n1;
		left1 -= n1;
	}
	else
	{
		p1.push_back(machineType(k, 0));
		leftM1 -= k;
		left1 -= k;
	}

	while(left1 || left2 || left3 || p1.size() > 0 || p2.size() > 0 || p3.size() > 0)
	{
		res++;
		if (p1.size() > 0 && res - p1[0].time == t1)
		{
			left2 += p1[0].num;
			leftM1 += p1[0].num;
			p1.erase(p1.begin());
		}
		if (p2.size() > 0 && res - p2[0].time == t2)
		{
			left3 += p2[0].num;
			leftM2 += p2[0].num;
			p2.erase(p2.begin());
		}
		if (p3.size() > 0 && res - p3[0].time == t3)
		{
			leftM3 += p3[0].num;
			p3.erase(p3.begin());
		}

		if (left1 > 0 && leftM1 > 0)
		{
			if (left1 > leftM1)
			{
				p1.push_back(machineType(leftM1, res));
				left1 -= leftM1;
				leftM1 = 0;
			}
			else
			{
				p1.push_back(machineType(left1, res));
				leftM1 -= left1;
				left1 = 0;
			}
		}
		if (left2 > 0 && leftM2 > 0)
		{
			if (left2 > leftM2)
			{
				p2.push_back(machineType(leftM2, res));
				left2 -= leftM2;
				leftM2 = 0;
			}
			else
			{
				p2.push_back(machineType(left2, res));
				leftM2 -= left2;
				left2 = 0;
			}
		}
		if (left3 > 0 && leftM3 > 0)
		{
			if (left3 > leftM3)
			{
				p3.push_back(machineType(leftM3, res));
				left3 -= leftM3;
				leftM3 = 0;
			}
			else
			{
				p3.push_back(machineType(left3, res));
				leftM3 -= left3;
				left3 = 0;
			}
		}
	}
	cout << res << endl;
	return 0;
}
