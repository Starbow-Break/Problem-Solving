import sys
import math
import heapq
from collections import deque

#sys.stdin = open('input.txt')
input = sys.stdin.readline

visited = [-1 for _ in range(10**6+1)]
previous = [-1 for _ in range(10**6+1)]


def bfs(s, e):
    queue = deque()
    queue.append(s)
    visited[s] = 0

    while queue:
        cur = queue.popleft()
        if cur == e:
            return
        if not cur%3 and visited[cur//3] == -1:
            queue.append(cur//3)
            visited[cur//3] = visited[cur]+1
            previous[cur//3] = cur
        if not cur%2 and visited[cur//2] == -1:
            queue.append(cur//2)
            visited[cur//2] = visited[cur]+1
            previous[cur//2] = cur
        if visited[cur-1] == -1:
            queue.append(cur-1)
            visited[cur-1] = visited[cur]+1
            previous[cur-1] = cur


N = int(input())

bfs(N, 1)

route = []
i = 1
while i != -1:
    route.append(i)
    i = previous[i]

print(len(route)-1)
route.reverse()
print(*route)