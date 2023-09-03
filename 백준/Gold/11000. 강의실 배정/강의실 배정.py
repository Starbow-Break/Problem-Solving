import math
import copy
import heapq
import sys
from collections import deque

from collections import deque

#sys.stdin = open('input.txt')
input = sys.stdin.readline
sys.setrecursionlimit(1000000)

N = int(input())
arr = []

for _ in range(N):
    t, s = map(int, input().split())
    arr.append((t, 1))
    arr.append((s, 0))

arr.sort()

cnt = 0
ans = 0
idx = 0
while idx < len(arr):
    t = arr[idx][0]
    while idx < len(arr) and t == arr[idx][0]:
        if arr[idx][1]:
            cnt += 1
        else:
            cnt -= 1
        idx += 1

    ans = max(ans, cnt)

print(ans)