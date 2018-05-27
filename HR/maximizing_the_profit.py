import sys
from bisect import *

def maximumProfit(p):
	profit = -1
	if len(p) < 3:
		return profit
	left = p[:1]
	right = sorted(p[1:])
	for pj in p[1:len(p)-1]:
		right.pop(bisect_left(right, pj))
		pl = []
		pr = []
		l_min = left[0]
		if l_min >= pj:
			insort(left, pj)
			continue
		pl.append(l_min)
		r_max = right[-1]
		if r_max <= pj:
			insort(left, pj)
			continue
		pr.append(r_max)
		index_l_pred = bisect_left(left, pj)
		if index_l_pred == len(left) or left[index_l_pred] >= pj:
			index_l_pred -= 1
		if not left[index_l_pred] == l_min:
			pl.append(left[index_l_pred])
		index_r_succ = bisect_right(right, pj)
		if not right[index_r_succ] == r_max:
			pr.append(right[index_r_succ])
		for pi in pl:
			for pk in pr:
				profit = max(profit, pi*pj*pk)
				if profit == -1:
					profit = pi*pj*pk
		insort(left, pj)
	return profit

if __name__ == "__main__":
	n = int(sys.stdin.readline())
	p = [int(i) for i in sys.stdin.readline().split(" ")]
	print maximumProfit(p)
