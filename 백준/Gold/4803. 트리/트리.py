import sys
input = sys.stdin.readline
# sys.stdin = open('input.txt')
from collections import deque


## 트리, 사이클 없는 그래프
def bfs(start):
    result = True
    q = deque([start])
    # visited[start] = 1
    while q:  # q가 빌 때까지
        v = q.popleft()
        # visited[v] = 1  # !! 밸 때 visited 갱신하기!!
        if visited[v] == 1:
            result = False # 트리 아님
        visited[v] = 1
        for i in range(1, n + 1):
            if arr[v][i] == 1 and visited[i] == 0:  # 연결되어있고 방문하지 않았다면,
                q.append(i)
    return result


case_num = 0
while True:
    cnt = 0  # 트리 개수

    # n: 정점의 개수, m: 간선의 개수
    n, m = map(int,input().split())
    # arr = [[] for _ in range(n+1)]
    arr = [[0] * (n+1) for _ in range(n+1)]
    visited = [0] * (n+1) # n번 노드까지 있으므로
    if n == 0 and m == 0:
        break
    case_num += 1
    for _ in range(m):
        a, b = map(int,input().split())
        # 인접행렬 만들기
        # arr[a].append(b)
        # arr[b].append(a)

        arr[a][b] = 1
        arr[b][a] = 1
    # print(arr)
    # bfs(1,visited,arr)
    # if bfs(1,visited,arr):
    #     cnt += 1
    for j in range(1, n+1):
        if visited[j] == 0:
            if bfs(j): # 트리이면,
                cnt += 1
    # print(cnt)

    if cnt == 1:
        print(f'Case {case_num}: There is one tree.')
    elif cnt == 0:
        print(f'Case {case_num}: No trees.')
    else:
        print(f'Case {case_num}: A forest of {cnt} trees.')