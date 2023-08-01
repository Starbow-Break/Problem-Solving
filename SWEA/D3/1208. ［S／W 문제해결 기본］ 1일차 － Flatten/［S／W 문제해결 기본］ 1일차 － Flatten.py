for tc in range(1, 11):
    M = int(input())
    arr = list(map(int, input().split()))
    cnt = [0 for i in range(101)] # cnt[i] == 높이가 i인 상자의 수

    # cnt 초기화
    for h in arr:
        cnt[h] += 1
    
    # i는 최소 높이, j는 최대 높이를 가리킴
    i = 0
    j = 100
    while M > 0:
        # i, j 조정
        while cnt[i] == 0:
            i += 1
        while cnt[j] == 0:
            j -= 1

        # 제일 높은 곳에서 상자 하나 제거
        cnt[j] -= 1
        cnt[j-1] += 1
        # 제일 낮은 곳에 상자 추가
        cnt[i] -= 1
        cnt[i+1] += 1
        # 횟수 하나 감소
        M -= 1

    # i, j 조정 후 답 계산
    while cnt[i] == 0:
        i += 1
    while cnt[j] == 0:
        j -= 1
    print(f'#{tc} {j-i}')
