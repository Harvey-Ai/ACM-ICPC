/*
描述
Standard web browsers contain features to move backward and forward among the pages recently visited. One way to implement these features is to use two stacks to keep track of the pages that can be reached by moving backward and forward. In this problem, you are asked to implement this. 
The following commands need to be supported: 
BACK: Push the current page on the top of the forward stack. Pop the page from the top of the backward stack, making it the new current page. If the backward stack is empty, the command is ignored. 
FORWARD: Push the current page on the top of the backward stack. Pop the page from the top of the forward stack, making it the new current page. If the forward stack is empty, the command is ignored. 
VISIT : Push the current page on the top of the backward stack, and make the URL specified the new current page. The forward stack is emptied. 
QUIT: Quit the browser. 
Assume that the browser initially loads the web page at the URL http://www.acm.org/
输入
Input is a sequence of commands. The command keywords BACK, FORWARD, VISIT, and QUIT are all in uppercase. URLs have no whitespace and have at most 70 characters. You may assume that no problem instance requires more than 100 elements in each stack at any time. The end of input is indicated by the QUIT command.
输出
For each command other than QUIT, print the URL of the current page after the command is executed if the command is not ignored. Otherwise, print "Ignored". The output for each command should be printed on its own line. No output is produced for the QUIT command.
样例输入
VISIT http://acm.ashland.edu/
VISIT http://acm.baylor.edu/acmicpc/
BACK
BACK
BACK
FORWARD
VISIT http://www.ibm.com/
BACK
BACK
FORWARD
FORWARD
FORWARD
QUIT
样例输出
http://acm.ashland.edu/
http://acm.baylor.edu/acmicpc/
http://acm.ashland.edu/
http://www.acm.org/
Ignored
http://acm.ashland.edu/
http://www.ibm.com/
http://acm.ashland.edu/
http://www.acm.org/
http://acm.ashland.edu/
http://www.ibm.com/
Ignored
*/

#include <iostream>
using namespace std;

int main()
{
	string stack1[100], stack2[100];
	string site, str;
	int pos1, pos2;
	pos1 = pos2 = 0;
	string pre = "http://www.acm.org/";
	while(cin >> str, str != "QUIT")
	{
		if (str == "VISIT")
		{
			cin >> site;
			cout << site << endl;
			stack1[pos1++] = pre;
			pre = site;
			pos2 = 0;
		}
		else if (str == "BACK")
		{
			if (pos1)
			{
				pos1--;
				cout << stack1[pos1] << endl;
				stack2[pos2++] = pre;
				pre = stack1[pos1];
			}
			else
				cout << "Ignored" << endl;
		}
		else if (str == "FORWARD")
		{
			if (pos2)
			{
				pos2--;
				cout << stack2[pos2] << endl;
				stack1[pos1++] = pre;
				pre = stack2[pos2];
			}
			else
				cout << "Ignored" << endl;
		}
	}
	return 0;
}
