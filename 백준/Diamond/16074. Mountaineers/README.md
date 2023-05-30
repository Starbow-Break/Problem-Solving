# [Diamond V] Mountaineers - 16074 

[문제 링크](https://www.acmicpc.net/problem/16074) 

### 성능 요약

메모리: 68960 KB, 시간: 648 ms

### 분류

이분 탐색, 자료 구조, 분리 집합, 그래프 이론, 최소 스패닝 트리, 병렬 이분 탐색

### 문제 설명

<p>The Chilean Andes have become increasingly popular as a destination for backpacking and hiking. Many parts of the Andes are quite remote and thus dangerous. Because of this, the Ministry of Tourism wants to help travelers plan their trips. In particular, the travelers need to know how high they will have to climb during their journey, as this information will help them decide which equipment they need to bring. The Ministry has tasked you to provide the aspiring mountaineers with this data.</p>

<p>You are given a topographic map of a part of the Andes, represented as a two-dimensional grid of height values, as well as the list of origins and destinations. Mountaineers can move from each grid cell to any of the four adjacent cells. For each mountaineer find the minimal height that they must be able to reach in order to complete their journey</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>one line with three integers m, n and q (1 ≤ m, n ≤ 500, 1 ≤ q ≤ 10<sup>5</sup>), where m is the number of rows, n is the number of columns, and q is the number of mountaineers;</li>
	<li>m lines, each with n integers h<sub>1</sub>, . . . , h<sub>n</sub> (1 ≤ h<sub>i</sub> ≤ 10<sup>6</sup>), the height values in the map;</li>
	<li>q lines, each with four integers x<sub>1</sub>, y<sub>1</sub>, x<sub>2</sub>, y<sub>2</sub> (1 ≤ x<sub>1</sub>, x<sub>2</sub> ≤ m, 1 ≤ y<sub>1</sub>, y<sub>2</sub> ≤ n), describing a mountaineer who wants to trek from (x<sub>1</sub>, y<sub>1</sub>) to (x<sub>2</sub>, y<sub>2</sub>).</li>
</ul>

<p>The top left cell of the grid has coordinates (1, 1) and the bottom right cell has coordinates (m, n).</p>

### 출력 

 <p>Output q integers, the minimal height for each mountaineer, in the same order as in the input.</p>

