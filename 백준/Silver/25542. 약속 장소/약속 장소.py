import sys
import math
import copy
import heapq
from collections import deque

#sys.stdin = open("input.txt") #제출하기전에 꼭 주석 달것!
input = sys.stdin.readline

alpt = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

N, L = map(int, input().split())
words = []
for _ in range(N):
    words.append(input().rstrip())

ans = ''
for i in range(L):
    for c in alpt:
        cur = ''
        for j in range(L):
            if i == j:
                cur += c
            else:
                cur += words[0][j]

        check = True
        for j in range(1, N):
            cnt = 0
            for k in range(L):
                cnt += cur[k] != words[j][k]
            if cnt >= 2:
                check = False
                break

        if check:
            ans = cur
            break

if ans == '':
    print('CALL FRIEND')
else:
    print(ans)