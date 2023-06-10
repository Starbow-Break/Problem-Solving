# [Diamond II] 카드 셔플 - 19589 

[문제 링크](https://www.acmicpc.net/problem/19589) 

### 성능 요약

메모리: 49016 KB, 시간: 5136 ms

### 분류

스플레이 트리, 트리

### 문제 설명

<p>위에서부터 1, 2, ..., <em>N</em>이 적혀 있는 카드 한 벌이 있다. 이 때, 1 ≤ <em>x</em> ≤ <em>y</em> ≤ <em>N</em>인 두 정수 <em>x</em>, <em>y</em>에 대해 다음 쿼리를 수행한다.</p>

<ul>
	<li><tt><span style="background-color:#dddddd;">1 x y</span></tt> : 위에서부터 <em>x</em>번째에 있는 카드부터 <em>y</em>번째에 있는 카드까지를 제일 위로 올린다.</li>
	<li><tt><span style="background-color:#dddddd;">2 x y</span></tt> : 위에서부터 <em>x</em>번째에 있는 카드부터 <em>y</em>번째에 있는 카드까지를 제일 아래로 내린다.</li>
	<li><tt><span style="background-color:#dddddd;">3 x y</span></tt> : 위에서부터 <em>x</em>번째에 있는 카드부터 <em>y</em>번째에 있는 카드까지 <strong>리플 셔플</strong>을 한다. <em>y</em> − <em>x</em> + 1은 1,000 이하이다.</li>
</ul>

<p><strong>리플 셔플</strong>은 <em>N</em>장의 카드가 있을 때 카드를 위에서부터 ⌊(<em>N</em> + 1) / 2⌋장의 카드 덩어리와 나머지 덩어리로 나눈 후 교대로 카드를 두는 방식으로 카드를 섞는 것이다. 섞기 전에 제일 위에 있었던 카드가 섞은 후에도 제일 위로 오도록 한다.</p>

### 입력 

 <p>첫 줄에 카드 수 <em>N</em>(1 ≤ <em>N</em> ≤ 10<sup>6</sup>)과 쿼리의 수 <em>Q</em>(1 ≤ <em>Q </em>≤ 2 × 10<sup>5</sup>)가 주어진다. 다음 <em>Q</em>개의 줄에 쿼리가 주어진다.</p>

### 출력 

 <p>카드를 다 섞고 난 뒤 카드에 어떤 숫자가 적혀 있는지 위에서부터 순서대로 출력한다.</p>

