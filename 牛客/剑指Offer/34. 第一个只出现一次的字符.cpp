/*
题目描述

在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符的位置。若为空串，返回-1
*/

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int count[256];
        memset(count, 0, sizeof(count));
         
        for(auto c : str) {
            count[c]++;
        }
         
        for(int i = 0;i < str.size();i++) {
            if (count[str[i]] == 1) {
                return i;
            }
        }
         
        return -1;
         
    }
};
