def dfs(c):
    global count # c: 현재 정점
    visited[c] = 1 # 방문처리
    count += 1    
    for i in arr[c]: # 연결돼있고
        if visited[i] == 0: # 방문하지 않았다면
            dfs(i)

N = int(input()) # 컴퓨터 수
n = int(input())

arr = [[] for _ in range(N+1)] #N번 인덱스까지 쓸라고 # 인접행렬
visited = [0] * (N+1) 

for _ in range(n):
    a, b = map(int,input().split())
    arr[a].append(b)
    arr[b].append(a)

# print(arr)
count = 0

dfs(1)
print(count-1)