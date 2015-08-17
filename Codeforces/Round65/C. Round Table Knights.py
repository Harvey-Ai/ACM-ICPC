import sys

def check(arr, head, dis, n):
	if arr[head] != 1:
		return 0
	pos = head + dis
	while pos != head:
		if arr[pos] != 1:
			return 0
		else:
			pos += dis
			pos %= n
	return 1
	
n = input();
kn = raw_input().split()
for i in range(len(kn)):
	kn[i] = int(kn[i])

flag = 0
i = 1
while i * i <= n:
	if (n % i == 0):
		step = i
		if n / step > 2:
			for j in range(0, step):
				if (check(kn, j, step, n) == 1):
					flag = 1
					break
		step = n / i
		if n / step > 2:
			for j in range(0, step):
				if (check(kn, j, step, n) == 1):
					flag = 1
					break
		if flag == 1:
			break
	if flag == 1:
		break
	i += 1

if flag == 1:
	print "YES"
else:
	print "NO"
