T = int(input())
for tc in range(1, T+1):
    N = int(input())
    ans = [[0 for _ in range(N)] for _ in range(N)]

    order = 0
    i = 0
    j = N-1
    while i <= j:
        if i == j:
            order += 1
            ans[i][j] = order
            break

        # 오른쪽
        for k in range(i, j):
            order += 1
            ans[i][k] = order
        # 아래
        for k in range(i, j):
            order += 1
            ans[k][j] = order
        # 왼족
        for k in range(j, i, -1):
            order += 1
            ans[j][k] = order
        # 위
        for k in range(j, i, -1):
            order += 1
            ans[k][i] = order
        i += 1
        j -= 1

    print(f'#{tc}')
    for i in range(N):
        for j in range(N):
            print(ans[i][j], end = ' ')
        print()