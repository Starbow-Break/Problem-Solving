# [Gold III] 정수 수열 - 14440 

[문제 링크](https://www.acmicpc.net/problem/14440) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

수학, 분할 정복을 이용한 거듭제곱

### 문제 설명

<p>음이 아닌 정수 수열 A<sub>0</sub>, A<sub>1</sub>, A<sub>2</sub>, A<sub>3</sub>, ...이 있다.</p>

<p>모든 n ≥ 2에 대해서, A<sub>n</sub> = x×A<sub>n-1</sub> + y×A<sub>n-2</sub>를 만족한다.</p>

<p>A<sub>0</sub>과 A<sub>1</sub>의 마지막 두 자리가 주어졌을 때, A<sub>n</sub>의 마지막 두 자리를 구하는 프로그램을 작성하시오.</p>

<p>예를 들어, x=y=1이고, A<sub>0</sub> = 0, A<sub>1</sub> = 1인 경우에 수열은 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55 이다. A<sub>10</sub>의 마지막 두 자리는 55이다.</p>

### 입력 

 <p>첫째 줄에 x, y, a<sub>0</sub>, a<sub>1</sub>, n이 주어진다. (1 ≤ x, y ≤ 99, 0 ≤ n < 10<sup>8</sup>) a<sub>0</sub>과 a<sub>1</sub>은 A<sub>0</sub>, A<sub>1</sub>의 마지막 두 자리이다.</p>

### 출력 

 <p>A<sub>n</sub>의 마지막 두 자리를 출력한다.</p>

