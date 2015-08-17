/*
Problem Description
      Mr. Pote's shop sells beans now. He has N bags of beans in his warehouse, and he has numbered them with 1, 2, …, N according to their expired dates. The i-th bag contains Wi units of beans. For selling at retail makes only a little profit, Mr. Pote want to pack beans in small packets with certain size and sell them in packets. Here comes his packing way:
      Suppose the size of the packet is P units. Firstly, Mr. Pote selects some bags (at least one) of beans with consecutive number in his warehouse. Then he takes out the beans from all selected bags, and puts them together on the desktop. To pack the beans, he take P units of beans from desktop and fill in a new packet each time, until the beans left are less than P units. Finally the beans left on the desktop are eaten by a lucky dog.
      Mr. Pote doesn't want the dog eat too many beans, so he prefers to solutions that resulting no more than K units of beans eaten by the dog. Moreover, he also wants to pack as many packets as possible. Could you tell him how many packets he can pack at most without breaking his preference?
 

Input
      On the first line of input, there is a single positive integer T <= 20 specifying the number of test cases to follow. 
      Each test case contains two lines. 
      There are three integers in the first line, N, P, K as described above. (0 < N, P < 1000001, 0 <= K < P)
      Next follow a line with N integers W1, W2, ..., WN. The i-th integers describes the amount of beans in the bags numbered i. (0 <= Wi < 32768)
      Numbers are separated by spaces.
 

Output
      For each test case you should output a single line containing "Case X: Y" (quotes for clarity) where X is the number of the test case (starting at 1) and Y is the maximum number of packets that Mr. Pote can pack following his way. 
      In case there's no solution avoiding the dog eats more than K units of beans, Y should be equal to -1.
 

Sample Input
3
10 20 10
0 3 1 8 19 39 2 9 1 8
3 100 10
32 34 23
1 5 3
1
 

Sample Output
Case 1: 4
Case 2: -1
Case 3: 0
*/

