import sys
import math
from collections import deque

#sys.stdin = open('input.txt')
input = sys.stdin.readline

N = int(input())
dep = [0 for i in range(0, N + 1)]
edges = [[] for i in range(0, N + 1)]
visited = [False for i in range(0, N + 1)]
turn = 0


def bfs(start):
    global turn
    queue = deque()
    queue.append(start)
    visited[start] = True

    while len(queue) > 0:
        cur = queue.popleft()
        is_leaf = True

        for next in edges[cur]:
            if not visited[next]:
                is_leaf = False
                dep[next] = dep[cur] + 1
                queue.append(next)
                visited[next] = True
        if is_leaf:
            turn += dep[cur]


for i in range(N - 1):
    a, b = map(int, input().split())
    edges[a].append(b)
    edges[b].append(a)

bfs(1)

if turn % 2:
    print('Yes')
else:
    print('No')