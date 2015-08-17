/*
题目描述

定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
*/

class Solution {
public:
    stack<int> minStack;
    stack<int> stack;
     
    void push(int value) {
        stack.push(value);
         
        int minVal = value;
        if (!minStack.empty())
            minVal = std::min(minVal, minStack.top());
        minStack.push(minVal);
    }
     
    void pop() {
        stack.pop();
        minStack.pop();
    }
    int top() {
        return stack.top();
    }
    int min() {
        return minStack.top();
    }
};
