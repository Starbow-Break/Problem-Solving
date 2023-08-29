import sys
import math
import heapq
from collections import deque

#sys.stdin = open('input.txt')
input = sys.stdin.readline

N, K = map(int, input().split())
arr = list(map(int, input().rstrip().split(',')))

for _ in range(K):
    temp = []
    for i in range(len(arr)-1):
        temp.append(arr[i+1]-arr[i])
    arr = temp

arr = list(map(str, arr))

print(','.join(arr))