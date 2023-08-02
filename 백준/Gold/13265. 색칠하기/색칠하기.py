# input 파일을 가져옴
import sys
#sys.stdin = open('input.txt')
input = sys.stdin.readline

color = [0] * 1001
def bfs(graph, start):
    queue = [start]
    color[start] = 1
    while len(queue) > 0:
        cur = queue[0]
        queue.remove(cur)
        for next in graph[cur]:
            if color[next] != 0:
                if color[cur] == color[next]:
                    return False
            else:
                color[next] = 3-color[cur]
                queue.append(next)

    return True


def solve(graph):
    sz = len(graph)-1
    for i in range(sz+1):
        color[i] = 0
    for i in range(1, sz+1):
        if color[i] == 0:
            if not bfs(graph, i):
                return False
    return True


T = int(input())
for tc in range(T):
    n, m = map(int, input().split())
    graph = [[] for i in range(n+1)]
    for _ in range(m):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)

    if solve(graph):
        print('possible')
    else:
        print('impossible')