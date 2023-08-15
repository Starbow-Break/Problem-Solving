def nQueen(N, r, pos):
    if r == N: return 1
    ret = 0
    for c in range(N):
        for i in range(r):
            if pos[i]-c == 0 or pos[i]-c == r-i or pos[i]-c == i-r: break
        else:
            pos[r] = c
            ret += nQueen(N, r+1, pos)
    return ret
print(f'{nQueen(int(input()), 0, [-1 for _ in range(14)])}')