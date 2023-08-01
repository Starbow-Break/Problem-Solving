import sys
import math
import copy
import heapq

#sys.stdin = open("input.txt") #제출하기전에 꼭 주석 달것!
input = sys.stdin.readline

INF = 1000000000
N, M = map(int, input().split())
num_two = 0
field = []
target = 0
virus = []
visited = [[False for i in range(N)] for j in range(N)]

def bfs(status):
    for i in range(N):
        for j in range(N):
            visited[i][j] = False

    cnt = 0
    queue = []
    for i in range(0, num_two):
        if status & 1<<i:
            queue.append((virus[i], 0))
            visited[virus[i][0]][virus[i][1]] = True
    
    while not len(queue) == 0:
        cur = queue[0]
        queue.remove(cur)

        r = cur[0][0]
        c = cur[0][1]
        t = cur[1]

        cnt += 1

        if cnt == target:
            return t

        if r-1 >= 0 and not visited[r-1][c] and field[r-1][c] != 1:
            queue.append(((r-1, c), t+1))
            visited[r-1][c] = True
        if r+1 < N and not visited[r+1][c] and field[r+1][c] != 1:
            queue.append(((r+1, c), t+1))
            visited[r+1][c] = True
        if c-1 >= 0 and not visited[r][c-1] and field[r][c-1] != 1:
            queue.append(((r, c-1), t+1))
            visited[r][c-1] = True
        if c+1 < N and not visited[r][c+1] and field[r][c+1] != 1:
            queue.append(((r, c+1), t+1))
            visited[r][c+1] = True

    return INF

for i in range(N):
    field.append(list(map(int, input().split())))

for i in range(N):
    for j in range(N):
        target += (field[i][j] != 1)
        if field[i][j] == 2:
            virus.append((i, j))
            num_two += 1

ans = INF
for s in range(0, 2**num_two):
    cnt = 0
    for i in range(0, num_two):
        if s & 1<<i:
            cnt += 1
    if cnt == M:
        ans = min(ans, bfs(s))

if ans == INF:
    print(-1)
else:
    print(ans)