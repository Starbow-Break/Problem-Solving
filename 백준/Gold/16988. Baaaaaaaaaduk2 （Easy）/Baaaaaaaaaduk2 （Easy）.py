# input 파일을 가져옴
import sys
import copy
#sys.stdin = open('input.txt')
input = sys.stdin.readline

N, M = map(int, input().split())
board = []
visited = [False] * (N * M)


def bfs(start):
    queue = [start]
    visited[start] = True
    flag = True
    ret = 0
    while len(queue) > 0:
        cur = queue[0]
        queue.remove(cur)
        ret += 1
        if cur//M-1 >= 0 and not visited[cur-M]:
            if board[cur-M] == 0:
                flag = False
            elif board[cur-M] == 2:
                queue.append(cur-M)
                visited[cur-M] = True
        if cur//M+1 < N and not visited[cur+M]:
            if board[cur+M] == 0:
                flag = False
            elif board[cur+M] == 2:
                queue.append(cur+M)
                visited[cur+M] = True
        if cur%M-1 >= 0 and not visited[cur-1]:
            if board[cur-1] == 0:
                flag = False
            elif board[cur-1] == 2:
                queue.append(cur-1)
                visited[cur-1] = True
        if cur%M+1 < M and not visited[cur+1]:
            if board[cur+1] == 0:
                flag = False
            elif board[cur+1] == 2:
                queue.append(cur+1)
                visited[cur+1] = True

    if flag:
        return ret
    else:
        return 0


def solve(a, b):
    ret = 0
    for k in range(N*M):
        visited[k] = False

    board[a] = 1
    board[b] = 1

    for k in range(N*M):
        if board[k] == 2 and not visited[k]:
            ret += bfs(k)

    board[a] = 0
    board[b] = 0
    return ret


for i in range(N):
    board.extend(list(map(int, input().split())))

ans = 0
for i in range(N*M):
    for j in range(N*M):
        if board[i] == 0 and board[j] == 0:
            ans = max(ans, solve(i, j))
print(ans)