import sys
from collections import deque
#sys.stdin = open('input.txt')
input = sys.stdin.readline

N = int(input())

arr = []
for _ in range(N):
    arr.append(int(input()))

arr.sort()

for i in range(N):
    print(arr[i])