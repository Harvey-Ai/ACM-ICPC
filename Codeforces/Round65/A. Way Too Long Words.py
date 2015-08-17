n = input()
for i in range(n):
	str = raw_input()
	if (len(str) > 10):
		print str[0] + str(len(str) - 2) + str[len(str) - 1]
	else:
		print str
