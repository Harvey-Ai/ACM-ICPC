/*
题目描述

输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4，5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。
*/

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if (pushV.size() == 0)
            return false;
           
        stack<int> st;
        for(int i = 0, j = 0;i < pushV.size();i++) {
            st.push(pushV[i]);
               
            while(!st.empty() && st.top() == popV[j]) {
                j++;
                st.pop();
            }
        }
           
        return st.empty();
    }
};

