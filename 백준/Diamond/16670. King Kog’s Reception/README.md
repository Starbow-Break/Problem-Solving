# [Diamond V] King Kog’s Reception - 16670 

[문제 링크](https://www.acmicpc.net/problem/16670) 

### 성능 요약

메모리: 35964 KB, 시간: 164 ms

### 분류

자료 구조, 느리게 갱신되는 세그먼트 트리, 세그먼트 트리

### 문제 설명

<p>King Kog got annoyed of the usual laxity of his knights — they can break into his hall without prior notice! Thus, the King decided to build a reception with a queue where each knight chooses in advance the time when he will come and how long the visit will take. The knights are served in the order of the recorded time, but each knight has to wait until the visits of all the knights before him are finished.</p>

<p>Princess Keabeanie wants to see her father. However, she does not want to interrupt the knights so she joins the queue. Unfortunately, the knights change their minds very often — they can join the queue or cancel their visits. Please help the princess to understand how long she will have to wait until she sees her father if she enters the queue at the specified moments of time given the records at the reception.</p>

### 입력 

 <p>The first line of the input contains a single integer q (1 ≤ q ≤ 3 · 10<sup>5</sup>) — the number of events. An event can be of three types: join, cancel, or query.</p>

<ul>
	<li>Join “+ t d” (1 ≤ t, d ≤ 10<sup>6</sup>) — a new knight joins the queue, where t is the time when the knight will come and d is the duration of the visit.</li>
	<li>Cancel “- i” (1 ≤ i ≤ q) — the knight cancels the visit, where i is the number (counted starting from one) of the corresponding join event in the list of all events.</li>
	<li>Query “? t” (1 ≤ t ≤ 10<sup>6</sup>) — Keabeanie asks how long she will wait if she comes at the time t.</li>
</ul>

<p>It is guaranteed that after each event there are no two knights with the same entrance time in the queue. Cancel events refer to the previous joins that were not cancelled yet.</p>

<p>Keabeanie can come at the same time as some knight, but Keabeanie is very polite and she will wait for the knight to pass.</p>

### 출력 

 <p>For each query write a separate line with the amount of time Keabeanie will have to wait.</p>

