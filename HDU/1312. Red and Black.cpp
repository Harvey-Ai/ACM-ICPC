/*
Problem Description
There is a rectangular room, covered with square tiles. Each tile is colored either red or black. A man is standing on a black tile. From a tile, he can move to one of four adjacent tiles. But he can't move on red tiles, he can move only on black tiles.

Write a program to count the number of black tiles which he can reach by repeating the moves described above. 
 

Input
The input consists of multiple data sets. A data set starts with a line containing two positive integers W and H; W and H are the numbers of tiles in the x- and y- directions, respectively. W and H are not more than 20.

There are H more lines in the data set, each of which includes W characters. Each character represents the color of a tile as follows.

'.' - a black tile 
'#' - a red tile 
'@' - a man on a black tile(appears exactly once in a data set) 
 

Output
For each data set, your program should output a line which contains the number of tiles he can reach from the initial tile (including itself). 
 

Sample Input
6 9
....#.
.....#
......
......
......
......
......
#@...#
.#..#.
11 9
.#.........
.#.#######.
.#.#.....#.
.#.#.###.#.
.#.#..@#.#.
.#.#####.#.
.#.......#.
.#########.
...........
11 6
..#..#..#..
..#..#..#..
..#..#..###
..#..#..#@.
..#..#..#..
..#..#..#..
7 7
..#.#..
..#.#..
###.###
...@...
###.###
..#.#..
..#.#..
0 0
 

Sample Output
45
59
6
13
*/

#include <iostream>
using namespace std;
struct tnode
{
    int x,y;
};
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
char map[20][20];
int x2,y2;
tnode n0;
int num;
int w,h;
void dfs(int xs,int ys)
{
    int i;
    for(i=0;i<4;i++)
    {
        n0.x=xs+dir[i][0];
        n0.y=ys+dir[i][1];
        if(n0.x>=0&&n0.x<h&&n0.y>=0&&n0.y<w&&map[n0.x][n0.y]=='.')
        {
              num++;
              map[n0.x][n0.y]='#';
              dfs(n0.x,n0.y);
        }
    }
}
int main()
{
    while(cin>>w>>h,h||w)
    {
        int i,j;
        num=1;
        for(i=0;i<h;i++)
          for(j=0;j<w;j++)
           {
               cin>>map[i][j];
               if(map[i][j]=='@')
                {
                    x2=i;
                    y2=j;
                }
            }
        map[x2][y2]='#';
        dfs(x2,y2);
        cout<<num<<endl;  
    }
    return 0;
}
