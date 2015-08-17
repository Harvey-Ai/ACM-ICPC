#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

vector<int> primes;
void getPrime(int n)
{
	for(int i = 2;i <= n;i++)
	{
		int j;
		for(j = 2;j * j <= i;j++)
			if (i % j == 0)
				break;
		if (j * j > i)
			primes.push_back(i);
	}
}

int isPrime(int num)
{
	for(int i = 2;i * i <= num;i++)
		if (num % 2 == 0)
			return 0;
	return 1;
}

int main()
{
	int n;
	cin >> n;

	int arr[n + 1];
	memset(arr, 0, sizeof(arr));
	getPrime(n);

	vector<int> res;
	vector<int> left;
	for(int i = 0;i < primes.size();i++)
	{
		vector<int> temp;
		for(int j = primes[i];j <= n;j += primes[i])
			if (arr[j] == 0 && !(primes[i] == 2 && j > 4 && isPrime(j / 2)))
			{
				temp.push_back(j);
				arr[j] = 1;
			}

		if (temp.size() == 1)
			continue;

		for(int j = 0;j < temp.size();j++)
		{
			if ((temp[j] == primes[i] * 2) && (temp.size() % 2 == 1))
				left.push_back(temp[j]);
			else
				res.push_back(temp[j]);
		}
	}

	for(int i = 0;i + 1 < left.size();i += 2)
	{
		res.push_back(left[i]);
		res.push_back(left[i + 1]);
	}

	cout << res.size() / 2 << endl;
	for(int i = 0;i < res.size();i += 2)
		cout << res[i] << " " << res[i + 1] << endl;
	return 0;
}
