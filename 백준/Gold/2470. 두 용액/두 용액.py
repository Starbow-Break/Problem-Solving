import sys

#sys.stdin = open("input.txt")
input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))

arr.sort()

i = 0
j = N-1
ans = (int(1e9), int(1e9))

while i < j:
    if abs(ans[1]+ans[0]) > abs(arr[j]+arr[i]):
        ans = (arr[i], arr[j])

    if arr[j]+arr[i] > 0:
        j -= 1
    else:
        i += 1

print(*ans)