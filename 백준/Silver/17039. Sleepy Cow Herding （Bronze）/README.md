# [Silver V] Sleepy Cow Herding (Bronze) - 17039 

[문제 링크](https://www.acmicpc.net/problem/17039) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

구현, 수학

### 제출 일자

2024년 1월 7일 16:12:52

### 문제 설명

<p>Farmer John's 3 prize cows, Bessie, Elsie, and Mildred, are always wandering off to the far reaches of the farm! He needs your help herding them back together.</p>

<p>The main field in the farm is long and skinny -- we can think of it as a number line, on which a cow can occupy any integer location. The 3 cows are currently situated at different integer locations, and Farmer John wants to move them so they occupy three consecutive locations (e.g., positions 6, 7, and 8).</p>

<p>Unfortunately, the cows are rather sleepy, and Farmer John has trouble getting their attention to make them move. At any point in time, he can only make a cow move if she is an "endpoint" (either the minimum or maximum position among all the cows). When he moves a cow, he can instruct her to move to any unoccupied integer location as long as in this new location she is no longer an endpoint. Observe that over time, these types of moves tend to push the cows closer and closer together.</p>

<p>Please determine the minimum and maximum number of moves possible before the cows become grouped in three consecutive locations.</p>

### 입력 

 <p>The input file contains one line with three space-separated integers, giving the locations of Bessie, Elsie, and Mildred. Each location is an integer in the range <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="2"><mjx-c class="mjx-c2026"></mjx-c></mjx-mo><mjx-msup space="2"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.393em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c39"></mjx-c></mjx-mn></mjx-script></mjx-msup></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>…</mo><msup><mn>10</mn><mn>9</mn></msup></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1 \ldots 10^9$</span></mjx-container>.</p>

### 출력 

 <p>The first line of output should contain the minimum number of moves Farmer John needs to make to group the cows together. The second line of output should contain the maximum number of such moves he could conceivably make before the cows become grouped together.</p>

