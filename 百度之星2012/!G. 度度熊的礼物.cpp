/*
题目描述:
度度熊拥有一个自己的 Baidu 空间,度度熊时不时会给空间朋友赠送礼物,以增加度度熊与朋友之间的友谊值。度度熊在偶然的机会下得到了两种超级礼物,于是决定给每位朋友赠送一件超级礼物。不同类型的朋友在收到不同的礼物所能达到的开心值是不一样的。开心值衡量标准是这样的:每种超级礼物都拥有两个属性(A, B),每个朋友也有两种属性(X, Y),如果该朋友收到这个超级礼物,则这个朋友得到的开心值为 A*X + B*Y。由于拥有超级礼物的个数限制,度度熊很好奇如何分配这些超级礼物,才能使好友的开心值总和最大呢?
输入
第一行 n 表示度度熊的好友个数。
接下来 n 行每行两个整数表示度度熊好朋友的两种属性值 Xi, Yi。
接下来 2 行,每行三个整数 ki, Ai, Bi,表示度度熊拥有第 i 种超级礼物的个数以及两个属性值。
1<=n<=1000, 0<=Xi,Yi, Ai, Bi 1+k2>=n
输出
输出一行一个值表示好友开心值总和的最大值
样例输入
4
3 6
7 4
1 5
2 4
3 3 4
3 4 3
样例输出
118
提示
送给第一种礼物的人有 1,3,4,送给第二种礼物的人有 2
保证数据不会爆 int

*/
