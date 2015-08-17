/*
题目描述:
百度公司有一块长 a 米宽 b 米的矩形空地,空地的左上角坐标为(0,0),右下角坐标为(a,b)。空地上长着 n 株灌木,每株灌木都非常小。现在百度公司准备清理掉其中的一些灌木,在空地上修建两个长 28 米宽 15 米的篮球场。球场必须完全修建在空地内部(边缘可以和空地的边缘重合)且球场边缘必须与空地边缘平行,两个篮球场不允许重叠(不考虑边缘)。
在清理灌木的时候,只有球场内部的灌木需要清理掉,球场外部和边缘的灌木不用清理。请帮助百度公司找到一种球场的建设方案,使得需要清理的灌木最少。
注意:在最优方案中球场的左上角坐标可能是实数。
输入描述
输入包含多组数据。
每组数据的第一行包含两个整数 a、b,表示空地的长和宽。
第二行包含一个整数 n,表示空地上灌木的数量。
接下来 n 行表示所有灌木的坐标,其中第 i 行包含两个整数 xi、yi,表示第 i 个灌木的坐标为(xi,yi)。最后一组数据之后的一行为两个 0,表示输入结束。
输出描述
对于每组数据,输出一个整数,表示最少需要清理多少株灌木。
样例输入
50 40
3
11 17
24 26
36 20
0 0
样例输出
1
提示
空地、灌木和最优的球场修建方案如下图所示。对于 100%的数据,30≤ a, b ≤ 100,灌木的坐标都不相同。
*/



#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
 
int tree[105][105];
int main() {
    int a, b;
    while(cin >> a >> b) {
        if (a == 0 && b == 0)
            break;
 
        int n;
        scanf("%d", &n);
 
        memset(tree, 0, sizeof(tree));
        for(int i = 0;i < n;i++) {
            int x, y;
            cin >> x >> y;
            tree[x][y] = 1;
        }
 
        int sum[105][105], r[105], l[105], t[105], bb[105];
        for(int i = 0;i < 105;i++)
            l[i] = r[i] = bb[i] = t[i] = 105 * 105;
         
        memset(sum, 0, sizeof(sum));
        for(int i = 0;i <= a;i++) {
            if (i) t[i] = t[i - 1];
            for(int j = 0;j <= b;j++) {
                sum[i][j] = tree[i][j];
                if (i > 0) sum[i][j] += sum[i - 1][j];
                if (j > 0) sum[i][j] += sum[i][j - 1];
                if (i > 0 && j > 0) sum[i][j] -= sum[i - 1][j - 1];
                int temp = 105 * 105;
                if (i - 28 >= 0 && j - 15 >= 0) {
                    temp = min(sum[i - 1][j - 1] - sum[i - 1][j - 15] - sum[i - 28][j - 1] + sum[i - 28][j - 15], temp);
                }
 
                if (i - 15 >= 0 && j - 28 >= 0) {
                    temp = min(sum[i - 1][j - 1] - sum[i - 15][j - 1] - sum[i - 1][j - 28] + sum[i - 15][j - 28], temp);
                }
                t[i] = min(t[i], temp);
                if (j)
                    l[j] = min(l[j], l[j - 1]);
                l[j] = min(l[j], temp);
            }
        }
         
        memset(sum, 0, sizeof(sum));
        for(int i = a;i >= 0;i--) {
            if (i < a)
                bb[i] = bb[i + 1];
            for(int j = b;j >= 0;j--) {
                sum[i][j] = tree[i][j];
                if (i < a) sum[i][j] += sum[i + 1][j];
                if (j < b) sum[i][j] += sum[i][j + 1];
                if (i < a && j < b) sum[i][j] -= sum[i + 1][j + 1];
                int temp = 105 * 105;
                if (i + 28 <= a && j + 15 <= b) {
                    temp = min(sum[i + 1][j + 1] - sum[i + 1][j + 15] - sum[i + 28][j + 1] + sum[i + 28][j + 15], temp);
                }
 
                if (i + 15 <= a && j + 28 <= b) {
                    temp = min(sum[i + 1][j + 1] - sum[i + 15][j + 1] - sum[i + 1][j + 28] + sum[i + 15][j + 28], temp);
                }
                bb[i] = min(bb[i], temp);
 
                if (j < b)
                    r[j] = min(r[j], r[j + 1]);
                r[j] = min(temp, r[j]);
            }
        }
 
        int ans = 105 * 105;
        for(int i = 0;i <= b;i++) {
            ans = min(ans, l[i] + r[i + 1]);
        }
        for(int j = 0;j <= a;j++) {
            ans = min(ans, t[j] + bb[j + 1]);
        }
 
        cout << ans << endl;
    }
 
    return 0;
}
