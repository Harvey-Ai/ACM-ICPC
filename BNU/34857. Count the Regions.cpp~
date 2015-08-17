#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct rectType
{
	int l, r, t, b;
};

int rectMap[305][305];
int dfs(int r, int c, int color)
{
	rectMap[r][c] = color;

	if (r + 1 < 300 && rectMap[r + 1][c] == 0)
		dfs(r + 1, c, color);
	if (c + 1 < 300 && rectMap[r][c + 1] == 0)
		dfs(r, c + 1, color);
	if (r - 1 >= 0 && rectMap[r - 1][c] == 0)
		dfs(r - 1, c, color);
	if (c - 1 >= 0 && rectMap[r][c - 1] == 0)
		dfs(r, c - 1, color);
}

int xMap[1000006], yMap[1000006];
int main()
{
	rectType rect[105];
	int n;
	while(cin >> n, n)
	{
        memset(xMap, 0, sizeof(xMap));
        memset(yMap, 0, sizeof(yMap));
		for(int i = 0;i < n;i++)
        {
			cin >> rect[i].l >> rect[i].t >> rect[i].r >> rect[i].b;
            xMap[rect[i].l] = xMap[rect[i].r] = 1;
            yMap[rect[i].t] = yMap[rect[i].b] = 1;
        }
		
		int xPos = 2;
        for(int i = 0;i < 1000006;i++)
            if (xMap[i])
            {
                xMap[i] = xPos;
                xPos += 2;
            }
        int yPos = 2;
        for(int i = 0;i < 1000006;i++)
            if (yMap[i])
            {
                yMap[i] = yPos;
                yPos += 2;
            }
        for(int i = 0;i < n;i++)
        {
            rect[i].l = xMap[rect[i].l];
            rect[i].r = xMap[rect[i].r];
            rect[i].t = yMap[rect[i].t];
            rect[i].b = yMap[rect[i].b];
        }
            
		memset(rectMap, 0, sizeof(rectMap));
		for(int i = 0;i < n;i++)
		{
			for(int x = rect[i].l;x <= rect[i].r;x++)
			{
				rectMap[x][rect[i].b] = -1;
				rectMap[x][rect[i].t] = -1;
			}
			for(int y = rect[i].b;y <= rect[i].t;y++)
			{
				rectMap[rect[i].l][y] = -1;
				rectMap[rect[i].r][y] = -1;
			}
		}
		int res = 1;
		for(int i = 0;i < 300;i++)
			for(int j = 0;j < 300;j++)
				if (rectMap[i][j] == 0)
                {
					dfs(i, j, res++);
                }
                
		cout << res - 1 << endl;
	}
	return 0;
}
