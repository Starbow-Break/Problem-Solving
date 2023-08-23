import sys
import math
import copy
import heapq
from collections import deque

#sys.stdin = open('input.txt')
input = sys.stdin.readline


def generate_magic_square(sz):
    ret = [[0 for _ in range(sz)] for _ in range(sz)]
    # N이 홀수이면
    if sz % 2:
        r = -1
        c = sz//2
        for i in range(1, sz*sz+1):
            # (3의 배수)+1이면
            if i%sz == 1:
                r += 1
                ret[r][c] = i
            else:
                r -= 1
                c += 1
                # 마방진 판을 벗어나면 벗어난 위치에 따라 특정 위치로 이동시킨다.
                if r < 0:
                    r = sz-1
                if c >= sz:
                    c = 0
                ret[r][c] = i

    # N이 4의 배수이면
    elif not sz%4:
        for r in range(sz):
            for c in range(sz):
                ret[r][c] = r*sz+c+1

        for r in range(sz//4):
            for c in range(sz//4):
                ret[r][sz//4+c], ret[sz-1-r][sz-1-sz//4-c] = ret[sz-1-r][sz-1-sz//4-c], ret[r][sz//4+c]
                ret[r][sz//4*2+c], ret[sz-1-r][sz-1-sz//4*2-c] = ret[sz-1-r][sz-1-sz//4*2-c], ret[r][sz//4*2+c]
                ret[sz//4+r][c], ret[sz-1-sz//4-r][sz-1-c] = ret[sz-1-sz//4-r][sz-1-c], ret[sz//4+r][c]
                ret[sz//4*2+r][c], ret[sz-1-sz//4*2-r][sz-1-c] = ret[sz-1-sz//4*2-r][sz-1-c], ret[sz//4*2+r][c]

    # 그 이외의 경우
    else:
        for r in range(sz//2):
            for c in range(sz//2):
                if c < sz//4:
                    ret[r][c] = 3
                    ret[r+sz//2][c] = 0
                else:
                    ret[r][c] = 0
                    ret[r+sz//2][c] = 3

                if c < sz//2-sz//4+1:
                    ret[r][c+sz//2] = 2
                    ret[r+sz//2][c+sz//2] = 1
                else:
                    ret[r][c+sz//2] = 1
                    ret[r+sz//2][c+sz//2] = 2
        ret[sz//4][0], ret[sz//4][sz//4] = ret[sz//4][sz//4], ret[sz//4][0]
        ret[sz//2+sz//4][0], ret[sz//2+sz//4][sz//4] = ret[sz//2+sz//4][sz//4], ret[sz//2+sz//4][0]

        for r in range(sz):
            for c in range(sz):
                ret[r][c] *= sz*sz//4

        small_ms = generate_magic_square(sz//2)
        for r in range(sz//2):
            for c in range(sz//2):
                ret[r][c] += small_ms[r][c]
                ret[r+sz//2][c] += small_ms[r][c]
                ret[r][c+sz//2] += small_ms[r][c]
                ret[r+sz//2][c+sz//2] += small_ms[r][c]

    return ret


N = int(input())
ans = generate_magic_square(N)
for arr in ans:
    print(*arr)