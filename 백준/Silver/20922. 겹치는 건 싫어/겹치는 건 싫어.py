import sys
input = sys.stdin.readline

N, K = map(int, input().split())
A = []
A.extend(list(map(int, input().split())))

i = 0
j = 0
cnt = [0 for i in range(0, 100001)]
cnt[A[0]] = 1
ans = 0
while j < N-1:
    j += 1
    cnt[A[j]] += 1
    if cnt[A[j]] > K:
        while cnt[A[j]] > K:
            cnt[A[i]] -= 1
            i += 1
    
    ans = max(ans, j-i+1)
    
print(ans)