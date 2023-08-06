# input 파일을 가져옴
import sys
from collections import deque
#sys.stdin = open('input.txt')
input = sys.stdin.readline
print = sys.stdout.write

N, M = map(int, input().split())
dp = [[-1 for _ in range(M+1)] for _ in range(N+1)]
D = []
for _ in range(N):
    v = int(input())
    D.append(v)

dp[0][0] = 0
for i in range(0, N):
    for m in range(0, M+1):
        if dp[i][m] != -1:
            if m < M:
                dp[i+1][m+1] = max(dp[i+1][m+1], dp[i][m]+D[i])

            if m > 0 and i+m <= N:
                dp[i+m][0] = max(dp[i+m][0], dp[i][m])
            elif m == 0:
                dp[i+1][0] = max(dp[i+1][0], dp[i][0])

print(str(dp[N][0]))