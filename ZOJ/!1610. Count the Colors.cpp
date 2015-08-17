/*
Painting some colored segments on a line, some previously painted segments may be covered by some the subsequent ones.
Your task is counting the segments of different colors you can see at last.


Input

The first line of each data set contains exactly one integer n, 1 <= n <= 8000, equal to the number of colored segments.

Each of the following n lines consists of exactly 3 nonnegative integers separated by single spaces:

x1 x2 c

x1 and x2 indicate the left endpoint and right endpoint of the segment, c indicates the color of the segment.

All the numbers are in the range [0, 8000], and they are all integers.

Input may contain several data set, process to the end of file.


Output

Each line of the output should contain a color index that can be seen from the top, following the count of the segments of this color, they should be printed according to the color index.

If some color can't be seen, you shouldn't print it.

Print a blank line after every dataset.


Sample Input

5
0 4 4
0 3 1
3 4 2
0 2 2
0 2 3
4
0 1 1
3 4 1
1 3 2
1 3 1
6
0 1 0
1 2 1
2 3 1
1 2 0
2 3 0
1 2 1


Sample Output

1 1
2 1
3 1

1 1

0 2
1 1
*/

