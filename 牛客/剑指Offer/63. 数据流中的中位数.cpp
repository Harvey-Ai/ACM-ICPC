/*
题目描述

如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
*/

class Solution {
public:
     
    priority_queue<int, vector<int>, less<int> > firstMaxQ;
    priority_queue<int, vector<int>, greater<int> > secondMinQ;
     
    void Insert(int num)
    {
        if (secondMinQ.size() && num >= secondMinQ.top() || secondMinQ.empty())
            secondMinQ.push(num);
        else {
            firstMaxQ.push(num);
        }
         
        if (firstMaxQ.size() > secondMinQ.size()) {
            int val = firstMaxQ.top();
            firstMaxQ.pop();
            secondMinQ.push(val);
        }
         
        if (secondMinQ.size() > firstMaxQ.size() + 1) {
            int val = secondMinQ.top();
            secondMinQ.pop();
            firstMaxQ.push(val);
        }
    }
 
    double GetMedian()
    {
        if (secondMinQ.size() > firstMaxQ.size())
            return secondMinQ.top();
        else
            return (secondMinQ.top() + firstMaxQ.top()) / 2.0;
    }
 
};
