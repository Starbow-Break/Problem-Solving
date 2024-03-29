# [Platinum III] 목장 - 1586 

[문제 링크](https://www.acmicpc.net/problem/1586) 

### 성능 요약

메모리: 2512 KB, 시간: 36 ms

### 분류

단절점과 단절선, 그래프 이론, 그래프 탐색

### 제출 일자

2024년 3월 18일 21:23:57

### 문제 설명

<p>농부 이동호는 직사각형 모양의 목장을 많이 가지고 있다. 만약 두 개의 목장이 경계를 공유한다면, 두 목장은 연결되어 있는 것이다. 단, 모서리만을 공유하는 목장은 연결되어 있는 것이 아니다. 슈퍼목장이란 연결되어 있는 목장의 최대 집합이다. 다른 말로 하면, 슈퍼 목장에 포함되어 있는 임의의 두 개의 목장은 한 목장에서 다른 목장으로 슈퍼목장을 떠나지 않는 경로가 있는 것이다. 만약, 어떤 목장이 다른 목장과 서로 연결되어 있지 않으면, 그 때는, 그 자체를 슈퍼목장으로 친다.</p>

<pre>  123456789
  ---------
1|........6
2|11..22388
3|11..22388
4|11....3..
5|..77..344
6|99775....
7|..775....</pre>

<p> 위의 그림은 총 9개의 목장을 포함하고 있다. 그리고, 3개의 슈퍼목장이 있다. 1번 목장은 다른 목장과 경계를 공유하지 않는다. 따라서, 그 자체로 슈퍼목장이 된다. 2, 3, 4, 6, 8번 목장은 또 다른 슈퍼목장이고, 5, 7, 9번 목장은 또 다른 슈퍼목장이다. 1번 목장과 7번 목장은 모서리만을 공유하기 때문에 연결되어 있지 않은 것이다.</p>

<p>슈퍼목장의 불량도는 슈퍼목장을 포함하는 최소 직사각형의 면적에서 슈퍼목장의 면적을 빼면 된다. 예를 들어, 1번 목장만 가지고 있는 슈퍼목장의 불량도는 0이고, 2, 3, 4, 6, 8번 목장을 가지고 있는 슈퍼목장의 불량도는 10이고, 나머지를 가지고 있는 슈퍼목장은 불량도가 5이다.</p>

<p>이동호는 가지고 있는 목장 중에 하나의 목장을 팔려고 한다. 이동호는 다음 규칙 중을 이용해서 어떤 것을 팔 것인지 정하려고 한다.</p>

<ol>
	<li>팔려고 하는 목장은 반드시 가장 높은 불량도를 가지는 슈퍼목장에 포함되어야 한다. 만약, 가장 높은 불량도를 가지는 슈퍼목장이 여러 개라면, 동호는 아무거나 선택한다.</li>
	<li>팔려고 하는 목장은 그것이 속해있는 슈퍼목장을 두 개 혹은 그 이상으로 분열시키면 안 된다.</li>
	<li>위의 두 조건을 만족시킨다면, 동호는 면적이 가장 작은 목장을 선택할 것이다. 만약 면적이 가장 작은 목장이 여러 개라면, 목장 번호가 작은 것을 선택한다.</li>
</ol>

<p>목장 정보가 주어졌을 때, 동호가 팔 목장이 어떤 것인지 알아내는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 목장의 개수 N이 주어진다. N은 5,000보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에는 목장의 정보가 1번 목장부터 차례대로 주어진다. 목장의 정보는 a b c d와 같이 생겼으며, a는 목장의 가장 왼쪽 좌표, b는 목장의 가장 오른쪽 좌표, c는 목장의 가장 위쪽 좌표, d는 목장의 가장 아래쪽 좌표이다. 좌표는 100,000보다 작거나 같은 음이 아닌 정수이고, a는 b보다 작고, c는 d보다 작다. 겹치는 목장은 없다.</p>

### 출력 

 <p>첫째 줄에 동호가 팔 목장의 번호를 출력한다.</p>

