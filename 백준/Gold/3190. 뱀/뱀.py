import sys
import math
import copy
import heapq

#sys.stdin = open("input.txt") #제출하기전에 꼭 주석 달것!
input = sys.stdin.readline

RIGHT = 0
DOWN = 1
LEFT = 2
UP = 3

dr = [0, 1, 0, -1]
dc = [1, 0, -1, 0]

N = int(input()) # 보드의 크기
K = int(input()) # 사과의 개수
apple = [[False for _ in range(N)] for _ in range(N)]
snake = [[False for _ in range(N)] for _ in range(N)]
command = [0]*10001
direction = RIGHT

for _ in range(K):
    r, c = map(int, input().split())
    apple[r-1][c-1] = True
    
L = int(input()) # 방향 전환 횟수
for _ in range(L):
    _x, c = input().split()
    x = int(_x)
    if c == 'L':
        command[x] = -1
    else:
        command[x] = 1
  
snake[0][0] = True     
queue = [None] * 20000 # 맨 앞이 꼬리, 맨 뒤가 머리이다.
front = -1
rear = -1
ans = 0

def qPush(value):
    global rear
    rear += 1
    queue[rear] = value
    
def qPop():
    global front
    ret = queue[front+1]
    queue[front+1] = None
    front += 1
    return ret

qPush((0, 0))
while True:
    ans += 1
    r, c = queue[rear]
    
    # 새로운 머리 위치
    nr = r+dr[direction]
    nc = c+dc[direction]
    
    # 벽에 부딫히면 종료
    if nr < 0 or nr >= N or nc < 0 or nc >= N:
        break
    # 자신의 몸에 부딫히면 종료    
    if snake[nr][nc]:
        break
    
    #머리 이동
    qPush((nr, nc))
    snake[nr][nc] = True
    
    # 꼬리 이동
    if apple[nr][nc]:
        apple[nr][nc] = False
    else:
        tail = qPop()
        snake[tail[0]][tail[1]] = False
    
    
    direction = (direction+4+command[ans])%4
    
print(ans)