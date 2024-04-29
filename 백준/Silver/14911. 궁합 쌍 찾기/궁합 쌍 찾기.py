values = list(map(int, input().split()))

cnt = [0 for _ in range(100001)]

for v in values:
    cnt[v] += 1

t = int(input())

i = 0
j = t

num = 0

while i <= j:
    if i == j:
        if cnt[i] >= 2:
            print(i, i)
            num += 1
    else:
        if cnt[i] > 0 and cnt[j] > 0:
            print(i, j)
            num += 1
            
    i += 1
    j -= 1
    
print(num)