# [Diamond I] 수열과 쿼리 19 - 14899 

[문제 링크](https://www.acmicpc.net/problem/14899) 

### 성능 요약

메모리: 14704 KB, 시간: 732 ms

### 분류

자료 구조, 느리게 갱신되는 세그먼트 트리, 세그먼트 트리

### 문제 설명

<p>길이가 n인 수열 A<sub>0</sub>, A<sub>1</sub>, ..., A<sub>n-1</sub>이 있다. 이때, 다음 쿼리를 수행하는 프로그램을 작성하시오.</p>

<ul>
	<li><code>1 l r c</code>: l ≤ i ≤ r에 속하는 모든 A<sub>i</sub>에 c를 더한다.</li>
	<li><code>2 l r d</code>: l ≤ i ≤ r에 속하는 모든 A<sub>i</sub>를 ⌊A<sub>i</sub>/d⌋로 바꾼다.</li>
	<li><code>3 l r</code>: l ≤ i ≤ r에 속하는 모든 A<sub>i</sub>중에서 가장 작은 값을 출력한다.</li>
	<li><code>4 l r</code>: l ≤ i ≤ r에 속하는 모든 A<sub>i</sub>의 합을 출력한다.</li>
</ul>

<p>⌊x⌋는 y ≤ x를 만족하는 가장 큰 정수 y이다. (⌊-2.5⌋ = -3, ⌊-7⌋ = -7)</p>

### 입력 

 <p>첫째 줄에 수열의 크기 n과 쿼리의 개수 q (1 ≤ n, q ≤ 100,000)가 주어진다.</p>

<p>둘째 줄에는 A<sub>0</sub>, A<sub>1</sub>, ..., A<sub>n-1</sub>가 주어진다. (-10<sup>9</sup> ≤ A<sub>i</sub> ≤ 10<sup>9</sup>)</p>

<p>다음 q개의 줄에는 쿼리가 한 줄에 하나씩 주어진다. (0 ≤ l ≤ r ≤ n-1, -10<sup>4</sup> ≤ c ≤ 10<sup>4</sup>, 2 ≤ d ≤ 10<sup>9</sup>)</p>

### 출력 

 <p>3번 4번 쿼리가 주어질 때 마다 정답을 한 줄에 하나씩 출력한다.</p>

