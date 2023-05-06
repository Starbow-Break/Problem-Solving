# [Diamond IV] 1013 피보나치 - 13729 

[문제 링크](https://www.acmicpc.net/problem/13729) 

### 성능 요약

메모리: 2024 KB, 시간: 4 ms

### 분류

분할 정복을 이용한 거듭제곱, 수학, 정수론

### 문제 설명

<p>F<sub>n</sub>을 n번째 피보나치 수, G<sub>n</sub>을 F<sub>n</sub> % 10<sup>13</sup>이라고 하다.</p>

<p>n이 주어졌을 때, G<sub>i</sub> = n인 가장 작은 i값을 찾는 프로그램을 작성하시오.</p>

<p>피보나치 수의 첫 부분은 아래와 같다.</p>

<ul>
	<li>F<sub>0</sub> = 0</li>
	<li>F<sub>1</sub> = 1</li>
	<li>F<sub>2</sub> = 1</li>
	<li>F<sub>3</sub> = 2</li>
	<li>F<sub>4</sub> = 3</li>
	<li>F<sub>5</sub> = 5</li>
	<li>F<sub>6</sub> = 8</li>
	<li>F<sub>7</sub> = 13</li>
	<li>F<sub>8</sub> = 21</li>
</ul>

### 입력 

 <p>첫째 줄에 정수 n(1 ≤ n ≤ 10<sup>13</sup>)이 주어진다.</p>

### 출력 

 <p>G<sub>i</sub> = n인 가장 작은 i값을 출력한다. 만약 그러한 i가 없으면 -1을 출력한다.</p>

