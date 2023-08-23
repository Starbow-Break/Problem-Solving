import sys
import math
import copy
import heapq
from collections import deque

#sys.stdin = open('input.txt')
input = sys.stdin.readline

# 판 움직이기
def move(n, m, lst, d):
    temp = copy.deepcopy(lst)
    change = False
    if d == 'L':
        for r in range(n):
            i = 0
            for c in range(m):
                if temp[r][c] == -1:
                    i = c+1
                if temp[r][c] > 0:
                    if temp[r][i] == -2:
                        temp[r][c] = 0
                        change = True
                    else:
                        if i != c:
                            temp[r][i] += temp[r][c]
                            temp[r][c] = 0
                            change = True
    if d == 'R':
        for r in range(n):
            i = m-1
            for c in range(m-1, -1, -1):
                if temp[r][c] == -1:
                    i = c-1
                if temp[r][c] > 0:
                    if temp[r][i] == -2:
                        temp[r][c] = 0
                        change = True
                    else:
                        if i != c:
                            temp[r][i] += temp[r][c]
                            temp[r][c] = 0
                            change = True
    if d == 'U':
        for c in range(m):
            i = 0
            for r in range(n):
                if temp[r][c] == -1:
                    i = r+1
                if temp[r][c] > 0:
                    if temp[i][c] == -2:
                        temp[r][c] = 0
                        change = True
                    else:
                        if i != r:
                            temp[i][c] += temp[r][c]
                            temp[r][c] = 0
                            change = True
    if d == 'D':
        for c in range(m):
            i = m-1
            for r in range(n-1, -1, -1):
                if temp[r][c] == -1:
                    i = r-1
                if temp[r][c] > 0:
                    if temp[i][c] == -2:
                        temp[r][c] = 0
                        change = True
                    else:
                        if i != r:
                            temp[i][c] += temp[r][c]
                            temp[r][c] = 0
                            change = True

    if not change:
        temp[0][0] = -3

    return temp


# 문제의 답 반환
def solve(n, m, lst, cmd):
    # 구슬이 다 빠졌는지 확인
    check = True
    for r in range(n):
        for c in range(m):
            if lst[r][c] > 0:
                check = False

    # 다 빠졌으면 현재까지의 과정 반환
    if check:
        return cmd

    # 아직 남은 구슬이 있으나 10회를 이미 다 채웠으면 빈 문자열 반환
    if len(cmd) >= 10:
        return ''

    # 판 움직이기
    for c in 'LRUD':
        if c == 'L':
            after = move(n, m, lst, 'L')
            if after[0][0] == -3:
                continue
            rst = solve(n, m, after, cmd+'L')
            if rst:
                return rst
        if c == 'R':
            after = move(n, m, lst, 'R')
            if after[0][0] == -3:
                continue
            rst = solve(n, m, after, cmd + 'R')
            if rst:
                return rst
        if c == 'U':
            after = move(n, m, lst, 'U')
            if after[0][0] == -3:
                continue
            rst = solve(n, m, after, cmd + 'U')
            if rst:
                return rst
        if c == 'D':
            after = move(n, m, lst, 'D')
            if after[0][0] == -3:
                continue
            rst = solve(n, m, after, cmd + 'D')
            if rst:
                return rst

T = int(input())
for _ in range(T):
    N, M = map(int, input().split())
    _arr = []
    arr = [[0 for _ in range(M)] for _ in range(N)]
    for _ in range(N):
        _arr.append(list(input().rstrip()))

    for r in range(N):
        for c in range(M):
            if _arr[r][c] == '#':
                arr[r][c] = -1
            if _arr[r][c] == 'O':
                arr[r][c] = -2
            if _arr[r][c] == '.':
                arr[r][c] = 1

    result = solve(N, M, arr, '')
    if result:
        print(result)
    else:
        print('XHAE')