T = int(input())
for tc in range(1, T+1):
    N = int(input())
    arr = list(map(int, input().split()))

    min_value = arr[0]
    min_index = 0
    max_value = arr[0]
    max_index = 0

    for i in range(N):
        if min_value > arr[i]:
            min_value = arr[i]
            min_index = i
        if max_value <= arr[i]:
            max_value = arr[i]
            max_index = i

    if max_index >= min_index:
        print(f'#{tc} {max_index-min_index}')
    else:
        print(f'#{tc} {min_index-max_index}')