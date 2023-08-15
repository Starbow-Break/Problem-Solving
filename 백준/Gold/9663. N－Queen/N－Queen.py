pos = [-1 for _ in range(14)]
def nQueen(N, row):
    if row == N:
        return 1
    
    ret = 0
    for col in range(N):
        check = True
        for i in range(row):
            if pos[i]-col == 0 or pos[i]-col == row-i or pos[i]-col == i-row:
                check = False
                break
        if check:
            pos[row] = col
            ret += nQueen(N, row+1)
            pos[row] = -1
    
    return ret
    

N = int(input())
print(f'{nQueen(N, 0)}')