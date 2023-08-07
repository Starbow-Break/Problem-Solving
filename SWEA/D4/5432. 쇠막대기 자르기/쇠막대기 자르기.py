T = int(input())
for tc in range(1, T+1):
    s = input().strip()
    cnt = 0
    ans = 0
    flag = False
    for c in s:
        if c == '(':
            cnt += 1
            flag = True
        else:
            cnt -= 1
            if flag:
                ans += cnt
            else:
                ans += 1
            flag = False

    print(f'#{tc} {ans}')