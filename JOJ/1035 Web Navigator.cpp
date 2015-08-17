#include <iostream>
#include <string>
using namespace std;
class stack
{
private:
	string s[102];
	int top;
public:
	stack();
	string pop();
	void push(string t);
	bool empty();
	void clear();
};

stack::stack()
{
	top=-1;
}

string stack::pop()
{
	top--;
	return s[top+1];
	
}

void stack::push(string t)
{
	top++;
	s[top]=t;
}

bool stack::empty()
{
	return top==-1;
}

void stack::clear()
{
	top=-1;
}

int main()
{
	stack f,b;
	int n;
	string commond="0",s;
	cin>>n;
	bool flag=0;
	while(n--)
	{
		cin.get();
		if(flag)
			cout<<endl;
		else
			flag=1;
		cin>>commond;
		f.clear();b.clear();
		b.push("http://www.acm.org/");
		while(commond!="QUIT")
		{
			if(commond=="VISIT")
			{
				cin>>s;
				cout<<s<<endl;
				f.clear();
				b.push(s);
			}
			if(commond=="BACK")
			{
				f.push(b.pop());
				if(!b.empty())
				{
					s=b.pop();
					cout<<s<<endl;
					b.push(s);
				}
				else
				{
					s=f.pop();
					b.push(s);
					cout<<"Ignored"<<endl;
				}
			}
			if(commond=="FORWARD")
			{
				if(!f.empty())
				{
					s=f.pop();
					cout<<s<<endl;
					b.push(s);
				}
				else
					cout<<"Ignored"<<endl;
			}
			cin>>commond;
		}
	}
	return 0;
}





