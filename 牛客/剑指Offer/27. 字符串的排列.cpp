/*
题目描述

输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。 
输入描述:
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
*/

class Solution {
public:
    int nextPem(string &str) {
        int pos;
        for(pos = str.size() - 2;pos >= 0 && str[pos] >= str[pos + 1];pos--);
        if (pos < 0)
            return -1;
         
        int minVal, minIndex = -1;
        for(int i = str.size() - 1;i > pos;i--) {
            if (str[i] > str[pos] && (minVal > str[i] || minIndex == -1))  {
                minVal = str[i];
                minIndex = i;
            }
        }
         
        swap(str[minIndex], str[pos]);
        reverse(str.begin() + pos + 1, str.end());
        return 0;
    }
     
    vector<string> Permutation(string str) {
         
        vector<string> ans;
        if (str == "")
            return ans;
         
        ans.push_back(str);
        while(nextPem(str) != -1) {
            ans.push_back(str);
        }
        return ans;
    }
};
