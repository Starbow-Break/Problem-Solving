# [Platinum III] 카탈란 게임 - 31073 

[문제 링크](https://www.acmicpc.net/problem/31073) 

### 성능 요약

메모리: 8960 KB, 시간: 12 ms

### 분류

자료 구조, 게임 이론, 누적 합

### 제출 일자

2024년 4월 6일 14:54:35

### 문제 설명

<p>괄호 문자열은 여는 괄호 <code>(</code>와 닫는 괄호 <code>)</code>로만 이루어진 문자열을 의미한다. 올바른 괄호 문자열은 다음과 같이 정의된다.</p>

<ul>
	<li>빈 문자열은 올바른 괄호 문자열이다.</li>
	<li><code>S</code>가 올바른 괄호 문자열이라면, <code>(S)</code>도 올바른 괄호 문자열이다.</li>
	<li><code>S</code>와 <code>T</code>가 올바른 괄호 문자열이라면, 두 문자열을 이어 붙인 괄호 문자열 <code>ST</code>도 올바른 괄호 문자열이다.</li>
</ul>

<p>위 과정을 통해 만들어질 수 없는 모든 괄호 문자열은 올바른 괄호 문자열이 아니다.</p>

<p>최근 준희는 길이가 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>2</mn><mi>n</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$2n$</span></mjx-container>인 올바른 괄호 문자열의 개수가 카탈란 수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msub><mjx-texatom texclass="ORD"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D436 TEX-I"></mjx-c></mjx-mi></mjx-texatom><mjx-script style="vertical-align: -0.15em; margin-left: -0.045em;"><mjx-texatom size="s" texclass="ORD"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-texatom></mjx-script></mjx-msub></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msub><mrow data-mjx-texclass="ORD"><mi>C</mi></mrow><mrow data-mjx-texclass="ORD"><mi>n</mi></mrow></msub></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">${C}_{n}$</span></mjx-container>개라는 사실을 알게 되었다. 올바른 괄호 문자열을 좋아하는 준희는 올바른 괄호 문자열이 전체 괄호 문자열 중 너무 낮은 빈도로 등장한다고 생각하여 슬퍼하고 있었다.</p>

<p>지민이는 준희를 위로해 주기 위하여, 올바른 괄호 문자열이 충분히 많이 존재한다는 것을 보여주기로 하였다. 지민이는 다음과 같은 게임에서 준희에게 승리하여 올바른 괄호 문자열이 충분히 많다는 것을 보여주고 싶다.</p>

<p>길이 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>인 <strong>올바르지 않은</strong> 괄호 문자열 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D446 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>S</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$S$</span></mjx-container>에서, 두 명이 번갈아 가며 지울 문자가 없어질 때까지 <strong>맨 앞의 문자</strong> 또는 <strong>맨 뒤의 문자</strong>를 지운다. 게임 중 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D446 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>S</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$S$</span></mjx-container>가 <strong>빈 문자열이 아닌</strong> 올바른 괄호 문자열이 되는 순간이 존재한다면 지민이가 승리한다. 게임이 끝날 때까지 빈 문자열이 아닌 올바른 괄호 문자열이 등장하지 않으면 준희가 승리한다.</p>

<p>게임은 지민이가 먼저 시작한다. 길이 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>과 문자열 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D446 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>S</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$S$</span></mjx-container>가 주어졌을 때, 지민과 준희가 모두 최적의 선택만을 내린다면 누가 게임에서 이길지 알아보자.</p>

### 입력 

 <p>첫째 줄에는 괄호 문자열의 길이 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>이 주어진다.</p>

<p>둘째 줄에는 괄호 문자열 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D446 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>S</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$S$</span></mjx-container>가 주어진다.</p>

### 출력 

 <p>지민이와 준희 모두 최선을 다해 게임을 했을 때, 승리하는 사람을 출력한다.</p>

<p>지민이가 게임에서 승리한다면 <code>jimin</code>을, 준희가 승리한다면 <code>junhui</code>를 출력한다.</p>

