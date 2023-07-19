import sys
input = sys.stdin.readline

T = int(input())

for tc in range(T):
    s = input().rstrip()
    stack = []
    cnt = [0 for i in range(0, 26)]
    cnt[0] = 1
    for c in s:
        if c == '[':
            cnt[len(stack)] -= 1
            cnt[len(stack)+1] += 2
            stack.append(1)
        else:
            stack.pop(len(stack)-1)
         
    ans = 0
    w = -1
    for i in range(25, -1, -1):
        if w == -1 and cnt[i] != 0:
            w = 1
        if w != -1:
            ans += cnt[i]*w
            w *= 2
            
    print(ans)
   