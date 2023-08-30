import sys
import math
import heapq
from collections import deque

#sys.stdin = open('input.txt')
input = sys.stdin.readline

dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]

N = int(input())
height = []
visited = [[False] * N for _ in range(N)]


# BFS로 영역 하나를 순회
def bfs(r, c, h):
    queue = deque()
    queue.append((r, c))
    visited[r][c] = True

    while queue:
        cur = queue.popleft()
        for k in range(4):
            nr = cur[0]+dr[k]
            nc = cur[1]+dc[k]
            if 0 <= nr < N and 0 <= nc < N and not visited[nr][nc] and height[nr][nc] > h:
                queue.append((nr, nc))
                visited[nr][nc] = True


# 안전 영역의 갯수를 센다
def get_num_safe_area(h):
    # visited 초기화
    for r in range(N):
        for c in range(N):
            visited[r][c] = False

    # 안전 영역의 갯수를 센다.
    ret = 0
    for r in range(N):
        for c in range(N):
            if not visited[r][c] and height[r][c] > h:
                bfs(r, c, h)
                ret += 1

    return ret


for _ in range(N):
    height.append(list(map(int, input().split())))

# 최대 안전 영역의 갯수 구하기
ans = 0
for h in range(101):
    ans = max(ans, get_num_safe_area(h))

print(ans)