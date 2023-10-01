import sys
from collections import deque

#sys.stdin = open("input.txt")
input = sys.stdin.readline

# 각 줄마다 잡고있는 프렛
stack = [deque(), deque(), deque(), deque(), deque(), deque()]

N, P = map(int, input().split())
ans = 0
for _ in range(N):
    num, p = map(int, input().split())
    # 더 높은 프렛은 전부 떼 준다.
    while stack[num-1] and stack[num-1][-1] > p:
        stack[num-1].pop()
        ans += 1
    # 목표 프렛을 잡고 있지 않으면 해당 프렛을 잡는다.
    if not stack[num-1] or stack[num-1][-1] != p:
        stack[num-1].append(p)
        ans += 1

print(ans)