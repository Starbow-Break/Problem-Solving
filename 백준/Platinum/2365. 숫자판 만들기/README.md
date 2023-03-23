# [Platinum III] 숫자판 만들기 - 2365 

[문제 링크](https://www.acmicpc.net/problem/2365) 

### 성능 요약

메모리: 55120 KB, 시간: 552 ms

### 분류

이분 탐색, 매개 변수 탐색, 최대 유량

### 문제 설명

<p>가로의 크기와 세로의 크기가 각각 N인 숫자판이 있다. 숫자판의 각 칸에는 음 아닌 정수들만 들어갈 수 있고 각 행과 각 열의 합이 미리 주어진다고 하자. N=2 인 경우의 예가 다음에 있다.</p>

<table class="table table-bordered" style="width:15%">
	<tbody>
		<tr>
			<td style="width:5%">?</td>
			<td style="width:5%">?</td>
			<td style="width:5%">12</td>
		</tr>
		<tr>
			<td>?</td>
			<td>?</td>
			<td>4</td>
		</tr>
		<tr>
			<td>6</td>
			<td>10</td>
			<td> </td>
		</tr>
	</tbody>
</table>

<p>위 그림에서 숫자판 옆의 수는 해당하는 행에 들어가는 숫자의 합을 나타내며, 숫자판 아래의 수는 해당하는 열에 들어가는 숫자의 합을 나타낸다. 이제, 숫자판에 주어진 합과 일치하도록 수를 넣으려고 한다. 합이 일치되도록 숫자를 넣는 방법은 여러 가지 있을 수 있으며 위의 예에 대해 서로 다른 형태를 3가지만 보이면 다음과 같다.</p>

<table class="table table-bordered" style="width:10%">
	<tbody>
		<tr>
			<td style="width:5%">5</td>
			<td style="width:5%">7</td>
		</tr>
		<tr>
			<td>1</td>
			<td>3</td>
		</tr>
	</tbody>
</table>

<table class="table table-bordered" style="width:10%">
	<tbody>
		<tr>
			<td style="width:5%">6</td>
			<td style="width:5%">6</td>
		</tr>
		<tr>
			<td>0</td>
			<td>4</td>
		</tr>
	</tbody>
</table>

<table class="table table-bordered" style="width:10%">
	<tbody>
		<tr>
			<td style="width:5%">4</td>
			<td style="width:5%">8</td>
		</tr>
		<tr>
			<td>2</td>
			<td>2</td>
		</tr>
	</tbody>
</table>

<p>이 문제에서는 가능한 여러 가지 형태중 숫자판에 들어가는 최대 숫자의 값을 최소로 하는 형태를 찾고자 한다. 그러므로, 위의 예에서는 최대 숫자가 6 인 형태가 원하는 답이다. 이 문제를 해결하는 프로그램을 작성하시오. </p>

### 입력 

 <p>입력의 첫째 줄에는 행(열)의 크기 N이 주어진다(1 ≤ N ≤ 50). 둘째 줄에는 N개의 정수가 주어진다. 주어지는 정수는 1행부터 N행까지의 합을 차례대로 나타낸다. 셋째 줄에는 N개의 정수가 주어진다. 주어지는 정수는 1열부터 N열까지의 합을 차례대로 나타낸다. 합을 나타내는 각 정수는 0 이상 10000 이하이다. 숫자판을 구성할 수 없는 입력은 주어지지 않는다고 가정한다.</p>

### 출력 

 <p>첫 줄에는 배정된 수들중 최댓값을 출력한다. 둘째 줄부터 (N+1)째줄까지 각 행에 배정된 수들을 한 줄에 한 행씩 출력한다. 배정되는 각각의 정수는 0 이상이어야 한다. </p>

