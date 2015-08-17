#include <iostream>
using namespace std;
#define N 2007
int main()
{
	int sieve[2008];
	int i,s,t,p;
	for(i = 2; i <= N; i++) 
	 sieve[i] = 1; 

  	for(i = 2; i <= N / 2; i++) 
	 sieve[i * 2] = 0; 

	p = 2; 

	while(p * p <= N) 
	{ 
		p = p + 1; 
		while(sieve[p] == 0) 
			p++; 

		t = p * p; 
		s = 2 * p; 
		while(t <= N) 
		{ 
			sieve[t] = 0;  
			t = t + s; 
		} 
	} 
	for(i = 1000; i <= N; i++) 	 
		if(sieve[i] != 0) 
			cout<<i<<endl;  
	return 0;
} 
  
