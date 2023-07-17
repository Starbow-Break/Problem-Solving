import sys
input = sys.stdin.readline

N = int(input())
isIn = [False for i in range(0, 200001)]
ans = 0
for i in range(0, N):
    a, b = map(int, input().split())
    if b == 0:
        if not isIn[a]:
            ans += 1
        isIn[a] = False
    else:
        if isIn[a]: 
            ans += 1
        isIn[a] = True
    
for i in range(1, 200001):
    ans += isIn[i]

print(ans)