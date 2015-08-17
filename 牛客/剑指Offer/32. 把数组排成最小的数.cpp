/*
题目描述

输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
*/

class Solution {
public:
    static string itoa(int n) {
        if (n == 0)
            return "0";
         
        string res;
        while(n) {
            res += n % 10 + '0';
            n /= 10;
        }
         
        reverse(res.begin(), res.end());
        return res;
    }
     
    static bool cmp(int a, int b) {
        string stra = itoa(a);
        string strb = itoa(b);
         
        if (stra + strb < strb + stra)
            return true;
        else
            return false;
    }
     
    string PrintMinNumber(vector<int> numbers) {
        sort(numbers.begin(), numbers.end(), Solution::cmp);
         
        string res;
        for(auto num : numbers) {
            res += itoa(num);
        }
         
        return res;
    }
};
