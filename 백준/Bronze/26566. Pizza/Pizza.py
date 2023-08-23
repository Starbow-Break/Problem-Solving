import math

T = int(input())
for _ in range(T):
    a1, p1 = map(int, input().split())
    r1, p2 = map(int, input().split())

    whole = p1*math.pi*r1*r1
    slice = a1*p2
    if whole > slice:
        print('Whole pizza')
    else:
        print('Slice of pizza')