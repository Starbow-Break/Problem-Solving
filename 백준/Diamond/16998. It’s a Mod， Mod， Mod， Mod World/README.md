# [Diamond IV] It’s a Mod, Mod, Mod, Mod World - 16998 

[문제 링크](https://www.acmicpc.net/problem/16998) 

### 성능 요약

메모리: 2020 KB, 시간: 76 ms

### 분류

유클리드 호제법, 수학, 정수론

### 문제 설명

<p>You are given multiple problems with three integers p, q, and n. Find <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mstyle><mjx-munderover><mjx-over style="padding-bottom: 0.192em; padding-left: 0.51em;"><mjx-texatom size="s" texclass="ORD"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-texatom></mjx-over><mjx-box><mjx-munder><mjx-row><mjx-base><mjx-mo class="mjx-lop"><mjx-c class="mjx-c2211 TEX-S2"></mjx-c></mjx-mo></mjx-base></mjx-row><mjx-row><mjx-under style="padding-top: 0.167em; padding-left: 0.148em;"><mjx-texatom size="s" texclass="ORD"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c3D"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-texatom></mjx-under></mjx-row></mjx-munder></mjx-box></mjx-munderover><mjx-texatom space="2" texclass="ORD"><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45D TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c22C5"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="3"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo><mjx-mtext class="mjx-n"><mjx-c class="mjx-cA0"></mjx-c><mjx-c class="mjx-c6D"></mjx-c><mjx-c class="mjx-c6F"></mjx-c><mjx-c class="mjx-c64"></mjx-c><mjx-c class="mjx-cA0"></mjx-c></mjx-mtext><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45E TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo></mjx-texatom></mjx-mstyle></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mstyle displaystyle="true" scriptlevel="0"><munderover><mo data-mjx-texclass="OP">∑</mo><mrow data-mjx-texclass="ORD"><mi>i</mi><mo>=</mo><mn>1</mn></mrow><mrow data-mjx-texclass="ORD"><mi>n</mi></mrow></munderover><mrow data-mjx-texclass="ORD"><mo stretchy="false">(</mo><mo stretchy="false">(</mo><mi>p</mi><mo>⋅</mo><mi>i</mi><mo stretchy="false">)</mo><mtext> mod </mtext><mi>q</mi><mo stretchy="false">)</mo></mrow></mstyle></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\(\displaystyle\sum_{i=1}^{n}{((p \cdot i) \text{ mod } q)}\)</span></mjx-container>. That is, the first n multiples of p, modulo q, summed. Note that the overall sum has no modulus.</p>

### 입력 

 <p>Each input will begin with a line with a single integer W (1 ≤ W ≤ 10<sup>5</sup>), which is the number of cases you must solve.</p>

<p>Each of the next W lines will contain three space-separated integers p, q and n (1 ≤ p, q, n ≤ 10<sup>6</sup>), which are the parameters of the problem as described above.</p>

### 출력 

 <p>Output W lines, each with the answer for a given instance of the problem, in the order that they appear in the input.</p>

