# [Diamond IV] 다항식과 쿼리 - 14882 

[문제 링크](https://www.acmicpc.net/problem/14882) 

### 성능 요약

메모리: 16256 KB, 시간: 168 ms

### 분류

고속 푸리에 변환, 수학, 정수론

### 문제 설명

<p>차수가 N이고 계수가 정수인 다항식 f(x) = a<sub>0</sub> + a<sub>1</sub>x + a<sub>2</sub>x<sup>2</sup> + ... + a<sub>N</sub>x<sup>N</sup>이 주어진다.</p>

<p>K개의 정수 x<sub>1</sub>, x<sub>2</sub>, ..., x<sub>K</sub>가 주어졌을 때, f(x<sub>1</sub>), f(x<sub>2</sub>), ..., f(x<sub>K</sub>)를 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 다항식의 차수 N(0 ≤ N ≤ 250,000)이 주어진다.</p>

<p>둘째 줄에는 N+1개의 정수가 주어진다. i번째 정수는 다항식의 계수 a<sub>i-1</sub>이다. (0 ≤ a<sub>i</sub> < 786,433)</p>

<p>셋째 줄에는 정수의 개수 K가 주어진다. (1 ≤ K ≤ 250,000)</p>

<p>넷째 줄에는 x<sub>1</sub>, x<sub>2</sub>, ..., x<sub>K</sub>가 주어진다. (0 ≤ x<sub>j</sub> < 786,433)</p>

### 출력 

 <p>총 K개의 줄을 출력한다. i번째 줄에는 f(x<sub>i</sub>)의 값을 786433로 나눈 나머지를 출력한다.</p>

