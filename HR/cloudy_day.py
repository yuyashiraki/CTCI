#!/bin/python

import sys
from bisect import *


def maximumPeople(p, x, y, r):
    # Return the maximum number of people that will be in a sunny town after removing exactly one cloud.
		# p = [populations in each town]
		# x = [location of each town]
		# y = [location of clouds]
		# r = [range of clouds]
		bin_tree = []
		max_end = 10**9 + 1
		total_pop = 0
		dark_pop = 0
		single_cover_pop = {}
		for ix in range(len(x)):
			insort(bin_tree, (x[ix], p[ix]))
			total_pop += p[ix]
		for iy in range(len(y)):
			insort(bin_tree, (max(y[iy] - r[iy], 0), -iy))
			insort(bin_tree, (min(y[iy] + r[iy], 10**9), max_end + iy))

		clouds = set()
		num_clouds = 0
		max_single_cover = 0
		for ic in range(len(bin_tree)):
			pop = bin_tree[ic][1]
			if pop <= 0:
				clouds.add(-bin_tree[ic][1])
				num_clouds += 1
				continue
			if not num_clouds:
				continue
			if pop > 10**9:
				cloud = pop - max_end
				clouds.remove(cloud)
				if single_cover_pop.has_key(cloud):
					max_single_cover = max(max_single_cover, single_cover_pop[cloud])
				num_clouds -= 1
				continue
			if num_clouds == 1:
				cloud = clouds.pop()
				clouds.add(cloud)
				if single_cover_pop.has_key(cloud):
					single_cover_pop[cloud] += pop
				else:
					single_cover_pop[cloud] = pop
			dark_pop += pop
		return total_pop - dark_pop + max_single_cover
			
			
				


if __name__ == "__main__":
    n = int(raw_input().strip())
    p = map(long, raw_input().strip().split(' '))
    x = map(long, raw_input().strip().split(' '))
    m = int(raw_input().strip())
    y = map(long, raw_input().strip().split(' '))
    r = map(long, raw_input().strip().split(' '))
    result = maximumPeople(p, x, y, r)
    print result
