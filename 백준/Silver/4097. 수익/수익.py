import sys
input = sys.stdin.readline

while True:
    N = int(input())
    if N == 0:
        break
    
    _sum = [0 for i in range(0, N+1)]
    _min = [0 for i in range(0, N+1)]
    for i in range(1, N+1):
        _sum[i] = int(input())
        _sum[i] += _sum[i-1]
    for i in range(1, N+1):
        _min[i] = min(_min[i-1], _sum[i])
    
    ans = _sum[1]
    for i in range(2, N+1):
        ans = max(ans, _sum[i]-_min[i-1])
    print(ans)