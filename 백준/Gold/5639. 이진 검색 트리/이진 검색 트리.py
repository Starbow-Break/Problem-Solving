import sys
import math
from collections import deque

#sys.stdin = open('input.txt')
input = sys.stdin.readline
sys.setrecursionlimit(100001)

MAX = 1000000

left_child = [-1 for _ in range(MAX+1)]
right_child = [-1 for _ in range(MAX+1)]
root = -1


def insert(value):
    cur = root
    while True:
        if value < cur:
            if left_child[cur] != -1:
                cur = left_child[cur]
            else:
                left_child[cur] = value
                break
        else:
            if right_child[cur] != -1:
                cur = right_child[cur]
            else:
                right_child[cur] = value
                break


def post_order(cur):
    if cur == -1:
        return

    post_order(left_child[cur])
    post_order(right_child[cur])
    print(cur)


while True:
    try:
        v = int(input().rstrip())
        if root == -1:
            root = v
        else:
            insert(v)

    except ValueError or EOFError:
        break

post_order(root)