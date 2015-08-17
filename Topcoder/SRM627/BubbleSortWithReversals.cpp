#include <string>
#include <vector>
#include <iostream>
using namespace std;
class BubbleSortWithReversals {
    public:
    int getSubSwap(int a, int b, vector<int> A)
    {
        int swap1 = 0, swap2 = 0;
        for(int i = a + 1;i <= b;i++)
            for(int j = a;j < i;j++)
                if (A[i] < A[j])
                    swap1++;
                else if (A[i] > A[j])
                    swap2++;
        return swap2 - swap1;
    }
    int getMinSwaps(vector <int> A, int K) {
        int dp[55][55];
        if (K >= A.size())
            K = A.size();

        dp[0][0] = 0;
        for(int i = 1;i < A.size();i++)
        {
            dp[i][0] = dp[i - 1][0];
            for(int j = 0;j < i;j++)
                if (A[j] > A[i])
                    dp[i][0]++;
        }

        for(int i = 0;i < A.size();i++)
            for(int j = 1;j <= K && j <= i + 1;j++)
            {
                int minSwap = -1;
                if (j == 1) minSwap = dp[i][0] + getSubSwap(0, i, A);
                if (i >= j && (minSwap == -1 || minSwap > dp[i - 1][j] + dp[i][0] - dp[i - 1][0]))
                    minSwap = dp[i - 1][j] + dp[i][0] - dp[i - 1][0];
                for(int k = i - 1;k + 1 >= j - 1 && k >= 0;k--)
                    if (minSwap == -1 || minSwap > (dp[k][j - 1] + dp[i][0] - dp[k][0] + getSubSwap(k + 1, i, A)))
                        minSwap = dp[k][j - 1] + dp[i][0] - dp[k][0] + getSubSwap(k + 1, i, A);
                dp[i][j] = minSwap;
            }
        
        int min = dp[A.size() - 1][0];
        for(int j = 1;j <= K;j++)
            if (dp[A.size() -1][j] < min)
                min = dp[A.size() - 1][j];

        return min;
    }
};
