import sys
from itertools import permutations

input = sys.stdin.readline


# 사면체 각 네면에 대해서 삼각부등식을 만족하는지 확인
def check_triangular_inequalities(per):
    a, b, c, d, e, f = per
    return (
        a+b > c and a+c > b and b+c > a and
        c+d > e and c+e > d and d+e > c and
        b+d > f and b+f > d and d+f > b and
        a+e > f and a+f > e and e+f > a
    )


# 행렬의 행렬식
def det(a):
    if len(a) == 1:
        return a[0][0]

    ret = 0
    for i in range(len(a)):
        sub_matrix = []
        for row in range(1, len(a)):
            sub_row = []
            for col in range(len(a)):
                if col != i:
                    sub_row.append(a[row][col])
            sub_matrix.append(sub_row)

        ret += pow(-1, i % 2) * a[0][i] * det(sub_matrix)

    return ret


# McCrea determinant 값
def mccrea_det(per):
    a, b, c, d, e, f = per
    matrix = [
        [2*d*d, d*d+e*e-c*c, f*f+d*d-b*b],
        [d*d+e*e-c*c, 2*e*e, e*e+f*f-a*a],
        [f*f+d*d-b*b, e*e+f*f-a*a, 2*f*f]
    ]

    return det(matrix)


N = int(input())

for _ in range(N):
    length = list(map(int, input().split()))
    check = False
    for per in permutations(length):
        # 이미 된다는걸 확인했으면 종료
        if check:
            break

        # 삼각 부등식을 만족하는지 확인
        if not check_triangular_inequalities(per):
            continue

        # McCrea determinant 값이 0을 초과하는지 확인
        if mccrea_det(per) <= 0:
            continue

        check = True

    if check:
        print("YES")
    else:
        print("NO")