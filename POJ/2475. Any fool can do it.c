/*
Description

Surely you know someone who thinks he is very clever. You decide to let him down with the following problem: 
"Can you tell me what the syntax for a set is?", you ask him. 
"Sure!", he replies, "a set encloses a possibly empty list of elements within two curly braces. Each element is either another set or a letter of the given alphabet. Elements in a list are separated by a comma." 
"So if I give you a word, can you tell me if it is a syntactically correct representation of a set?" 
"Of course, any fool can do it!" is his answer.

Now you got him! You present him with the following grammar, defining formally the syntax for a set (which was described informally by him): 
Set          ::= "{" Elementlist "}"

Elementlist  ::= <empty> | List

List         ::= Element | Element "," List

Element      ::= Atom | Set

Atom         ::= "{" | "}" | ","


<empty> stands for the empty word, i.e., the list in a set can be empty. 
Soon he realizes that this task is much harder than he has thought, since the alphabet consists of the characters which are also used for the syntax of the set. So he claims that it is not possible to decide efficiently if a word consisting of "{", "}" and "," is a syntactically correct representation of a set or not. 
To disprove him, you need to write an efficient program that will decide this problem.
Input

The first line of the input contains a number representing the number of lines to follow. 
Each line consists of a word, for which your program has to decide if it is a syntactically correct representation of a set. You may assume that each word consists of between 1 and 200 characters from the set { "{", "}", "," }.
Output

Output for each test case whether the word is a set or not. Adhere to the format shown in the sample output.
Sample Input

4
{}
{{}}
{{}},{,}}
{,,}
Sample Output

Word #1: Set
Word #2: Set
Word #3: Set
Word #4: No Set
*/


#include <stdio.h>
#include <string.h>
#define N 205
#define false 0
#define true 1

char str[N];
int elm[N][N], list[N][N], set[N][N];

int isElm(int begin, int end)
{
	if (begin > end)
		return false;
	if (elm[begin][end])
		return elm[begin][end] - 1;
	if (end != begin)
		elm[begin][end] = isSet(begin, end) + 1;
	else
		if (str[begin] == '{' || str[begin] == '}' || str[begin] == ',')
			elm[begin][end] = true + 1;
		else
			elm[begin][end] = false + 1;
	return elm[begin][end] - 1;
}
int isList(int begin, int end)
{
	int i;
	if (begin > end)
		return false;
	if (list[begin][end])
		return list[begin][end] - 1;
	if (isElm(begin, end))
		list[begin][end] = true + 1;
	else
	{
		//the splitter ',' can't be in the end and begin position of list
		for(i = begin + 1;i < end;i++)
			if (str[i] == ',' && (isElm(begin, i - 1) && isList(i + 1, end)))
			{
					list[begin][end] = true + 1;
					break;
			}
	}
	if (!list[begin][end])
		list[begin][end] = false + 1;
	return list[begin][end] - 1;
}
int isElmList(int begin, int end)
{
	if (begin > end)
		return true;
	else
		return isList(begin, end);

}
int isSet(int begin, int end)
{
	if (begin >= end)
		return false;
	if (set[begin][end])
		return set[begin][end] - 1;
	if (str[begin] == '{' && str[end] == '}' && isElmList(begin + 1, end - 1))
		set[begin][end] = true + 1;
	else
		set[begin][end] = false + 1;
	return set[begin][end] - 1;
}
int main()
{
	int i, len, res, n;
	scanf("%d", &n);
	for(i = 0;i < n;i++)
	{
		scanf("%s", str);
		memset(elm, 0, sizeof(elm));
		memset(list, 0, sizeof(list));
		memset(set, 0, sizeof(set));
		len = strlen(str);
		res = isSet(0, len - 1);

		res ? printf("Word #%d: Set\n", i + 1) : printf("Word #%d: No Set\n", i + 1);
	}
	return 0;
}
