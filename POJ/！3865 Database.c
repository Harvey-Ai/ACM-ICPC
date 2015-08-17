#include <iostream>
#include <set> 
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int i, j, k;
	int m, n;
	int begin, end;
	int r1, r2, c1, c2;
	string str, temp;
	map<string, set<int> > d[12];
	set<int> ins;

	while(cin>> m >> n)
	{

		getchar();
		string str, temp;
		map<string, set<int> > d[12];
		set<int> ins;

		for(i = 0;i < m;i++)
		{
			getline(cin, str);
			begin = 0;
			for(k = 0;k < n;k++)
			{
				end = str.find(",", begin);
				temp = str.substr(begin, end - begin);
				begin = end + 1;

				d[k][temp].insert(i);
			}
		}

		r1 = r2 = c1 = c2 = -1;
		for(i = 0;i < n;i++)
			for(j = i + 1;j < n;j++)
			{
				map<string, set<int> >::iterator it1, it2;
				for(it1 = d[i].begin(); it1 != d[i].end(); it1++)
					for(it2 = d[j].begin(); it2 != d[j].end(); it2++)
					{
						
						ins.clear();
						std::set_intersection((it1->second).begin(), (it1->second).end(), (it2->second).begin(), (it2->second).end(), inserter(ins, ins.begin()));
						if (ins.size() > 1)
						{
							set< int >::iterator it;
							it = ins.begin();
							r1 = *(it++);
							r2 = *(it);
							c1 = i;
							c2 = j;
							break;
						}
						if (r1 != -1)
							break;
					}
				if (r1 != -1)
					break;
			}

		if (r1 != -1)
		{
			cout<<"NO"<<endl;
			cout<<r1 + 1<<" "<<r2 + 1<<endl;
			cout<<c1 + 1<<" "<<c2 + 1<<endl;
		}
		else
			cout<<"YES"<<endl;
	}
	return 0;
}
