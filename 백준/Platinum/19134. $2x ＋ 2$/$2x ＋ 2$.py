import sys
#sys.stdin = open('input.txt')
input = sys.stdin.readline

n = int(input())

ans = 0

i = 0
while True:
    a = 2 ** i
    b = 2 ** (i+1) - 2

    upper_bound = (n - b) // a

    if upper_bound <= 2:
        num = max(0, upper_bound)
    else:
        num = (upper_bound+1)//2+1

    if num == 0:
        break

    if i % 2 == 0:
        ans += num

    i += 1

print(ans)