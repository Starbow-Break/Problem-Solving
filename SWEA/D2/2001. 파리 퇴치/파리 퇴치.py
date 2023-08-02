T = int(input())
for tc in range(1, T+1):
    N, M = map(int, input().split())
    arr = [[0 for _ in range(N+1)] for _ in range(N+1)]

    for i in range(1, N+1):
        lst = list(map(int, input().split()))
        for j in range(1, N+1):
            arr[i][j] = lst[j-1]
            arr[i][j] += arr[i][j-1]

    for j in range(1, N+1):
        for i in range(1, N+1):
            arr[i][j] += arr[i-1][j]


    ans = 0
    for i in range(0, N-M+1):
        for j in range(0, N-M+1):
            ans = max(ans, arr[i+M][j+M]-arr[i+M][j]-arr[i][j+M]+arr[i][j])
    print(f'#{tc} {ans}')