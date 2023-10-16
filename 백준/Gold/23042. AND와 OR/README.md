# [Gold I] AND와 OR - 23042 

[문제 링크](https://www.acmicpc.net/problem/23042) 

### 성능 요약

메모리: 2020 KB, 시간: 80 ms

### 분류

비트마스킹, 그리디 알고리즘, 수학

### 제출 일자

2023년 10월 16일 11:12:05

### 문제 설명

<p>당신에게 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개의 수가 주어집니다. 당신은 다음과 같은 작업을 하고 싶은 만큼 할 수 있습니다.</p>

<ul>
	<li>두 수를 고르고, 이 두 수를 두 수와 bitwise AND 및 bitwise OR가 모두 같은 두 음이 아닌 정수로 바꿉니다.</li>
</ul>

<p>당신은 작업을 수행한 후 이 수들의 곱을 최소화하고 싶습니다. <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개의 수의 최소화된 곱을 구하세요. 단, 이 곱이 매우 커질 수 있으니 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msup><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.393em;"><mjx-texatom size="s" texclass="ORD"><mjx-mn class="mjx-n"><mjx-c class="mjx-c39"></mjx-c></mjx-mn></mjx-texatom></mjx-script></mjx-msup><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c37"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msup><mn>10</mn><mrow data-mjx-texclass="ORD"><mn>9</mn></mrow></msup><mo>+</mo><mn>7</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$10^{9} + 7$</span></mjx-container>로 나눈 나머지를 대신 출력합니다.</p>

<p>Bitwise AND와 bitwise OR에 대한 설명은 노트 란을 참고하세요.</p>

### 입력 

 <p>첫째 줄에 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>2</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$2$</span></mjx-container> 이상 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c33"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mstyle><mjx-mspace style="width: 0.167em;"></mjx-mspace></mjx-mstyle><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>300</mn><mstyle scriptlevel="0"><mspace width="0.167em"></mspace></mstyle><mn>000</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$300\,000$</span></mjx-container> 이하인 정수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>이 주어집니다.</p>

<p>둘째 줄에 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개의 양의 정수가 공백을 사이에 두고 주어집니다. 각 정수는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msup><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.363em;"><mjx-texatom size="s" texclass="ORD"><mjx-mn class="mjx-n"><mjx-c class="mjx-c33"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-texatom></mjx-script></mjx-msup></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msup><mn>2</mn><mrow data-mjx-texclass="ORD"><mn>30</mn></mrow></msup></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$2^{30}$</span></mjx-container>보다 작습니다.</p>

### 출력 

 <p>첫째 줄에 최소화된 곱을 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msup><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.393em;"><mjx-texatom size="s" texclass="ORD"><mjx-mn class="mjx-n"><mjx-c class="mjx-c39"></mjx-c></mjx-mn></mjx-texatom></mjx-script></mjx-msup><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c37"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msup><mn>10</mn><mrow data-mjx-texclass="ORD"><mn>9</mn></mrow></msup><mo>+</mo><mn>7</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$10^{9} + 7$</span></mjx-container>로 나눈 나머지를 출력합니다.</p>

<p><strong>곱을 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msup><mjx-texatom texclass="ORD"><mjx-mn class="mjx-b"><mjx-c class="mjx-c1D7CF TEX-B"></mjx-c><mjx-c class="mjx-c1D7CE TEX-B"></mjx-c></mjx-mn></mjx-texatom><mjx-script style="vertical-align: 0.382em;"><mjx-texatom size="s" texclass="ORD"><mjx-texatom texclass="ORD"><mjx-mn class="mjx-b"><mjx-c class="mjx-c1D7D7 TEX-B"></mjx-c></mjx-mn></mjx-texatom></mjx-texatom></mjx-script></mjx-msup><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-texatom space="3" texclass="ORD"><mjx-mn class="mjx-b"><mjx-c class="mjx-c1D7D5 TEX-B"></mjx-c></mjx-mn></mjx-texatom></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msup><mrow data-mjx-texclass="ORD"><mn mathvariant="bold">10</mn></mrow><mrow data-mjx-texclass="ORD"><mrow data-mjx-texclass="ORD"><mn mathvariant="bold">9</mn></mrow></mrow></msup><mo>+</mo><mrow data-mjx-texclass="ORD"><mn mathvariant="bold">7</mn></mrow></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$\mathbf{10}^{\mathbf{9}} + \mathbf{7}$</span></mjx-container>로 나눈 나머지를 최소화하는 것이 아님에 주의하세요.</strong></p>

