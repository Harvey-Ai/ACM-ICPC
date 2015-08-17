/*
A consortium of European Internet providers manages a large backbone network, with direct links (connections) between a large number of European cities. A link between a pair of cities is bidirectional. The transmission of a message in a link has an associated cost. As it is common in the Internet, it is possible to use a(unbounded) sequence of direct links to indirectly transfer data between any pair of cities.

For allowing the broadcast of TV programs using this backbone, it is necessary to continuously send data to all nodes in the network. For helping to minimize costs, it is necessary to select the network links that will be used for transmitting data. The set of selected links must be connected and include all nodes in the network.

For helping the consortium to manage its network, you have been asked to create a program that computes the minimum cost for transmitting data to all cities of the backbone.

Given a set of network links, compute the minimum transmission cost for reaching all nodes.

Input

A positive integer P in a single line followed by a sequence of P test cases. The first line of the each test case contains a positive integer M, not greater than 2,000, with the number of cities that have network connections. The second line contains an integer N not greater than 50,000, with the number of existing links. Each of the following N lines contains the representation of a link. Each line contains two strings and one integer, separated by empty spaces, B E C, where B and E are the city names of the endpoints of the network link, with no more than 8 characters, and C is a positive integer, not greater than 30, representing the cost of transmitting in the link.

Output

The output consists of one single line that contains an integer with the minimum transmission cost for sending data to all cities.

Sample Input

1
4
5
lisbon london 6
lisbon paris 5
london paris 1
london berlin 2
paris berlin 10
Sample Output

8
*/


#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int  root[2005];
struct  EDGEDATA
{
	int beg,end;
	int  q;
}e[50005];
bool cmp(const EDGEDATA a,const EDGEDATA b)
{
	return a.q<b.q;
}
int find(int x){//
