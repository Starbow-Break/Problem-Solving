import sys
import math
import copy
import heapq

#sys.stdin = open("input.txt") #제출하기전에 꼭 주석 달것!
input = sys.stdin.readline

dr = [-1, -1, 0, 1, 1, 1, 0, -1]
dc = [0, 1, 1, 1, 0, -1, -1, -1]

N, M, K = map(int, input().split())
field = [[[0, 0, []] for i in range(N)] for j in range(N)]
temp = [[[0, 0, []] for i in range(N)] for j in range(N)]

#파이어볼이 움직임
def move():
    global field
    global temp
    for r in range(N):
        for c in range(N):
            if len(field[r][c][2]) >= 2:
                m = field[r][c][0]
                s = field[r][c][1]
                cnt = [0, 0]
                sz = len(field[r][c][2])
                for d in field[r][c][2]:
                    cnt[d%2] += 1
                if cnt[0] and cnt[1]:
                    for d in [1, 3, 5, 7]:
                        if m//5 > 0:
                            temp[(r+(N+dr[d])*(s//sz))%N][(c+(N+dc[d])*(s//sz))%N][0] += m//5
                            temp[(r+(N+dr[d])*(s//sz))%N][(c+(N+dc[d])*(s//sz))%N][1] += s//sz
                            temp[(r+(N+dr[d])*(s//sz))%N][(c+(N+dc[d])*(s//sz))%N][2].append(d)
                else:
                    for d in [0, 2, 4, 6]:
                        if m//5 > 0:
                            temp[(r+(N+dr[d])*(s//sz))%N][(c+(N+dc[d])*(s//sz))%N][0] += m//5
                            temp[(r+(N+dr[d])*(s//sz))%N][(c+(N+dc[d])*(s//sz))%N][1] += s//sz
                            temp[(r+(N+dr[d])*(s//sz))%N][(c+(N+dc[d])*(s//sz))%N][2].append(d)
                
            elif len(field[r][c][2]) == 1:
                m = field[r][c][0]
                s = field[r][c][1]
                d = field[r][c][2][0]
                temp[(r+(N+dr[d])*s)%N][(c+(N+dc[d])*s)%N][0] += m
                temp[(r+(N+dr[d])*s)%N][(c+(N+dc[d])*s)%N][1] += s
                temp[(r+(N+dr[d])*s)%N][(c+(N+dc[d])*s)%N][2].append(d)
                
    field = copy.deepcopy(temp)
    
    for r in range(N):
        for c in range(N):
            temp[r][c] = [0, 0, []]
    

for i in range(M):
    r, c, m, s, d = map(int, input().split())
    field[r-1][c-1][0] += m
    field[r-1][c-1][1] += s
    field[r-1][c-1][2].append(d)

while K > 0:
    K -= 1
    move()

ans = 0
for i in range(N):
    for j in range(N):
        if len(field[i][j][2]) >= 2:
            ans += field[i][j][0]//5*4
        else:
            ans += field[i][j][0]

print(ans)