import sys
import math
import heapq
from collections import deque

#sys.stdin = open('input.txt')
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    N = int(input())
    key1 = list(input().rstrip().split())
    key2 = list(input().rstrip().split())
    arr = list(input().rstrip().split())

    ans = []

    for i in range(N):
        ans.append(arr[key2.index(key1[i])])

    print(*ans)