import sys
input = sys.stdin.readline

T = int(input())
fib = [0, 1, 1]
invFib = {}

for i in range(3, 100001):
    fib.append(fib[i-1]+fib[i-2])
    invFib[fib[i]] = i
    
for t in range(0, T):
    n = int(input())
    if n == 1:
        print(2)
    else:
        print(invFib[n])