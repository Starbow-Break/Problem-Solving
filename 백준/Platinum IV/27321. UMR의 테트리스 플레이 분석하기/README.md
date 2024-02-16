# [Platinum IV] UMR의 테트리스 플레이 분석하기 - 27321 

[문제 링크](https://www.acmicpc.net/problem/27321) 

### 성능 요약

메모리: 4764 KB, 시간: 236 ms

### 분류

비트마스킹, 브루트포스 알고리즘, 해싱, 구현, 누적 합

### 제출 일자

2024년 2월 16일 12:15:00

### 문제 설명

<p>당신은 테트리스 마스터 UMR의 플레이를 따라하기 위해 UMR의 테트리스 플레이 영상을 분석하고 있다.</p>

<p>테트리스의 규칙은 다음과 같다.</p>

<ul>
	<li>게임은 세로 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>H</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$H$</span></mjx-container>칸, 가로 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D44A TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>W</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$W$</span></mjx-container>칸의 사각 격자 공간 내에서 이루어진다. 이 공간을 “필드”라고 한다.</li>
	<li>단위 정사각형 블록 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c34"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>4</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$4$</span></mjx-container> 개로 이루어진 여러 개의 테트로미노가 순서대로 주어지고, 플레이어는 테트로미노를 조작해서 필드 내의 원하는 곳에 놓는다.</li>
	<li>이때, 테트로미노는 회전할 수 있으나 뒤집을 수는 없다. 또한, 현재 필드 내에 있는 블록과 겹치는 곳에 놓을 수는 없으며, 테트로미노를 “공중에” 놓을 수도 없다. 다시 말해, 테트로미노를 한 칸 아래로 이동해도 필드를 벗어나거나 기존 블록과 겹치지 않는다면 그 곳에는 놓을 수 없다.</li>
	<li>어떤 테트로미노를 놓은 후에, 완전히 블록으로 가득 찬 가로줄은 모두 지워지고, 해당 가로줄 위쪽에 위치한 블록들이 아래로 이동한다. 이 때 지워진 가로줄의 수만큼 필드의 맨 위쪽에 비어있는 가로줄이 생긴다.</li>
</ul>

<p>테트로미노는 다음과 같이 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c37"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>7</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$7$</span></mjx-container>종류가 있으며, 왼쪽부터 순서대로 I, J, L, O, S, T, Z라고 부른다. 테트로미노를 뒤집을 수 없기 때문에 J와 L, S와 Z는 서로 다른 테트로미노이다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/10a07c12-9a30-4c06-986a-2a54193074d1/-/preview/"></p>

<p>당신은 영상을 분석하던 중, UMR의 플레이가 너무 빨라서 어떤 테트로미노를 놓기 전의 장면과 후의 장면만 찍힌 부분을 발견했다. 그 사이에 지나간 테트로미노는 과연 무엇이었을까?</p>

<p>이 문제에서는 테트로미노를 조작해서 원하는 곳으로 이동하는 과정은 무시하고, 위에서 제시한 조건에 맞는 곳이라면 어디든지 놓을 수 있다고 가정한다. (예제 3 참조)</p>

### 입력 

 <p>첫 번째 줄에 필드의 세로 크기 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>H</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$H$</span></mjx-container>와 가로 크기 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D44A TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>W</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$W$</span></mjx-container>가 공백으로 구분되어 주어진다. (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c35"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D43B TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mstyle><mjx-mspace style="width: 0.167em;"></mjx-mspace></mjx-mstyle><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>5</mn><mo>≤</mo><mi>H</mi><mo>≤</mo><mn>100</mn><mstyle scriptlevel="0"><mspace width="0.167em"></mspace></mstyle><mn>000</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$5\le H\le 100\,000$</span></mjx-container>, <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c35"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D44A TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>5</mn><mo>≤</mo><mi>W</mi><mo>≤</mo><mn>10</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$5\le W\le 10$</span></mjx-container>)</p>

<p>다음 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>H</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$H$</span></mjx-container>개의 줄에 어떤 테트로미노를 놓기 전의 필드의 상태가 주어진다. 각각의 칸에 대해 블록이 있으면 <code>#</code>, 없으면 <code>.</code>으로 주어지며, <code>#</code>로만 이루어진 가로줄이 포함된 입력은 주어지지 않는다.</p>

<p>그다음 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>H</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$H$</span></mjx-container>개의 줄에 테트로미노를 놓은 후의 필드의 상태가 같은 형식으로 주어진다.</p>

### 출력 

 <p><mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"> <mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c37"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>7</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$7$</span></mjx-container>가지 테트로미노 <code>I</code>, <code>J</code>, <code>L</code>, <code>O</code>, <code>S</code>, <code>T</code>, <code>Z</code> 중에서 가능한 종류를 출력한다. 가능한 종류가 여러 개라면 모든 가능한 종류를 알파벳 순으로 공백 없이 출력한다. 가능한 종류가 없다면 <code>X</code>를 출력한다.</p>

