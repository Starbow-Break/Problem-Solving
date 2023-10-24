import sys
from collections import deque
#sys.stdin = open('input.txt')
input = sys.stdin.readline

arr = []
s = 0
for i in range(5):
    arr.append(int(input()))
    s += arr[i]

arr.sort()

print(s//5)
print(arr[2])