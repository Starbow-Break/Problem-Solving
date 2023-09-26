import sys
import heapq
import math
#sys.stdin = open('input.txt')
input = sys.stdin.readline

INF = int(1e9)


# 그래프의 정점
class Vertex:
    def __init__(self, pos, is_cannon):
        self.pos = pos  # 위치
        self.is_cannon = is_cannon  # 대포 여부


def calc_distance(v, w):
    return math.sqrt((v[0]-w[0])**2+(v[1]-w[1])**2)


def calc_length(vertices, i, j):
    if vertices[i].is_cannon:
        d = calc_distance(vertices[i].pos, vertices[j].pos)
        if d < 50:
            ret = min(d/5, 2+(50-d)/5)
            return ret
        else:
            ret = min(d/5, 2+(d-50)/5)
            return ret
    else:
        return calc_distance(vertices[i].pos, vertices[j].pos)/5


def dijkstra(vertices, start, finish):
    # 최단거리가 담기는 리스트
    dist = [INF for _ in range(len(vertices))]
    heap = []   # 힙
    heapq.heappush(heap, (0, start))
    dist[start] = 0

    while heap:
        t = heapq.heappop(heap)
        cur = t[1]  # 현재 정점
        d = t[0]    # 현재 정점에서의 최단 거리

        if d > dist[cur]:
            continue

        if cur == finish:
            return dist[finish]

        for nxt in range(len(vertices)):
            if cur != nxt:
                length = calc_length(vertices, cur, nxt)
                if d+length < dist[nxt]:
                    dist[nxt] = d+length
                    heapq.heappush(heap, (dist[nxt], nxt))


vertices = []   # 정점들

# 출발점
x, y = map(float, input().rstrip().split())
vertices.append(Vertex((x, y), False))
# 도착점
x, y = map(float, input().rstrip().split())
vertices.append(Vertex((x, y), False))

# 대포들
N = int(input())
for _ in range(N):
    x, y = map(float, input().rstrip().split())
    vertices.append(Vertex((x, y), True))

# 다익스트라로 최단시간 계산
print(dijkstra(vertices, 0, 1))