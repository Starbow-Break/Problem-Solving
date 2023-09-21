import sys
#sys.stdin = open('input.txt')

dr = [0, 0, 0, 1, -1]
dc = [0, 1, -1, 0, 0]

visited = [[False for _ in range(29)] for _ in range(29)]
p = list(map(int, input().split()))
N = p[0]


def solve(r, c, step, sz):
    if visited[r][c]:
        return 0

    if step == sz:
        return 1

    ret = 0
    visited[r][c] = True
    for k in range(1, 5):
        nr = r+dr[k]
        nc = c+dc[k]
        ret += p[k]/100*solve(nr, nc, step+1, sz)

    visited[r][c] = False
    return ret


print(f'{solve(14, 14, 0, N)}')