#!/bin/python

import sys

def solve(grades):
    sgrades = sorted(grades)
    h = min(4, len(sgrades) - 1)
    for i in range(len(sgrades)):
        if (sgrades[i][0] < 38) and (sgrades[h][0] < sgrades[i][0] + 3):
            grades[sgrades[i][1]][0] = sgrades[h][0]
        if h < len(sgrades) - 1:
            h += 1
    return [i[0] for i in grades]


n = int(raw_input().strip())
grades = []
grades_i = 0
for grades_i in xrange(n):
    grades_t = int(raw_input().strip())
    grades.append((grades_t, grades_i))
result = solve(grades)
print "\n".join(map(str, result))
