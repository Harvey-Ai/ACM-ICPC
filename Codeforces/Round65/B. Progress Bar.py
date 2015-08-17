n, k, t = map (int, raw_input ().split ())
sum = (t * n * k / 100)
for i in range(n):
	if (sum >= k):
		sum -= k
		print str(k) + " "
	else:
		print str(sum) + " "
		sum = 0
