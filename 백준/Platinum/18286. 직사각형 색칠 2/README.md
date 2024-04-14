# [Platinum III] 직사각형 색칠 2 - 18286 

[문제 링크](https://www.acmicpc.net/problem/18286) 

### 성능 요약

메모리: 2508 KB, 시간: 112 ms

### 분류

비트마스킹, 다이나믹 프로그래밍, 비트필드를 이용한 다이나믹 프로그래밍, 분할 정복을 이용한 거듭제곱, 수학

### 제출 일자

2024년 4월 14일 17:33:14

### 문제 설명

<p>단위 정사각형으로 나누어져 있는 N×M 크기의 직사각형이 주어졌을 때, 아래 조건을 만족하게 색칠하는 방법의 수를 구하는 프로그램을 작성하시오.</p>

<ul>
	<li>모든 칸은 검정색 또는 흰색 중 하나로 색칠해야 한다.</li>
	<li>같은 색으로 이루어진 2×2 크기의 정사각형이 없어야 한다.</li>
</ul>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/fdddd240-0eee-4363-891b-8cea411d42fc/-/preview/" style="width: 471px; height: 150px;"></p>

<p style="text-align: center;">N = 3, M = 3인 경우 올바른 색칠 방법</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/26ba28b2-9239-4c12-9b5c-5d72e7a32eca/-/preview/" style="width: 472px; height: 150px;"></p>

<p style="text-align: center;">N = 3, M = 3인 경우 올바르지 않은 색칠 방법</p>

<p>N, M이 주어졌을 때, N×M 크기의 직사각형을 올바르게 색칠하는 방법의 수를 1,000,000,007로 나눈 나머지를 구해보자.</p>

### 입력 

 <p>첫째 줄에 N (1 ≤ N ≤ 10<sup>18</sup>), M (1 ≤ M ≤ 5)이 주어진다.</p>

### 출력 

 <p>첫째 줄에 N×M 크기의 직사각형을 올바르게 색칠하는 방법의 수를 1,000,000,007로 나눈 나머지를 출력한다.</p>

