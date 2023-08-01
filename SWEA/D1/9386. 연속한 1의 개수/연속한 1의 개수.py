T = int(input())
for tc in range(1, T+1):
    N = int(input())
    arr = list(map(int, input()))

    ans = 0 # 답
    cur = 0 # 현재 연속된 1의 갯수
    for i in range(N):
        if arr[i]: # 1이면 cur 1증가
            cur += 1
        else: # 0이면 cur을 0으로 초기화
            cur = 0
        if cur > ans:
            ans = cur

    print(f'#{tc} {ans}')
