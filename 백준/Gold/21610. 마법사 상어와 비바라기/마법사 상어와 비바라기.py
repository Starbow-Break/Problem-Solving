import sys
import math
import copy
import heapq

#sys.stdin = open("input.txt") #제출하기전에 꼭 주석 달것!
input = sys.stdin.readline

dr = [0, -1, -1, -1, 0, 1, 1, 1]
dc = [-1, -1, 0, 1, 1, 1, 0, -1]

N, M = map(int, input().split())
#물
water = [[] for i in range(N)]
water_delta = [[0 for i in range(N)] for j in range(N)]
#이동 전 구름
cloud_before = [[False for i in range(N)] for j in range(N)]
#이동 후 구름
cloud_after = [[False for i in range(N)] for j in range(N)]

# 구름 이동
def cloud_move(d, s):
    for i in range(N):
        for j in range(N):
            cloud_after[i][j] = False

    for i in range(N):
        for j in range(N):
            if cloud_before[i][j]:
                cloud_after[(i+(N+dr[d-1])*s)%N][(j+(N+dc[d-1])*s)%N] = True

# 비 내림
def rain():
    #구름이 있는 위치에 물 1씩 증가
    for i in range(N):
        for j in range(N):
            water[i][j] += cloud_after[i][j]

# 물 복사 버그
def water_copy_bug():
    for r in range(N):
        for c in range(N):
            water_delta[r][c] = 0

    for r in range(N):
        for c in range(N):
            if not cloud_after[r][c]:
                continue
            if r-1 >= 0 and c-1 >= 0 and water[r-1][c-1]:
                water_delta[r][c] += 1
            if r-1 >= 0 and c+1 < N and water[r-1][c+1]:
                water_delta[r][c] += 1
            if r+1 < N and c-1 >= 0 and water[r+1][c-1]:
                water_delta[r][c] += 1
            if r+1 < N and c+1 < N and water[r+1][c+1]:
                water_delta[r][c] += 1
    for r in range(N):
        for c in range(N):
            water[r][c] += water_delta[r][c]
        

# 구름 생성
def create_cloud():
    for i in range(N):
        for j in range(N):
            cloud_before[i][j] = False
            if water[i][j] >= 2 and cloud_after[i][j] == False:
                cloud_before[i][j] = True
                water[i][j] -= 2

# 전체 물의 양 계산
def total_water():
    ret = 0
    for i in range(N):
        ret += sum(water[i])
    return ret

#초기 물의 양
for i in range(N):
    water[i] = list(map(int, input().split()))

cloud_before[N-1][0] = True
cloud_before[N-1][1] = True
cloud_before[N-2][0] = True
cloud_before[N-2][1] = True

for i in range(M):
    d, s = map(int, input().split())
    cloud_move(d, s) # 구름 이동
    rain() # 비 내림
    water_copy_bug() # 물 복사 버그
    create_cloud() # 새 구름 생성

print(total_water()) # 전체 물 계산