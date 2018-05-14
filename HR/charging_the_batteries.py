import sys
import bisect

def get_index(n, x, y):
    if x == 0:
        return y
    if y == n:
        return n + x
    if x == n:
        return 3 * n - y
    if y == 0:
        return 4 * n - x
    return -1

if __name__ == "__main__":
    # n: square side len, m: num plugs, k: num controllers
    n, m, k = raw_input().strip().split(' ')
    n, m, k = [int(n), int(m), int(k)]
    plugs = []
    intervals = []
    
    for a0 in xrange(m):
        x, y = raw_input().strip().split(' ')
        x, y = [int(x), int(y)]
        bisect.insort(plugs, get_index(n, x, y))

    for i in range(m):
        j = (i + 1) % m
        if j == 0:
            interval = plugs[j] + 4 * n - plugs[i]
        else:
            interval = plugs[j] - plugs[i]
        intervals.append(interval)

    i = 0
    j = i + k - 1
    min_dist = distance = sum(intervals[i:j])
    while i < m:
        distance = distance - intervals[i] + intervals[j]
        min_dist = min(min_dist, distance)
        i += 1
        j = (j + 1) % m
    print min_dist
