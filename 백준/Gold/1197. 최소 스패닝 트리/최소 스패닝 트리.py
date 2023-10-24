import sys

def find(x):
    global parent

    if parent[x] == x:
        return x
    else:
        return find(parent[x])

def union(x, y):
    pX, pY = find(x), find(y)
    if pX > pY:
        parent[pX] = pY
    else:
        parent[pY] = pX



### MAIN
V, E = map(int, sys.stdin.readline().strip().split())
arr, parent = [], [i for i in range(V)]

for _ in range(E):
    v1, v2, dist = map(int, sys.stdin.readline().strip().split())
    arr.append([dist, v1-1, v2-1])

arr.sort() # 모든 간선을 오름차순으로 정렬

result = 0
for a in arr:
    if find(a[1]) == find(a[2]): # 사이클이 발생하는 경우
        continue

    union(a[1], a[2])
    result += a[0]

print(result)