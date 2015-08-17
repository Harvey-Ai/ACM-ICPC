#include <stdio.h>
#include <set>
using namespace std;
#define N 1000005

int main()
{
	set<int> st;
	set<int>::iterator it;
	int a, n;
	int arr[2];
	while(scanf("%d", &n), n)
	{
		st.clear();
		n *= 2;
		while(n--)
		{
			scanf("%d", &a);
			it = st.find(a);
			if (it == st.end())
				st.insert(a);
			else
				st.erase(it);
		}
		for(i = 0, it = st.begin();it != st.end();it++, i++)
			arr[i] = *it;
		arr[0] > arr[1] ? printf("%d %d\n", arr[1] : arr[0]) : printf("%d %d\n", arr[0] : arr[1]); 
	}
	return 0;
}

//////////////////////////////////
   1.
      #include<iostream>
   2.
      #include<vector>
   3.
      #include<algorithm>
   4.
      #include<cstdio>
   5.
      using namespace std;
   6.
      int num[1000001];
   7.
      int n;
   8.
      void init(){
   9.
      int i;
  10.
      for(i=0;i<2*n;i++){
  11.
      scanf("%d",&num[i]);
  12.
      }
  13.
      sort(num,num+2*n);
  14.
      }
  15.
      void cal(){
  16.
      int i;
  17.
      int mm=-1024,mmin=-1024;
  18.
      for(i=0;i<2*n-1;){
  19.
      if(num[i]!=num[i+1]){
  20.
      if(mm==-1024){
  21.
      mm=num[i];
  22.
      }
  23.
      else{
  24.
      mmin=num[i];
  25.
      }
  26.
      i++;
  27.
      continue;
  28.
      }
  29.
      i=i+2;
  30.
      }
  31.
      if(mmin==-1024){
  32.
      mmin=num[2*n-1];
  33.
      }
  34.
      cout<<mm<<" "<<mmin<<endl;
  35.
      }
  36.
      int main(){
  37.
      while(cin>>n){
  38.
      if(n==0){
  39.
      break;
  40.
      }
  41.
      init();
  42.
      cal();
  43.
      }
  44.
      return 0;
  45.
      }


