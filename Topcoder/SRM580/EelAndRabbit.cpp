#include <string>
#include <vector>
#include <set>
using namespace std;
class EelAndRabbit {
	public:
	int getmax(vector <int> l, vector <int> t) {
        set<int> catchTime;

        for(int i = 0;i < t.size();i++)
        {
            catchTime.insert(t[i]);
            catchTime.insert(t[i] + l[i]);
        }

        int res = 0;
        int temp;
        int flag[55];
        for(set<int>::iterator it1 = catchTime.begin(); it1 != catchTime.end();it1++)
        {
            temp = 0;
            memset(flag, 0, sizeof(flag));
            for(int k = 0;k < l.size();k++)
                if (*it1 >= t[k] && *it1 <= t[k] + l[k])
                {
                    temp++;
                    flag[k] = 1;
                }
            set<int>::iterator it2 = it1;
            it2++;
            int max2 = 0;
            for(; it2 != catchTime.end();it2++)
            {
                int temp2 = 0;
                for(int k = 0;k < l.size();k++)
                    if (!flag[k] && *it2 >= t[k] && *it2 <= t[k] + l[k])
                        temp2++;
                if (temp2 > max2)
                    max2 = temp2;
            }
            if (max2 + temp > res)
                res = max2 + temp;
        }
        return res;
	}
};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
