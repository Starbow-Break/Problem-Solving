# 어느 행성에서 사용하는 수 체계
NUMBERS = ["ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN"]


# 문자열을 대응되는 정수로 전환
def str_to_int(s):
    return NUMBERS.index(s)


# 정수를 대응되는 문자열로 전환
def int_to_str(i):
    return NUMBERS[i]


# 정렬된 리스트 반환
def solve(lst):
    int_lst = list(map(str_to_int, lst))    # 리스트의 모든 요소를 정수로 변환
    int_lst.sort()                          # 정렬
    ret = list(map(int_to_str, int_lst))    # 리스트의 모든 요소를 문자열로 변환
    return ret


T = int(input())
for t in range(1, T+1):
    tc, str_N = input().split()
    N = int(str_N)
    arr = list(input().split())
    print(tc, *solve(arr))