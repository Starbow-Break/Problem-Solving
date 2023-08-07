import sys
from collections import deque
#sys.stdin = open('input.txt')
input = sys.stdin.readline


def area_square(a, b):
    return (b[0]-a[0])**2+(b[1]-a[1])**2


T = int(input())
for _ in range(T):
    N = int(input())
    pts = deque()  # 점들
    pts_set = set()
    for _ in range(N):
        x, y = map(int, input().split())
        pts.append((x, y))
        pts_set.add((x, y))

    pts = list(pts)
    pts.sort()

    ans = 0
    for i in range(N):
        for j in range(i+1, N):
            x1 = pts[i][0]
            y1 = pts[i][1]
            x2 = pts[j][0]
            y2 = pts[j][1]

            pt1 = (x1+y1-y2, y1+x2-x1)
            pt2 = (x2+y1-y2, y2+x2-x1)
            pt3 = (x1+y2-y1, y1+x1-x2)
            pt4 = (x2+y2-y1, y2+x1-x2)

            if pt1 in pts_set and pt2 in pts_set:
                ans = max(ans, area_square((x1, y1), pt1))
            if pt3 in pts_set and pt4 in pts_set:
                ans = max(ans, area_square((x1, y1), pt3))

    print(ans)