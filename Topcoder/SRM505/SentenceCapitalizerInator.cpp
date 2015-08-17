#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
class SentenceCapitalizerInator
{
public:
string fixCaps(string paragraph)
{
	string temp = paragraph;
	string::iterator it;
	for(it = temp.begin();it != temp.end();it++)
	{
		while(it != temp.end() && (*it < 'a' || *it > 'z'))
			it++;
		if (it == temp.end())
			break;

		*it += 'A' - 'a';
		while(it != temp.end() && *it != '.')
			it++;
		if (it == temp.end())
			break;
	}
	return temp;
}
}; 
