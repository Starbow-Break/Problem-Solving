# input 파일을 가져옴
import sys
import copy
#sys.stdin = open('input.txt')
input = sys.stdin.readline

N = int(input()) # 계란의 갯수
S = [] # 내구도
W = [] # 무게

for i in range(N):
    s, w = map(int, input().split())
    S.append(s)
    W.append(w)

ans = 0
for status in range(N**N):
    target = [0] * N
    st = status
    flag = True

    #각 계란의 타겟
    for i in range(N):
        target[i] = st%N
        st //= N
        if target[i] == i:
            flag = False
            break

    # 자기 자신이 타겟인 계란이 있으면 해당 경우는 스킵
    if not flag:
        continue

    s = S[:]
    w = W[:]
    remain = N

    # 계란 깨기 진행
    for i in range(N):
        if s[i] <= 0: # 현재 계란이 깨진 상태면 스킵
            continue
        if s[target[i]] <= 0:
            if remain > 1: # 다른 계란이 남아있으나 계란을 깨지 않으면 규칙 위반
                flag = False
                break
            else: # 깰 수 있는 계란이 없는 상황이라면 그냥 패스
                continue

        # 둘 다 멀쩡하면 충돌
        s[i] -= w[target[i]]
        s[target[i]] -= w[i]

        # 깨진 계란이 있다면 remain을 업데이트
        if s[i] <= 0:
            remain -= 1
        if s[target[i]] <= 0:
            remain -= 1

    # print(target, s, remain, flag)

    if flag:
        ans = max(ans, N-remain)

print(ans)