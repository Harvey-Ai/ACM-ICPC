#include <string>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;
class FoxAndClassroom {
	public:
	string ableTo(int n, int m) {
		int graph[20][20];
		memset(graph, 0, sizeof(graph));

		int posX = 0, posY = 0;
		int num = 0;
		while(!graph[posX][posY])
		{
			num++;
			graph[posX][posY] = 1;
			posX = (posX + 1) % m;
			posY = (posY + 1) % n;
		}
		return (num == m * n) ? "Possible" : "Impossible";
	}
};
