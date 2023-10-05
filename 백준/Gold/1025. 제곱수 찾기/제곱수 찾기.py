from math import sqrt
N, M = map(int ,input().split())
arr = [list(input()) for _ in range(N)]
answer = -1
# print(arr)

## 제곱수 판별 함수
# def square_number(data):
#     if int(data) == (int(data )**0.5) ** 2:
#         return 1
#     else:
#         return 0

## 등차수열 맞게 행, 열 선택하는 완전탐색?

# 1. 행의 공차가 0일때, 열의 공차는 0부터 M-1까지
# 2. 행의 공차가 1, ..열의 공차는
# 3. 행의 공차 range 0 ~ N-1까지/음수가 있으니까 -N+1 ~ N-1



for i in range(N): # 행 시작 시점
    for j in range(M): # 열 시작 지점
        for d1 in range(-N ,N): # 행의 등차
            for d2 in range(-M ,M): # 열의 등차
                nums = '' # 숫자 넣을 빈 문자열 생성
                x ,y = i, j
                if d1 == 0 and d2 == 0: # 행,열 등차 모두 일 때
                    continue
                # ni = i + d1
                # nj = j + d2
                while 0 <= x < N and 0 <= y < M:
                    nums += str(arr[x][y])
                    if int(sqrt(int(nums))) ** 2 == int(nums): # 제곱수라면
                        answer = max(answer,int(nums))
                    x += d1
                    y += d2

print(answer)