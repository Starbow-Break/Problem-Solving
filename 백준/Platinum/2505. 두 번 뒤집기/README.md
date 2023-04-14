# [Platinum V] 두 번 뒤집기 - 2505 

[문제 링크](https://www.acmicpc.net/problem/2505) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

구현, 애드 혹

### 문제 설명

<p>1부터 N까지의 숫자가 각 칸에 차례대로 들어있는 놀이판이 있다. 예를 들어 10 칸을 가진 놀이판의 초기 상태는 다음과 같다.  </p>

<table class="table table-bordered td-center table-center-30">
	<tbody>
		<tr>
			<td style="width:3%;">1</td>
			<td style="width:3%;">2</td>
			<td style="width:3%;">3</td>
			<td style="width:3%;">4</td>
			<td style="width:3%;">5</td>
			<td style="width:3%;">6</td>
			<td style="width:3%;">7</td>
			<td style="width:3%;">8</td>
			<td style="width:3%;">9</td>
			<td style="width:3%;">10</td>
		</tr>
	</tbody>
</table>

<p>구간[i,j]는 놀이판의 왼쪽 i번째 칸부터 j번째칸 사이에 있는 모든 숫자를 말한다. 단 구간[i,j]에서 항상 i ≤ j라고 가정한다. 우리는 이 놀이판의 한 구간을 잡아서 그 구간을 완전히 뒤집을  수 있다. 만일 초기상태에서 구간[3,8]을 뒤집으면 놀이판은 다음과 같이 변한다.</p>

<table class="table table-bordered td-center table-center-30">
	<tbody>
		<tr>
			<td style="width:3%;">1</td>
			<td style="width:3%;">2</td>
			<td style="width:3%;">8</td>
			<td style="width:3%;">7</td>
			<td style="width:3%;">6</td>
			<td style="width:3%;">5</td>
			<td style="width:3%;">4</td>
			<td style="width:3%;">3</td>
			<td style="width:3%;">9</td>
			<td style="width:3%;">10</td>
		</tr>
	</tbody>
</table>

<p>이어 이 상태에서 구간[1,5]를 다시 뒤집으면 놀이판은 다음과 같이 바뀐다. </p>

<table class="table table-bordered td-center table-center-30">
	<tbody>
		<tr>
			<td style="width:3%;">6</td>
			<td style="width:3%;">7</td>
			<td style="width:3%;">8</td>
			<td style="width:3%;">2</td>
			<td style="width:3%;">1</td>
			<td style="width:3%;">5</td>
			<td style="width:3%;">4</td>
			<td style="width:3%;">3</td>
			<td style="width:3%;">9</td>
			<td style="width:3%;">10</td>
		</tr>
	</tbody>
</table>

<p>여러분은 두 번 뒤집힌 놀이판의 상태를 입력으로 받아서 이를 다시 초기 상태로 돌리기 위해서 어떤 두 구간을 차례대로 뒤집어야 하는지를 계산해야 한다. 즉 여러분이 찾아낸 두 개의 구간대로 입력 놀이판을 차례대로 뒤집으면, 놀이판은 초기상태인 1, 2, 3, ...., N 으로 되돌아가야 한다.  </p>

<p>단 어떤 경우에는 초기상태로 되돌릴 수 있는 두 구간이 여러 개 있을 수도 있는데, 그러한 경우에는 그 중 하나만 출력해도 된다. 구간[i,i]를 뒤집으면 아무런 변화가 없는데 이러한 것도 허용이 된다.</p>

### 입력 

 <p>첫줄에는 숫자판의 크기를 나타내는 정수 N (5 ≤ N ≤ 10,000)이 주어진다. 그 다음 줄에는 두 개의 구간이 뒤집혀진 놀이판의 상태를 나타내는 숫자들이 하나의 공백을 두고 나타난다. </p>

### 출력 

 <p>첫 두 줄에는 뒤집어야 할 각 구간을 차례대로 출력해야 한다. 각 줄에는 구간[i,j]를 나타내는 i와 j를 빈 칸을 사이에 두고 출력해야 한다. 입력에 대한 답은 항상 존재한다.</p>

