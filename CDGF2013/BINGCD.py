import sys
s=sys.stdin
s.readline()
for l in s:
    N = int(l)
    r = 2
    while N % 2 == 0:
        r *= 2
        N /= 2
    print r

