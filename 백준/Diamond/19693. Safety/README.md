# [Diamond III] Safety - 19693 

[문제 링크](https://www.acmicpc.net/problem/19693) 

### 성능 요약

메모리: 8184 KB, 시간: 52 ms

### 분류

자료 구조, 다이나믹 프로그래밍, 우선순위 큐, 함수 개형을 이용한 최적화

### 문제 설명

<p>Squeaky the Mouse has recently gained an appreciation for the visual arts, and is now attempting his own work of art to be put on display in the most prestigious visual arts festival in town.</p>

<p>His artwork consists of many stacks of similar-sized illuminated cubes arranged to form a line. More precisely, there are N stacks, numbered from 1 to N from left to right, and stack i contains S[i] cubes. The following is one possibility of Squeaky’s artwork:</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/7aa11d96-0bd9-4535-8c8e-4371f0e7835f/-/preview/" style="width: 454px; height: 284px;"></p>

<p style="text-align: center;">Figure 5: Possible artwork configuration, with N = 20</p>

<p>As the cubes are massive, assembling the cubes to form the artwork is a very exhausting task, and Squeaky was only able to complete its assembly a few days before the start of the festival.</p>

<p>Just as he thought he was able to finally take a break, the safety committee came around to assess his artwork. The safety committee at this festival has been very particular and uncompromising ever since a disastrous mishap occurred during the festival last year.</p>

<p>When Squeaky saw the committee huddling together and speaking to one another in hushed voices, his heart sank. He knew that they found an issue with his work. Eventually, some members of the committee approached him and explained their concern: Some of the stacks might topple over when visitors bump into the artwork. Specifically, the artwork is only safe if the heights of adjacent stacks differ by no more than H cubes; equivalently, |S[i] − S[i + 1]| ≤ H for all 1 ≤ i ≤ N − 1.</p>

<p>They then gave him two choices – either alter the artwork to make it safe, or remove the artwork completely.</p>

<p>Of course, having spent so much effort on this piece, Squeaky didn’t consider removing the artwork to be an option at all, so he opted to alter the artwork by adding and removing some cubes. As carrying cubes around is tiring, he wants to minimize the amount of work he needs to do.</p>

<p>Formally, he wants to minimise the number of steps needed to make his artwork safe, where each step is one of the following:</p>

<ul>
	<li>Add one cube to the top of stack k</li>
	<li>Remove one cube from the top of stack k</li>
</ul>

<p>Help Squeaky determine the minimum number of steps he needs to make his artwork safe.</p>

### 입력 

 <p>Your program must read from standard input.</p>

<p>The first line of input contains two positive integers, N and H.</p>

<p>The second line of input contains N non-negative integers. The i<sup>th</sup> integer on this line is S[i].</p>

### 출력 

 <p>Your program must output a single integer — the minimum number of operations required to make the artwork safe.</p>

