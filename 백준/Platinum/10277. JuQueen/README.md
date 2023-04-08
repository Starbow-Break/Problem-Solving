# [Platinum II] JuQueen - 10277 

[문제 링크](https://www.acmicpc.net/problem/10277) 

### 성능 요약

메모리: 198632 KB, 시간: 216 ms

### 분류

자료 구조, 세그먼트 트리, 느리게 갱신되는 세그먼트 트리

### 문제 설명

<p>JuQueen is the super computer with the best performance allover Germany. It is on rank 8 in the famous top500 list with its 458 752 cores. It draws a lot of energy (up to 2 301 kW), so we want to reduce that by underclocking the unused cores. The cluster scheduling algorithm which is in charge of distributing jobs over the nodes and cores of a cluster will issue the following speedstepping commands:</p>

<ul>
	<li><code>change X S</code> changes the frequency of core X by S steps</li>
	<li><code>groupchange A B S</code> changes the frequency of every core in range [A,B] by S steps</li>
	<li><code>state X</code> returns the current state of core X</li>
</ul>

<p>To be safe for the future, your program should be able to handle 4 587 520 cores. The initial frequency for each core is 0.</p>

### 입력 

 <p>The input contains a single test case. It starts with a line containing three integers C, N, and O, where C is the number of cores (1 ≤ C ≤ 4 587 520) to manage, N is the number of frequency steps for each core (1 ≤ N ≤ 10 000) and O is the number of operations in the test program (1 ≤ O ≤ 50 000). Then follow O lines, each containing one command as described above. X, A and B are 0-based IDs of the cores (0 ≤ A, B, X < C; A ≤ B). S is an integer number of steps, possibly negative (−N ≤ S ≤ +N).</p>

<p>Both, the change and the groupchange command will increase (or decrease) in single steps and stop as soon as one core in the group reaches the minimal (0) or maximal frequency (N).</p>

### 출력 

 <p>Output one line for every operation in the input. For <code>change</code> and <code>groupchange</code> print the changed number of steps, for state print the current state.</p>

