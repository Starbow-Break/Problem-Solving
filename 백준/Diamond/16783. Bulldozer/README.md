# [Diamond II] Bulldozer - 16783 

[문제 링크](https://www.acmicpc.net/problem/16783) 

### 성능 요약

메모리: 51356 KB, 시간: 928 ms

### 분류

자료 구조, 기하학, 세그먼트 트리, 스위핑

### 문제 설명

<p>JOI Kingdom is famous for producing gold. In JOI Kingdom, once in every year, they use a bulldozer to mine gold.</p>

<p>The land of JOI Kingdom is described as a plane with xy-coordinates. There are N spots in the land. The i-th spot (1 ≤ i ≤ N) is (X<sub>i</sub>, Y<sub>i</sub>). Each spot has either gold or rock, but not both.</p>

<p>If the spot i has gold, when we mine it once, we obtain gold of value V<sub>i</sub>. If the spot i has rock, when we mine it once, we obtain rock. The cost to discard it is C<sub>i</sub>.</p>

<p>We use a bulldozer for mining in the following way. First, we choose two parallel lines in the xy-plane. Then, we mine all gold and rock, once for each, in the area between two parallel lines (including gold or rock lying on them).</p>

<p>The profit of JOI Kingdom is the total value of gold in the area for mining minus the total cost to discard rock in the same area. We want to maximize the profit of JOI Kingdom.</p>

<p>Write a program which calculates the maximum profit of JOI Kingdom.</p>

### 입력 

 <p>Read the following data from the standard input.</p>

<ul>
	<li>The first line of input contains an integer N, the number of spots where we can take gold or rock.</li>
	<li>The i-th line (1 ≤ i ≤ N) of the following N lines contains three space separated integers X<sub>i</sub>, Y<sub>i</sub>, W<sub>i</sub>.
	<ul>
		<li>If W<sub>i</sub> ≥ 1, the i-th spot (X<sub>i</sub>, Y<sub>i</sub>) has gold. When we mine it once, we obtain gold of value V<sub>i</sub> = W<sub>i</sub>.</li>
		<li>If W<sub>i</sub> ≤ −1, the i-th spot (X<sub>i</sub>, Y<sub>i</sub>) has rock. When we mine it once, we obtain rock, and the cost to discard it is C<sub>i</sub> = −W<sub>i</sub>.</li>
		<li>W<sub>i</sub> ≠ 0 is satisfied.</li>
	</ul>
	</li>
</ul>

### 출력 

 <p>Write one line to the standard output. The output contains the maximum profit of JOI Kingdom.</p>

