#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class KeyDungeonDiv2 {
	public:
	int countDoors(vector <int> doorR, vector <int> doorG, vector <int> keys) {
		int res = 0;
		for(int i = 0;i < doorR.size();i++)
		{
			int red = doorR[i] - keys[0] < 0 ? 0 : (doorR[i] - keys[0]);
			int green = doorG[i] - keys[1] < 0 ? 0 : (doorG[i] - keys[1]);
			
			if (red + green <= keys[2])
				res++;
		}
		return res;
	}
};
