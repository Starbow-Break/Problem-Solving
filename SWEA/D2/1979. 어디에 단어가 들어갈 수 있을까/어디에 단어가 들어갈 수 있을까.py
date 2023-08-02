T = int(input())
for tc in range(1, T+1):
    N, K = map(int, input().split())
    arr = []
    for _ in range(N):
        arr.append(list(map(int, input().split())))

    ans = 0
    for i in range(N):
        cur = 0
        for j in range(N):
            if arr[i][j] == 1:
                cur += 1
            else:
                if cur == K:
                    ans += 1
                cur = 0
        if cur == K:
            ans += 1

    for j in range(N):
        cur = 0
        for i in range(N):
            if arr[i][j] == 1:
                cur += 1
            else:
                if cur == K:
                    ans += 1
                cur = 0
        if cur == K:
            ans += 1

    print(f'#{tc} {ans}')