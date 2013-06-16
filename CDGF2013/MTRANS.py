import sys
s=sys.stdin.readline
t=int(s())
for i in range(t):
    c=int(s().split()[1])
    m=eval(s())
    print[tuple([co[i]for co in m])for i in range(c)]
