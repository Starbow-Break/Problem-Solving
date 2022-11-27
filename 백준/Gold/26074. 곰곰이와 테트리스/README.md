# [Gold II] 곰곰이와 테트리스 - 26074 

[문제 링크](https://www.acmicpc.net/problem/26074) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

애드 혹(ad_hoc), 게임 이론(game_theory)

### 문제 설명

<p>곰곰이와 총총이가 재미있는 테트리스 게임을 하려고 한다.</p>

<p>테트리스 게임은 세로 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>칸, 가로 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>M</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$M$</span></mjx-container>칸인 빈 직사각형 게임판에서 시작한다.</p>

<p>곰곰이부터 돌아가면서 원하는 테트리스 블록 혹은 <em>1×1</em>블록을 빈 공간에 하나씩 배치한다.</p>

<p>단, 이때 블록을 회전시켜서 배치할 수 있으나 뒤집는 것은 불가능하고, 기존 블록과 겹치지 않고 격자와 테두리를 벗어나지 않게 배치해야 한다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/2662c74a-ffbd-4fea-a56f-4e3221d23eba/-/preview/"></p>

<p style="text-align: center;"><strong>[그림 1] 배치할 수 있는 블록의 종류와 번호 </strong></p>

<p>각 플레이어는 블록을 배치할 때마다 블록의 종류마다 정해진 점수를 얻는다. </p>

<p>게임을 진행하다 게임판에 더 이상 블록을 배치할 수 없게 되면 게임은 종료되고, 자신의 최종 점수로 승패를 겨루게 된다. </p>

<p>동점을 방지하기 위해, 곰곰이는 선공 페널티로 자신의 최종 점수에서 0.5점을 빼게 된다.</p>

<p>두 등장인물이 최적의 방법으로 게임을 진행했을 때, 마지막에 점수가 높은 등장인물이 누구인지 출력하자.</p>

<p>테트리스 블록과 <em>1×1</em>블록은 종류마다 개수가 무한히 있기 때문에 블록이 떨어지는 경우는 없다고 가정한다.</p>

### 입력 

 <p>첫째 줄에 게임판의 크기 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi><mjx-mtext class="mjx-n"><mjx-c class="mjx-cA0"></mjx-c></mjx-mtext><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c32"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi><mo>,</mo><mi>M</mi><mtext> </mtext><mo stretchy="false">(</mo><mn>1</mn><mo>≤</mo><mi>N</mi><mo>,</mo><mi>M</mi><mo>≤</mo><mn>20</mn><mo stretchy="false">)</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N, M\ (1 \leq N, M \leq 20)$</span></mjx-container>이 주어진다.</p>

<p>둘째 줄에 [그림 1]에 표시된 번호에 해당하는 블록의 점수 8개 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-msub space="4"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D443 TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em; margin-left: -0.109em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-script></mjx-msub><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mo class="mjx-n" space="2"><mjx-c class="mjx-c22EF"></mjx-c></mjx-mo><mjx-mo class="mjx-n" space="2"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-msub space="2"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D443 TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em; margin-left: -0.109em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c38"></mjx-c></mjx-mn></mjx-script></mjx-msub><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mtext class="mjx-n"><mjx-c class="mjx-cA0"></mjx-c></mjx-mtext><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo stretchy="false">(</mo><mn>1</mn><mo>≤</mo><msub><mi>P</mi><mn>1</mn></msub><mo>,</mo><mo>⋯</mo><mo>,</mo><msub><mi>P</mi><mn>8</mn></msub><mo>≤</mo><mn>1</mn><mtext> </mtext><mn>000</mn><mo stretchy="false">)</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$(1 \leq P_1, \cdots, P_8 \leq 1\ 000)$</span></mjx-container>가 차례대로 주어진다. </p>

<p>입력은 모두 양의 정수로 주어진다.</p>

### 출력 

 <p>곰곰이가 이기는 경우에는 <span style="color:#e74c3c;"><code>GomGom</code></span>, 총총이가 이기는 경우에는 <span style="color:#e74c3c;"><code>ChongChong</code></span>을 출력한다.</p>

