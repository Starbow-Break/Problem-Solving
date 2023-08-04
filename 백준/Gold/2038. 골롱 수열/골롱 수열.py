arr = [1, 2, 2, 3, 3]

idx = 3
while idx <= 5000:
    for _ in range(arr[idx]):
        arr.append(idx+1)
    idx += 1

N = int(input())
ans = 1
while arr[ans-1] < N:
    N -= arr[ans-1]
    ans += 1
print(ans)