import sys
import math
import copy
import heapq
from collections import deque

#sys.stdin = open("input.txt") #제출하기전에 꼭 주석 달것!
input = sys.stdin.readline

dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]

def bfs(arr, sz):
    queue = deque()
    queue.append((0, 0))
    visited = [[False for _ in range(sz)] for _ in range(sz)]
    visited[0][0] = True

    while queue:
        r, c = queue.popleft()

        if arr[r][c] == -1:
            return True

        for k in range(4):
            if 0 <= r+arr[r][c]*dr[k] < sz and 0 <= c+arr[r][c]*dc[k] < sz:
                if not visited[r+arr[r][c]*dr[k]][c+arr[r][c]*dc[k]]:
                    queue.append((r+arr[r][c]*dr[k], c+arr[r][c]*dc[k]))
                    visited[r+arr[r][c]*dr[k]][c+arr[r][c]*dc[k]] = True
    return False

N = int(input())
arr = []
for _ in range(N):
    arr.append(list(map(int, input().split())))

if bfs(arr, N):
    print('HaruHaru')
else:
    print('Hing')