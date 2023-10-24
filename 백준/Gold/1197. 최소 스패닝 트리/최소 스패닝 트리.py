import sys
# sys.stdin = open('input.txt')
input =sys.stdin.readline
sys.setrecursionlimit(10**9)

def union(x,y):
    # 부모 먼저 찾고
    # 그 다음에 합치기
    px = find(x)
    py = find(y)

    if px == py:
        return
    elif px < py: # 작은 쪽 기준으로 합치기
        parent[py] = px
        return
    else:
        parent[px] = py
        return
#
def find(x):
    if x == parent[x]:
        return x
    else:
        parent[x] = find(parent[x]) # 재귀 통해 부모 찾고 갱신하기
        return parent[x]

# V: 정점의 개수, E: 간선의 개수
V, E = map(int, input().split())
parent = [i for i in range(V+1)]
# arr = [[0] * (V+1) for _ in range(V+1)]
arr = []

for i in range(1, E+1):
    A, B, C = map(int, input().split())
    arr.append([ A, B, C])
arr.sort(key=lambda x:x[2]) # C를 기준으로 오름차순 정렬
# print(arr)

cost = 0
for a,b,c in arr:
    if find(a) != find(b):
        union(a,b)
        cost += c
    # pa = find(a)
    # pb = find(b)
    # if pa != pb:# 부모가 같지 않으면,
    #     if pa < pb:
    #
    #     else:
    #         parent[A] = pB
    #     cost += c
print(cost)