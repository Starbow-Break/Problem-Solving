import sys
import math
import heapq
from collections import deque

#sys.stdin = open('input.txt')
input = sys.stdin.readline

while True:
    N = int(input())
    if not N:
        break

    words = []
    for _ in range(N):
        word = input().rstrip()
        word_lower = word.lower()
        words.append((word_lower, word))

    words.sort()

    print(words[0][1])