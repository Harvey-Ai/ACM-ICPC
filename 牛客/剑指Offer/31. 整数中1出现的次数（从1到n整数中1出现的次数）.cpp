/*
题目描述

求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数。
*/

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int bitVal = 1;
        int count = 0;
         
        while(bitVal <= n) {
            if ((n / bitVal) % 10 > 1) count += (n / bitVal / 10 + 1) * bitVal;
            else if ((n / bitVal) % 10 == 1) count += (n / bitVal / 10) * bitVal +
                    n % bitVal + 1;
            else count += (n / bitVal / 10) * bitVal;
                 
            bitVal *= 10;
        }
         
        return count;
    }
};
