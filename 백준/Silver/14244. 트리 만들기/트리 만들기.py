import sys
import math
import copy
import heapq
from collections import deque

#sys.stdin = open("input.txt") #제출하기전에 꼭 주석 달것!
input = sys.stdin.readline

n, m = map(int, input().split())
for i in range(1, m+1):
    print(f'0 {i}')

if n > m+1:
    print(f'1 {m+1}')

for i in range(m+1, n-1):
    print(f'{i} {i+1}')