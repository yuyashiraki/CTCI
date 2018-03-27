#!/bin/python

import sys

def solve(grades):
    rt = []
    for i in grades:
        if i >= 38 and i % 5 > 2:
            i = (i / 5 + 1) * 5
        rt.append(i)
    return rt


n = int(raw_input().strip())
grades = []
grades_i = 0
for grades_i in xrange(n):
    grades_t = int(raw_input().strip())
    grades.append(grades_t)
result = solve(grades)
print "\n".join(map(str, result))
