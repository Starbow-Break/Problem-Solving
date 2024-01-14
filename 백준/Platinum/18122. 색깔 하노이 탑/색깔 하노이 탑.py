N = int(input())
MOD = 1000000007

if(N == 1):
    print(3)
else:
    a = 2*(pow(2, N-1, MOD)+MOD-1)%MOD
    print((4*a+3)%MOD)