import sys
# sys.stdin = open('input.txt')
input = sys.stdin.readline

def union(x,y): # 합치는 함수
    # 부모를 찾은 다음, 합치기

    # 부모 먼저 찾기
    px = find(x)
    py = find(y)

    if px == py:
        return # 부모가 같으면 종료
    else:
        # 첫번째 인자의 부모로 합치기
        parent[py] = px
        friend[px] += friend[py]
        return # 종료

def find(x): # 부모 찾는 함수
    if parent[x] == x: # 만약에 같다면, 부모를 찾은거
        return x # 부모!
    else: # 부모를 찾아야함
        parent[x] = find(parent[x]) # 재귀를 통해 부모 찾고 갱신해주기
        return parent[x] # 부모!


T = int(input())
for tc in range(1, T+1):
    F = int(input()) # 친구 관계 수

    # 자식부모 정보 담을 빈 dict 만들기
    # key 값에 이름, value 값에 부모 정보 담기
    parent = {}

    # 친구 네트워크에 몇 명이 있는 지 구할 dict
    friend = {}

    for _ in range(F):
        a, b = input().split()
    #     parent[a] = a
    #     parent[b] = b
    # print(parent) # 즉 자기 자신을 부모로 가지는 dict


#### 문제는 이어져 있는지 아닌지 판별을 해야됌 #####

        if a not in parent: # 만약에 새로운 이름이면,
            # 딕셔너리에 추가
            parent[a] = a
            friend[a] = 1

        if b not in parent:
            parent[b] = b
            friend[b] = 1

        union(a,b)

        # print(parent)
        # print(friend)

        # 첫번째 이름의 부모를 찾아서, 그것의 친구 네트워크 수를 구함
        # friend 딕셔너리에서, 첫번째 이름의 부모 노드에 해당하는 key값으로 value 구함.
        print(friend[find(a)]) 