#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


class ShoutterDiv1 {

    struct rabbit
    {
        int id;
        int startTime, endTime;
    };
    public:
        int left[2555], right[2555];
        rabbit rts[2555];
        int num;

        static bool cmp1(rabbit a, rabbit b)
        {
            if (a.startTime < b.startTime)
                return 1;
            else
                return 0;
        }

        static bool cmp2(rabbit a, rabbit b)
        {
            if (a.endTime > b.endTime)
                return 1;
            else
                return 0;
        }
        int cross(int a, int b)
        {
            if (rts[a].endTime < rts[b].startTime ||
                    rts[b].endTime < rts[a].startTime)
                return 0;
            else
                return 1;
        }

        int count(vector <string> s1000, vector <string> s100, vector <string> s10, vector <string> s1, vector <string> t1000, vector <string> t100, vector <string> t10, vector <string> t1) {

            int minR = 10000000, maxL = 0;
            int l = 0;
            for(int i = 0;i < s1.size();i++)
                for(int j = 0;j < s1[i].size();j++)
                {
                    rts[l].id = l;
                    rts[l++].startTime = (s1000[i][j]-'0') * 1000 + (s100[i][j]-'0') * 100 + (s10[i][j] - '0') * 10 + s1[i][j] - '0';
                    if (rts[l - 1].startTime > maxL)
                        maxL = rts[l - 1].startTime; 
                }
           l = 0; 
            for(int i = 0;i < s1.size();i++)
                for(int j = 0;j < s1[i].size();j++)
                {
                    rts[l++].endTime = (t1000[i][j] - '0') * 1000 + (t100[i][j] - '0') * 100 + (t10[i][j] - '0') * 10 + t1[i][j] - '0';
                    if (rts[l - 1].endTime < minR)
                        minR = rts[l - 1].endTime;
                }


            num = l;
            sort(&rts[0], &rts[num], cmp1);
            left[rts[0].id] = 0;
            for(int i = 1;i < num;i++)
            {
                left[rts[i].id] = 2555;
                if (rts[i].startTime <= minR)
                    left[rts[i].id] = 0;
                for(int j = i - 1;j >= 0;j--)
                    if (cross(i, j))
                        left[rts[i].id] = min(left[rts[i].id], left[rts[j].id] + 1);
                if (left[rts[i].id] == 2555)
                    return -1;
            }
 
            sort(&rts[0], &rts[num], cmp2);
            right[rts[0].id] = 0;
            for(int i = 1;i < num;i++)
            {
                right[rts[i].id] = 2555;
                if (rts[i].endTime >= maxL)
                    right[rts[i].id] = 0;
                for(int j = i - 1;j >= 0;j--)
                    if (cross(i, j))
                        right[rts[i].id] = min(right[rts[i].id], right[rts[j].id] + 1);

                if (right[rts[i].id] == 2555)
                    return -1;
            }
   
            int ans = 0;
            int temp;
            for(int i = 0;i < num;i++)
            {
                temp = left[rts[i].id] + right[rts[i].id];
                for(int j = 0;j < num;j++)
                    if (i != j && cross(i, j))
                    {
                        int temp2 = left[rts[j].id] + right[rts[j].id] + 1;
                        if (temp > temp2)
                            temp = temp2;
                    }
                ans += temp;
            }
            return ans;
        }
};
