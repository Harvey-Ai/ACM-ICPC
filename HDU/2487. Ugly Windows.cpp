/*
Problem Description
Sheryl works for a software company in the country of Brada. Her job is to develop a Windows operating system. People in Brada are incredibly conservative. They even never use graphical monitors! So Sheryl’s operating system has to run in text mode and windows in that system are formed by characters. Sheryl decides that every window has an ID which is a capital English letter (‘A’ to ‘Z’). Because every window had a unique ID, there can’t be more than 26 windows at the same time. And as you know, all windows are rectangular.

On the screen of that ugly Windows system, a window’s frame is formed by its ID letters. Fig-1 shows that there is only one window on the screen, and that window’s ID is ‘A’. Windows may overlap. Fig-2 shows the situation that window B is on the top of window A. And Fig-3 gives a more complicated overlapping. Of course, if some parts of a window are covered by other windows, you can’t see those parts on the screen. 

.........................
....AAAAAAAAAAAAA........
....A...........A........
....A...........A........
....A...........A........
....AAAAAAAAAAAAA........
......................... 

Fig-1

.........................
....AAAAAAAAAAAAA........
....A...........A........
....A.......BBBBBBBBBB...
....A.......B........B...
....AAAAAAAAB........B...
............BBBBBBBBBB...
......................... 

Fig-2







..........................
....AAAAAAAAAAAAA.........
....A...........A.........
....A.......BBBBBBBBBB....
....A.......B........BCCC.
....AAAAAAAAB........B..C.
.......C....BBBBBBBBBB..C.
.......CCCCCCCCCCCCCCCCCC. 
.......................... 

Fig-3

If a window has no parts covered by other windows, we call it a “top window” (The frame is also considered as a part of a window). Usually, the top windows are the windows that interact with user most frequently. Assigning top windows more CPU time and higher priority will result in better user experiences. Given the screen presented as Figs above, can you tell Sheryl which windows are top windows?
 

Input
The input contains several test cases.

Each test case begins with two integers, n and m (1 <= n, m <= 100), indicating that the screen has n lines, and each line consists of m characters.

The following n lines describe the whole screen you see. Each line contains m characters. For characters which are not on any window frame, we just replace them with ‘.’ . 

The input ends with a line of two zeros.

It is guaranteed that:

1) There is at least one window on the screen.
2) Any window’s frame is at least 3 characters wide and 3 characters high.
3) No part of any window is outside the screen.

 

Output
For each test case, output the IDs of all top windows in a line without blanks and in alphabet order.
 

Sample Input
9 26
..........................
....AAAAAAAAAAAAA.........
....A...........A.........
....A.......BBBBBBBBBB....
....A.......B........BCCC.
....AAAAAAAAB........B..C.
.......C....BBBBBBBBBB..C.
.......CCCCCCCCCCCCCCCCCC. 
..........................
7 25
.........................
....DDDDDDDDDDDDD........
....D...........D........
....D...........D........
....D...........D..AAA...
....DDDDDDDDDDDDD..A.A...
...................AAA...
0 0
 

Sample Output
B
AD
*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

char winChars[105][105];
int main()
{
    int n, m;
    
    while(cin >> n >> m)
    {
        if (n == 0 || m == 0)
            break;

    for(int i = 0;i < n;i++)
        cin >> winChars[i];


    int VBar[27][2], HBar[27][2];
    memset(VBar, -1, sizeof(VBar));
    memset(HBar, -1, sizeof(HBar));

    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            if (winChars[i][j] != '.')
            {
                int index = winChars[i][j] - 'A';
                if (VBar[index][0] == -1 || VBar[index][0] > j)
                    VBar[index][0] = j;
                if (VBar[index][1] == -1 || VBar[index][1] < j)
                    VBar[index][1] = j;
                if (HBar[index][0] == -1 || HBar[index][0] > i)
                    HBar[index][0] = i;
                if (HBar[index][1] == -1 || HBar[index][1] < i)
                    HBar[index][1] = i;
            }

    int isTop[27];
    memset(isTop, 0, sizeof(isTop));
    for(int i = 0;i < 27;i++)
    {
        if (HBar[i][0] == -1)
            continue;

        if (HBar[i][1] - HBar[i][0] < 2 || VBar[i][1] - VBar[i][0] < 2)
        {
            isTop[i] = -1;
            continue;
        }
//    cout << (char)(i + 'A') << " " << HBar[i][0] << " " << HBar[i][1] << " " << VBar[i][0] << " " << VBar[i][1] << endl;
        for(int j = HBar[i][0];j <= HBar[i][1];j++)
            for(int k = VBar[i][0];k <= VBar[i][1];k++)
                if (j == HBar[i][0] || j == HBar[i][1] || k == VBar[i][0] || k == VBar[i][1])
                {
                    if (winChars[j][k] != 'A' + i)
                        isTop[i] = -1;
                }
                else if (winChars[j][k] != '.')
                    isTop[i] = -1;
                
        if (isTop[i] == 0)
            isTop[i] = 1;
    }

    for(int i = 0;i < 27;i++)
        if(isTop[i] == 1)
            cout << (char)(i + 'A');
    cout << endl;
    }
    return 0;
}
