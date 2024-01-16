# [Platinum V] 스위치 배열 - 10258 

[문제 링크](https://www.acmicpc.net/problem/10258) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

애드 혹, 다이나믹 프로그래밍, 수학

### 제출 일자

2024년 1월 16일 20:03:00

### 문제 설명

<p>새로운 잠금 장치가 개발되었다.</p>

<p>이 장치는 열리거나 닫힌 상태를 갖는 여러 스위치(s<sub>1</sub>, s<sub>2 </sub>,.., s<sub>i-1</sub>, s<sub>i</sub>)들로 이루어져 있으며, 각각의 스위치는 0 또는 1의 상태를 갖는다. 따라서, 각 장치는 0과 1로 이루어진 스위치 배열로 나타낼 수 있다.</p>

<p>다음 표는 8개의 스위치를 가진 스위치 배열의 예제이다.</p>

<table class="table table-bordered" style="width:50%">
	<thead>
		<tr>
			<th>switch</th>
			<th>s<sub>1</sub></th>
			<th>s<sub>2</sub></th>
			<th>s<sub>3</sub></th>
			<th>s<sub>4</sub></th>
			<th>s<sub>5</sub></th>
			<th>s<sub>6</sub></th>
			<th>s<sub>7</sub></th>
			<th>s<sub>8</sub></th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<th>state</th>
			<td>0</td>
			<td>1</td>
			<td>1</td>
			<td>0</td>
			<td>1</td>
			<td>1</td>
			<td>0</td>
			<td>0</td>
		</tr>
	</tbody>
</table>

<p>N개의 스위치를 가진 배열의 각 스위치를 작동시키는 규칙은 다음과 같다.</p>

<ul>
	<li>규칙 1) S<sub>N</sub>은 아무 때나 토글하여 상태를 바꿀 수 있다.</li>
	<li>규칙 2) S<sub>i+1</sub> = 1이며 S<sub>i+2</sub>, S<sub>i+3</sub>, ..., S<sub>N-1</sub>, S<sub>N</sub>은 모두 0일 때, S<sub>i</sub>를 토글하여 상태를 바꿀 수 있다. 이 규칙은 스위치 S<sub>i+2</sub>, S<sub>i+3</sub>, ..., S<sub>N-1</sub>, S<sub>N</sub>가 없을 때도 적용된다. 예를 들어, S<sub>N-1</sub>은 S<sub>N</sub>이 1이기만 하면 토글할 수 있다.</li>
	<li>규칙 3) 한 번에 하나의 스위치만 토글할 수 있다.</li>
</ul>

<p>모든 스위치의 상태가 0일 때 이 장치는 열린다.</p>

<p>위의 규칙에 따라 배열을 모두 0으로 바꾸는 최소 토글 횟수를 구하는 것이 당신의 과제이다.</p>

<p>아래의 표는 배열 '1111' 을 '0000' 으로 바꾸는 최소 횟수의 연산을 나타낸 것이다. '1111' 의 경우, 최소 10번의 연산으로 배열을 '0000' 으로 만들 수 있다.</p>

<table class="table table-bordered" style="width:50%">
	<thead>
		<tr>
			<th>operation</th>
			<th>s1</th>
			<th>s2</th>
			<th>s3</th>
			<th>s4</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<th>0</th>
			<td>1</td>
			<td>1</td>
			<td>1</td>
			<td>1</td>
		</tr>
		<tr>
			<th>1</th>
			<td>1</td>
			<td>1</td>
			<td>0</td>
			<td>1</td>
		</tr>
		<tr>
			<th>2</th>
			<td>1</td>
			<td>1</td>
			<td>0</td>
			<td>0</td>
		</tr>
		<tr>
			<th>3</th>
			<td>0</td>
			<td>1</td>
			<td>0</td>
			<td>0</td>
		</tr>
		<tr>
			<th>4</th>
			<td>0</td>
			<td>1</td>
			<td>0</td>
			<td>1</td>
		</tr>
		<tr>
			<th>5</th>
			<td>0</td>
			<td>1</td>
			<td>1</td>
			<td>1</td>
		</tr>
		<tr>
			<th>6</th>
			<td>0</td>
			<td>1</td>
			<td>1</td>
			<td>0</td>
		</tr>
		<tr>
			<th>7</th>
			<td>0</td>
			<td>0</td>
			<td>1</td>
			<td>0</td>
		</tr>
		<tr>
			<th>8</th>
			<td>0</td>
			<td>0</td>
			<td>1</td>
			<td>1</td>
		</tr>
		<tr>
			<th>9</th>
			<td>0</td>
			<td>0</td>
			<td>0</td>
			<td>1</td>
		</tr>
		<tr>
			<th>10</th>
			<td>0</td>
			<td>0</td>
			<td>0</td>
			<td>0</td>
		</tr>
	</tbody>
</table>

### 입력 

 <p>입력의 첫 줄엔 테스트 케이스의 수 T가 주어진다.</p>

<p>각 테스트 케이스마다 비트스트링 B가 한 줄에 주어지며, B의 첫 비트가 S<sub>1</sub>, 마지막 비트가 S<sub>N</sub>이다.</p>

<p>B의 길이는 2 ≤ |B| ≤ 31 을 만족한다.</p>

### 출력 

 <p>각 테스트 케이스마다 한 줄에 모든 스위치를 0으로 만들기 위한 최소의 연산 횟수를 출력한다.</p>

