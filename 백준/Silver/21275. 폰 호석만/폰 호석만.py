import sys
import math
input = sys.stdin.readline

class Element():
    def __init__(self, x, a, b):
        self.x = x
        self.a = a
        self.b = b

def calc(s, b):
    ret = 0
    for c in s:
        v = 0
        if '0' <= c <= '9':
            v = ord(c)-ord('0')
        else:
            v = ord(c)-ord('a')+10

        if v >= b:
            return -1
        ret *= b
        ret += v
    return ret

s, t = input().split()
ans = []
for a in range(2, 36):
    for b in range(2, 36):
        if a == b:
            continue
        xa = calc(s, a)
        xb = calc(t, b)
        if(xa != -1 and xa == xb):
            ans.append(Element(xa, a, b))

if len(ans) >= 2:
    print("Multiple")
elif len(ans) == 0:
    print("Impossible")
else:
    print(f'{ans[0].x} {ans[0].a} {ans[0].b}')