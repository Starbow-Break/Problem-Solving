import sys
import math
import copy
import heapq

#sys.stdin = open("input.txt") #제출하기전에 꼭 주석 달것!
input = sys.stdin.readline

N, M = map(int, input().split())
parent = [i for i in range(N+1)]
ans = 0

def find_root(v):
    if v == parent[v]:
        return v
    parent[v] = find_root(parent[v])
    return parent[v]


def merge(a, b):
    ra = find_root(a)
    rb = find_root(b)
    if ra > rb:
        ra, rb = rb, ra
    parent[rb] = ra


edges = []
for _ in range(M):
    a, b, c = map(int, input().split())
    edges.append((c, a, b))
    ans += c

edges.sort()

cnt = 0
idx = 0
while cnt < N-1 and idx < len(edges):
    a = edges[idx][1]
    b = edges[idx][2]
    if find_root(a) != find_root(b):
        ans -= edges[idx][0]
        merge(a, b)
        cnt += 1
    idx += 1

if cnt < N-1:
    ans = -1
print(ans)