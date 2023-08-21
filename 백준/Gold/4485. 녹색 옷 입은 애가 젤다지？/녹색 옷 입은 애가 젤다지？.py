import sys
import math
import copy
import heapq
from collections import deque

# sys.stdin = open("input.txt") #제출하기전에 꼭 주석 달것!
input = sys.stdin.readline


def bfs(arr, graph, sz):
    dq = deque()
    dq.append((0, 0, 0))

    visited = [[[-1 for _ in range(10)] for _ in range(sz)] for _ in range(sz)]
    visited[0][0][0] = 0

    while dq:
        cur = dq.popleft()

        r, c, k = cur
        for next in graph[r][c][k]:
            nr, nc, nk = next
            if visited[nr][nc][nk] == -1:
                if r == nr and c == nc:
                    dq.append(next)
                    visited[nr][nc][nk] = visited[r][c][k]+1
                else:
                    dq.appendleft(next)
                    visited[nr][nc][nk] = visited[r][c][k]

    return visited[sz-1][sz-1][arr[sz-1][sz-1]]


tc = 0
while True:
    tc += 1
    N = int(input())

    if not N:
        break

    arr = []
    for _ in range(N):
        arr.append(list(map(int, input().split())))

    adj_list = [[[[] for _ in range(10)] for _ in range(N)] for _ in range(N)]
    for r in range(N):
        for c in range(N):
            for k in range(arr[r][c]):
                adj_list[r][c][k].append((r, c, k+1))

    for r in range(N):
        for c in range(N):
            if r > 0:
                adj_list[r-1][c][arr[r-1][c]].append((r, c, 0))
            if c > 0:
                adj_list[r][c-1][arr[r][c-1]].append((r, c, 0))
            if r < N-1:
                adj_list[r+1][c][arr[r+1][c]].append((r, c, 0))
            if c < N-1:
                adj_list[r][c+1][arr[r][c+1]].append((r, c, 0))

    print(f'Problem {tc}: {bfs(arr, adj_list, N)}')