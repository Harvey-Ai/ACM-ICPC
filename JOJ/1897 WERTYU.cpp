#include <iostream>
using namespace std;
int main()
{
	char c;
	while(cin.get(c))
	{
		switch(c)
		{
		case 'B':{cout<<'V';break;}
		case 'C':{cout<<'X';break;}
		case 'D':{cout<<'S';break;}
		case 'E':{cout<<'W';break;}
		case 'F':{cout<<'D';break;}
		case 'G':{cout<<'F';break;}
		case 'H':{cout<<'G';break;}
		case 'I':{cout<<'U';break;}
		case 'J':{cout<<'H';break;}
		case 'K':{cout<<'J';break;}
		case 'L':{cout<<'K';break;}
		case 'M':{cout<<'N';break;}
		case 'N':{cout<<'B';break;}
		case 'O':{cout<<'I';break;}
		case 'P':{cout<<'O';break;}
		case 'R':{cout<<'E';break;}
		case 'S':{cout<<'A';break;}
		case 'T':{cout<<'R';break;}
		case 'U':{cout<<'Y';break;}
		case 'V':{cout<<'C';break;}
		case 'W':{cout<<'Q';break;}
		case 'X':{cout<<'Z';break;}
		case 'Y':{cout<<'T';break;}
		case '[':{cout<<'P';break;}
		case ']':{cout<<"[";break;}
		case '\\':{cout<<"]";break;}
		case ';':{cout<<'L';break;}
		case ',':{cout<<'M';break;}
		case '.':{cout<<',';break;}
		case '/':{cout<<'.';break;}
		case '\'':{cout<<';';break;}
		}
		if(c>'1'&&c<='9')
			cout<<char(c-1);
		else
		{
			if(c=='1')
				cout<<'`';
			if(c=='0')
				cout<<'9';
		}
		if(c=='-')
			cout<<'0';
		if(c=='=')
			cout<<'-';
		if(c==' ')
			cout<<c;
		if(c==10)
			cout<<c;
	}
	return 0;
}