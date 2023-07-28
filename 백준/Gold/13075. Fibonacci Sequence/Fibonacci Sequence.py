import sys
import math
import copy
#sys.stdin = open("input.txt") #제출하기전에 꼭 주석 달것!
input = sys.stdin.readline

MOD = int(1e9)

def solve(N):
    if N <= 2:
        return 1
    
    w = [[1, 1], [1, 0]]
    a = [[1, 0], [0, 1]]
    N -= 2
    while N > 0:
        if N%2 == 1:
            temp = [[0, 0], [0, 0]]
            temp[0][0] = (a[0][0]*w[0][0]+a[0][1]*w[1][0])%MOD
            temp[0][1] = (a[0][0]*w[0][1]+a[0][1]*w[1][1])%MOD
            temp[1][0] = (a[1][0]*w[0][0]+a[1][1]*w[1][0])%MOD
            temp[1][1] = (a[1][0]*w[0][1]+a[1][1]*w[1][1])%MOD
            a[0][0] = temp[0][0]
            a[0][1] = temp[0][1]
            a[1][0] = temp[1][0]
            a[1][1] = temp[1][1]
        temp = [[0, 0], [0, 0]]
        temp[0][0] = (w[0][0]*w[0][0]+w[0][1]*w[1][0])%MOD
        temp[0][1] = (w[0][0]*w[0][1]+w[0][1]*w[1][1])%MOD
        temp[1][0] = (w[1][0]*w[0][0]+w[1][1]*w[1][0])%MOD
        temp[1][1] = (w[1][0]*w[0][1]+w[1][1]*w[1][1])%MOD
        w[0][0] = temp[0][0]
        w[0][1] = temp[0][1]
        w[1][0] = temp[1][0]
        w[1][1] = temp[1][1]
        N //= 2
        
    return (a[0][0]+a[0][1])%MOD
        

T = int(input().strip())

for tc in range(T):
    N = int(input().strip())
    print(solve(N))