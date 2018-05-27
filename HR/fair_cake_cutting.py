#!/bin/python

import sys

def howManyToInvite(A, B, a):
    # Return the number of people Leha should invite to his party
		return a * B / A

if __name__ == "__main__":
    A, B, a = raw_input().strip().split(' ')
    A, B, a = [long(A), long(B), long(a)]
    b = howManyToInvite(A, B, a)
    print b
