#!/usr/bin/python3

import sys

if (len(sys.argv) != 2):
    print("Usage: " + sys.argv[0] + " <Filename>")
    exit(1)
f = open(sys.argv[1], "r")
while num := f.readline():
    for d in range(2, int(int(num)**.5) + 1):
        if (int(num) % d == 0):
            print(f"{int(num)}={int(int(num)/d)}*{d}")
            break
