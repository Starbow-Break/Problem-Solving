import sys
import math
import heapq
from collections import deque

#sys.stdin = open('input.txt')
input = sys.stdin.readline

N = int(input())
num = list(map(int, input().split()))

dq = deque()

for i in range(1, N+1):
    dq.append(i)

while True:
    cur = dq.popleft()
    print(cur, end=' ')

    if not dq:
        break

    if num[cur-1] > 0:
        num[cur-1] -= 1
        while num[cur-1] > 0:
            dq.append(dq.popleft())
            num[cur-1] -= 1
    else:
        while num[cur-1] < 0:
            dq.appendleft(dq.pop())
            num[cur-1] += 1