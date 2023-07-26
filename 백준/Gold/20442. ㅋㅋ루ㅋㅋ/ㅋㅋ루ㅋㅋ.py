import sys
import math
import copy
#sys.stdin = open("input.txt") #제출하기전에 꼭 주석 달것!
input = sys.stdin.readline

s = input().strip()

R = 0
K = 0
for c in s:
    R += (c == 'R')

ans = R

i = 0
j = len(s)-1
while True:
    while i <= j and s[i] != 'K':
        R -= 1
        i += 1
        
    while i <= j and s[j] != 'K':
        R -= 1
        j -= 1

    if i > j:
        break

    K += 2
    if R > 0:
        ans = max(ans, R+K)
    i += 1
    j -= 1

print(ans)