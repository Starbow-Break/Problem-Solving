import sys
import math
import copy
import heapq

#sys.stdin = open("input.txt") #제출하기전에 꼭 주석 달것!
input = sys.stdin.readline

def bubble_sort(lst) :
    sz = len(lst)
    for i in range(sz):
        for j in range(sz-1):
            if lst[j][0]*lst[j+1][1] > lst[j][1]*lst[j+1][0]:
                lst[j], lst[j+1] = lst[j+1], lst[j]

N = int(input())
arr = []
for i in range(N):
    t, s = map(int, input().split())
    arr.append((t, s, i+1))
    bubble_sort(arr)

for a in arr:
    print(a[2], end = ' ')