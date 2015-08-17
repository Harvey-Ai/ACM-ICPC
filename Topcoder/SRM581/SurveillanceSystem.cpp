#include <string>
#include <vector>
using namespace std;
class SurveillanceSystem {
	public:
	string getContainerInfo(string containers, vector <int> reports, int L)
    {
        vector<int> monitorC[51];
        vector<int> survel;

        for(int i = 0;i < containers.size();i++)
        {
            string s = "";
            for(int j = 0;j < L && i + L <= containers.size();j++)
                s += containers[i + j];
            if (s.size() != L)
                break;
            
            int count = 0;
            for(int j = 0;j < L;j++)
                if (s[j] == 'X')
                    count++;
            monitorC[count].push_back(i);
        }

        char res[100];
        for(int i = 0;i < 100;i++)
            res[i] = '-';
        //sort(&reports[0], &reports[reports.size()]);
        
        

        survel.resize(100);
        for(int i = 0;i < reports.size();i++)
            survel[reports[i]]++;

        for(int i = 0;i <= L;i++)
        {
            int counts[100];
            memset(counts, 0, sizeof(counts));
             for(int j = 0;j < monitorC[i].size();j++)
                for(int k = monitorC[i][j]; k < monitorC[i][j] + L;k++)
                    counts[k]++;

            for(int j = 0;j < containers.size();j++)
                if (counts[j] + survel[i] > monitorC[i].size())
                {

                    res[j] = '+';
                }
                else
                {
                    if (res[j] != '+' && counts[j] > 0 && survel[i] > 0)
                    {
                        if (j == 3)
                            printf("count %d survel %d m %d\n", counts[j], survel[i], monitorC[i].size());
                        res[j] = '?';
                    }
                }
        }
        string resString(res, containers.size());
        return resString;
	}
};
