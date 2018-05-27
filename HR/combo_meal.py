#!/bin/python

import sys

def profit(b, s, c):
    # Return the fixed profit.
		act_b = c - s
		return b - act_b

if __name__ == "__main__":
    t = int(raw_input().strip())
    for a0 in xrange(t):
        b, s, c = raw_input().strip().split(' ')
