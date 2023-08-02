SIZE = 100

for t in range(1, 11):
    tc = int(input())
    arr = [] # 배열 (원래는 2차원이나 1차원으로 필 예정)
    for _ in range(SIZE):
        arr.extend(list(map(int, input().split())))

    ans = 0
    # 각 행의 합
    for i in range(0, SIZE*SIZE, SIZE):
        cur = 0
        for j in range(i, i+SIZE):
            cur += arr[j]
        if ans < cur:
            ans = cur

    # 각 열의 합
    for i in range(SIZE):
        cur = 0
        for j in range(i, SIZE*SIZE, SIZE):
            cur += arr[j]
        if ans < cur:
            ans = cur

    # 각 대각선의 합
    # 좌상-우하
    cur = 0
    for i in range(0, SIZE*SIZE, SIZE+1):
        cur += arr[i]
    if ans < cur:
        ans = cur
    # 우상-좌하
    cur = 0
    for i in range(SIZE-1, SIZE*(SIZE-1)+1, SIZE-1):
        cur += arr[i]
    if ans < cur:
        ans = cur

    print(f'#{tc} {ans}')