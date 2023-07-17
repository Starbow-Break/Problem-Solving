N = int(input())
dp = [0 for i in range(0, N+1)]
MOD = 123456789

#소수 구하기
isPrime = [True for i in range(0, N+1)]
isPrime[0] = False
isPrime[1] = False
for i in range(2, N+1):
    if isPrime[i]:
        for j in range(i*2, N+1, i):
            isPrime[j] = False

dp[0] = 1
for p in range(2, N+1):
    if isPrime[p]:
        for i in range(p, N+1):
            dp[i] += dp[i-p]
            dp[i] %= MOD
            
print(dp[N])