import sys
import math
import copy
import heapq

INF = 1 << 60

#sys.stdin = open("input.txt") #제출하기전에 꼭 주석 달것!
input = sys.stdin.readline

N, K = map(int, input().split())
dp = [[INF for _ in range(N)] for _ in range(1<<N)]
T = []
for i in range(N):
    T.append(list(map(int, input().split())))

for k in range(N):
    for i in range(N):
        for j in range(N):
            T[i][j] = min(T[i][j], T[i][k]+T[k][j])

dp[1<<K][K] = 0

for status in range(1, 1<<N):
    for i in range(N):
        for j in range(N):
            if status & 1<<j == 0:
                dp[status|1<<j][j] = min(dp[status|1<<j][j], dp[status][i]+T[i][j])

print(min(dp[(1<<N)-1]))