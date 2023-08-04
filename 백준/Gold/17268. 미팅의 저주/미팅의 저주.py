import sys
import math
import copy
import heapq

#sys.stdin = open("input.txt") #제출하기전에 꼭 주석 달것!
input = sys.stdin.readline

MOD = 987654321
N = int(input())
dp = [0 for _ in range(N+1)]

dp[0] = 1

for i in range(2, N+1, 2):
    for k in range(0, i-1, 2):
        dp[i] += dp[k]*dp[i-k-2]
        dp[i] %= MOD

print(dp[N])