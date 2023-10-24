import sys
# sys.stdin = open('input.txt')
input = sys.stdin.readline
sys.setrecursionlimit(100000000)

n, m = map(int, input().split())
arr = [i for i in range(n)]
# print(arr)

def union(num1,num2): # 합치는 함수
    # 부모를 찾은 다음 합치기

    # 부모 먼저 찾기
    p1 = find(num1)
    p2 = find(num2)

    if p1 == p2:
        return # 부모가 같으면 종료
    elif p1 > p2:
        # 더 작은 쪽 인자의 부모로 합치기
        arr[p1] = p2
        return # 종료
    elif p1 < p2:
        arr[p2] = p1
        return

def find(num): # 부모 찾는 함수
    if arr[num] == num: # 만약에 같다면, 부모를 찾은거
        return num # 부모!
    else: # 부모를 찾아야함
        arr[num] = find(arr[num]) # 재귀를 통해 부모 찾고 갱신해주기
        return arr[num] # 부모!

for i in range(m):
    a, b = map(int, input().split())
    if find(a) == find(b):
        print(i+1)
        break
    union(a, b)
else:
    print(0)