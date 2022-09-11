#!/usr/bin/python3
import sys

if (len(sys.argv) != 2):
    print("Usage: ")
f = open()

def is_prime(n):
    return n > 1 and all(n%d for d in xrange(2, int(n**.5) + 1))
