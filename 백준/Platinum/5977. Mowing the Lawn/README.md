# [Platinum III] Mowing the Lawn - 5977 

[문제 링크](https://www.acmicpc.net/problem/5977) 

### 성능 요약

메모리: 3584 KB, 시간: 16 ms

### 분류

다이나믹 프로그래밍, 자료 구조, 덱, 덱을 이용한 다이나믹 프로그래밍

### 문제 설명

<p>After winning the annual town competition for best lawn a year ago, Farmer John has grown lazy; he has not mowed the lawn since then and thus his lawn has become unruly. However, the competition is once again coming soon, and FJ would like to get his lawn into tiptop shape so that he can claim the title.</p>

<p>Unfortunately, FJ has realized that his lawn is so unkempt that he will need to get some of his N (1 <= N <= 100,000) cows, who are lined up in a row and conveniently numbered 1..N, to help him. Some cows are more efficient than others at mowing the lawn; cow i has efficiency E_i (0 <= E_i <= 1,000,000,000).</p>

<p>FJ has noticed that cows near each other in line often know each other well; he has also discovered that if he chooses more than K (1 <= K <= N) consecutive (adjacent) cows to help him, they will ignore the lawn and start a party instead. Thus, FJ needs you to assist him: determine the largest total cow efficiency FJ can obtain without choosing more than K consecutive cows.</p>

### 입력 

 <ul>
	<li>Line 1: Two space-separated integers: N and K</li>
	<li>Lines 2..N+1: Line i+1 contains the single integer: E_i</li>
</ul>

### 출력 

 <ul>
	<li>Line 1: A single integer that is the best total efficiency FJ can obtain.</li>
</ul>

