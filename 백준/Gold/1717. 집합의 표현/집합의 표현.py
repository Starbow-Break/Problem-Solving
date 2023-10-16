import sys
input = sys.stdin.readline
sys.setrecursionlimit(100000) ###!! 파이썬 재귀 횟수 늘려주기...!!!!!!
# sys.stdin = open('input.txt')

def union(num1,num2): # 합치는 함수
    # 부모를 찾은 다음 합치기

    # 부모 먼저 찾기
    p1 = find(num1)
    p2 = find(num2)

    if p1 == p2:
        return # 부모가 같으면 종료
    else:
        # 두번째 인자의 부모로 합치기
        arr[p1] = p2
        return # 종료

def find(num): # 부모 찾는 함수
    if arr[num] == num: # 만약에 같다면, 부모를 찾은거
        return num # 부모!
    else: # 부모를 찾아야함
        arr[num] = find(arr[num]) # 재귀를 통해 부모 찾고 갱신해주기
        return arr[num] # 부모!


n, m = map(int,input().split())
arr = [i for i in range(n + 1)]  # i 번째 인덱스의(노드의) 부모는 i번 노드
for _ in range(m):
    x, a, b = map(int,input().split())
    if x == 0:
        # 합치기
        union(a,b)
    else:
        # 같은 부모인지 찾기

        if find(a) == find(b):
            print('YES')
        else:
            print('NO')


