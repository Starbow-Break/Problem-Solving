import sys
#sys.stdin = open('input.txt')
input = sys.stdin.readline

N, M = map(int, input().split())
# 받은 칭찬의 총합
dp = [0 for _ in range(N+1)]
# 직속 상사
parent = [0]
parent.extend(list(map(int, input().split())))

# 직접 받은 칭찬 반영
for _ in range(M):
    i, w = map(int, input().split())
    dp[i] += w

# dp[i] = dp[parent[i]] + (직접 받은 칭찬)
for i in range(1, N+1):
    if parent[i] != -1:
        dp[i] += dp[parent[i]]
    print(dp[i], end=' ')