import sys
import math
import copy
import heapq
from collections import deque

#sys.stdin = open("input.txt") #제출하기전에 꼭 주석 달것!
input = sys.stdin.readline

N = int(input())
pts = []
for _ in range(N):
    x, y = map(int, input().split())
    pts.append((x, y))

ans = 0
for i in range(N-2):
    for j in range(i+1, N-1):
        for k in range(j+1, N):
            a = (pts[j][0]-pts[i][0])**2+(pts[j][1]-pts[i][1])**2
            b = (pts[j][0]-pts[k][0])**2+(pts[j][1]-pts[k][1])**2
            c = (pts[k][0]-pts[i][0])**2+(pts[k][1]-pts[i][1])**2
            ans += (a+b == c or a+c == b or b+c == a)

print(ans)