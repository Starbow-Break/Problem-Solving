import sys
input = sys.stdin.readline

N = int(input())
arr = list(input().rstrip())

cnt = 0
cnt_G = 0
for c in arr:
    if c == '(':
        cnt += 1
    elif c == ')':
        cnt -= 1
    else:
        cnt_G += 1

open_bracket = (cnt_G-cnt)//2
close_bracket = (cnt_G+cnt)//2

for i in range(N):
    if arr[i] == 'G':
        if open_bracket:
            arr[i] = '('
            open_bracket -= 1
        else:
            arr[i] = ')'
            close_bracket -= 1

print(''.join(arr))