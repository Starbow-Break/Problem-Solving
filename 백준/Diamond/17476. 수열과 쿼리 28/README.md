# [Diamond I] 수열과 쿼리 28 - 17476 

[문제 링크](https://www.acmicpc.net/problem/17476) 

### 성능 요약

메모리: 12668 KB, 시간: 272 ms

### 분류

자료 구조(data_structures), 느리게 갱신되는 세그먼트 트리(lazyprop), 세그먼트 트리(segtree)

### 문제 설명

<p>길이가 N인 수열 A<sub>1</sub>, A<sub>2</sub>, ..., A<sub>N</sub>이 주어진다. 이때, 다음 쿼리를 수행하는 프로그램을 작성하시오. </p>

<ul>
	<li><code>1 L R X</code>: 모든 L ≤ i ≤ R에 대해서 A<sub>i</sub> = A<sub>i</sub> + X를 적용한다. </li>
	<li><code>2 L R</code>: 모든 L ≤ i ≤ R에 대해서 A<sub>i</sub> = ⌊√A<sub>i</sub>⌋를 적용한다.</li>
	<li><code>3 L R</code>: A<sub>L</sub> + A<sub>L+1</sub> + ... + A<sub>R</sub>을 출력한다.</li>
</ul>

### 입력 

 <p>첫째 줄에 수열의 크기 N이 주어진다. (1 ≤ N ≤ 100,000)</p>

<p>둘째 줄에는 A<sub>1</sub>, A<sub>2</sub>, ..., A<sub>N</sub>이 주어진다. (1 ≤ A<sub>i</sub> ≤ 100,000)</p>

<p>셋째 줄에는 쿼리의 개수 M이 주어진다. (1 ≤ M ≤ 100,000)</p>

<p>넷째 줄부터 M개의 줄에는 쿼리가 한 줄에 하나씩 주어진다. (1 ≤ L ≤ R ≤ N, 1 ≤ X ≤ 100,000) 3번 쿼리는 한 번 이상 주어진다.</p>

### 출력 

 <p>3번 쿼리의 결과를 한 줄에 하나씩 출력한다.</p>

