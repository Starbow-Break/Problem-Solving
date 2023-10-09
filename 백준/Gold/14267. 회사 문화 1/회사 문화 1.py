import sys
# sys.stdin = open('input.txt')
input = sys.stdin.readline

N, M = map(int, input().split())
dp = [0 for _ in range(N+1)]
parent = [0]
parent.extend(list(map(int, input().split())))

edges = [[] for _ in range(N+1)]

for _ in range(M):
    i, w = map(int, input().split())
    dp[i] += w

for i in range(1, N+1):
    if parent[i] != -1:
        dp[i] += dp[parent[i]]
    print(dp[i], end=' ')