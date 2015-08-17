/*
题目描述

请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
*/


class Solution {
public:
     
    bool readDig(char *str, int &start) {
         
        if (str[start] == '+' || str[start] == '-')
            start++;
         
        int hasInt = false, hasFloat = false, hasPoint = false;
        while (str[start] >= '0' && str[start] <= '9') {
            start++;
            hasInt = true;
        }
         
        if (str[start] == '.') {
            start++;
            hasPoint = true;
            while (str[start] >= '0' && str[start] <= '9') {
                start++;
                hasFloat = true;
            }
        }
         
        if (!hasInt && !hasFloat)
            return false;
        return true;
    }
     
    bool readExp(char *str, int &start) {
        if (str[start] == '+' || str[start] == '-')
            start++;
         
        int hasInt = false;
        while (str[start] >= '0' && str[start] <= '9') {
            start++;
            hasInt = true;
        }
         
        return hasInt;
    }
     
    // symbol -> dig > point > dig -> E > dig
    bool isNumeric(char* string)
    {
        int start = 0;
        if (readDig(string, start) == false)
            return false;
         
        if (string[start] == 'e' || string[start] == 'E') {
            if (start - 1 >= 0 && string[start - 1] == '.') {
                return false;
            }
                 
            start++;
            if (readExp(string, start) == false) {
                return false;
            }
        }
         
        return string[start] == '\0';
    }
 
};
