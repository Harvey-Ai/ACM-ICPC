/*
题目描述

地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
*/

class Solution {
public:
     
    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<vector<bool> > visit;
    int count;
    int th, r, c;
     
    bool check(int x, int y) {
        if (x < 0 || x >= r || y < 0 || y >= c)
            return false;
         
        int digSum = 0;
        while(x) {
            digSum += x % 10;
            x /= 10;
        }
        while(y) {
            digSum += y % 10;
            y /= 10;
        }
         
        return digSum <= th;
    }
     
    void dfs(int x, int y) {
        count++;
        visit[x][y] = true;
         
        for(int i = 0;i < 4;i++) {
            if (check(x + dir[i][0], y + dir[i][1])
                && !visit[x + dir[i][0]][y + dir[i][1]])
                dfs(x + dir[i][0], y + dir[i][1]);
        }
    }
     
    int movingCount(int threshold, int rows, int cols)
    {
        if (threshold < 0)
            return 0;
         
        visit = vector< vector<bool> >(rows, vector<bool>(cols, 0));
        th = threshold, r = rows, c = cols;
        count = 0;
         
        dfs(0,0);
         
        return count;
    }
};
