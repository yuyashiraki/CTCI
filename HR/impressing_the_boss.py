import sys

def checker(a):
	prev = a[0]
	for s in a:
		if prev > s:
			return 0
		prev = s
	return 1


def canModify(a):
	for i in range(len(a)):
		if i == 0:
			rp = 0
		else:
			rp = a[i - 1]
		ca = a[:]
		ca[i] = rp
		if checker(ca):
			return "YES"
	return "NO"
		

t = int(sys.stdin.readline())
for i in range(t):
	n = int(sys.stdin.readline())
	a = [int(i) for i in sys.stdin.readline().split(" ")]
	print canModify(a)
