/*
题目描述

请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
*/


class Solution {
public:
    
    bool match(char* str, char* pattern)
    {
        vector<int> PFlag;
        string pStr;
    
        ///frtttttttttttttttttttt
        for(int i = 0;pattern[i];i++) {
            if (pattern[i] == '*') {
                PFlag[PFlag.size() - 1] = -1;
            } else {
                pStr += pattern[i];
                PFlag.push_back(1);
            }
        }
          
        ///frtttttttttttttttttttt
        string mStr(str);
        vector<vector<bool> > dp(pStr.size() + 1, vector<bool>(mStr.size() + 1, 0));
        dp[0][0] = 1;
        for(int i = 1;i <= pStr.size();i++) {
            if (PFlag[i - 1] == -1) {
                dp[i][0] = 1;
            }
            else {
                break;
            }
        }
          
        ///frtttttttttttttttttttt
        for(int i = 0;i < pStr.size();i++) {
            for(int j = 0;j < mStr.size();j++) {
                if (PFlag[i] == 1) {
                    if (pStr[i] == '.') {
                        dp[i + 1][j + 1] = (dp[i][j] | dp[i + 1][j + 1]);
                    } else if (pStr[i] == mStr[j]) {
                        dp[i + 1][j + 1] = (dp[i][j] | dp[i + 1][j + 1]);
                    }
                } else {
                    dp[i + 1][j + 1] = (dp[i][j + 1] | dp[i + 1][j + 1]);
                    for(int k = j;k >= 0;k--) {
                        if (pStr[i] == mStr[k] || pStr[i] == '.') {
                            dp[i + 1][j + 1] = dp[i][k] | dp[i + 1][j + 1];
                        } else {
                            break;
                        }
                    }
                }
            }
        }
            
        return dp[pStr.size()][mStr.size()];
    }
};
