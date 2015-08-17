/*
题目描述

请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/

class Solution {
public:
    void replaceSpace(char *str,int length) {
        int spaceNum = 0;
        for(int i = 0;i < length;i++)
            spaceNum += str[i] == ' ';
          
        int pos = length + spaceNum * 2 - 1;
        for(int i = length - 1;i >= 0;i--) {
            if (str[i] == ' ') {
                str[pos--] = '0', str[pos--] = '2', str[pos--] = '%';
            } else
                str[pos--] = str[i];
        }
    }
