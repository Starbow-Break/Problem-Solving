# [Silver V] 두라무리 휴지 - 25178 

[문제 링크](https://www.acmicpc.net/problem/25178) 

### 성능 요약

메모리: 2808 KB, 시간: 4 ms

### 분류

구현, 문자열

### 제출 일자

2024년 1월 3일 08:12:00

### 문제 설명

<p>기령이는 어느 날 캠릿브지 대학의 연결구과에 대해 알게 되었다. 캠릿브지 대학의 연결구과란, 단어를 이해함에 있어 한 단어 안에서 글자들이 어떤 순서로 배열되어 있는지는 중요하지 않고, 양 끝의 글자가 올바른지만 중요하다는 이론이다. 즉 단어의 글자가 섞이더라도 양 끝의 글자만 그대로라면 원래의 단어를 쉽게 유추하여 이해할 수 있다는 것이다.</p>

<p>그러나 기령이는 "<code>durumari</code>"와 같은 단어를 "<code>daumurri</code>"로 바꾸게 된다면 원래의 단어를 유추하기 매우 어려워진다는 사실을 발견했다. 몇 날 며칠의 고민을 거듭한 끝에 위의 이론이 잘 작동할 수 있는 조건을 새롭게 찾아냈다.</p>

<ul>
	<li>한 단어를 재배열해 다른 단어를 만들 수 있어야 한다.</li>
	<li>두 단어의 첫 글자와 마지막 글자는 서로 동일해야 한다.</li>
	<li>각 단어에서 모음(<code>a</code>, <code>e</code>, <code>i</code>, <code>o</code>, <code>u</code>)을 제거한 문자열은 동일해야 한다.</li>
</ul>

<p>기령이는 새로운 조건을 발견하게 해준 단어를 기려 이를 두라무리 효과라 부르기로 했다.</p>

<p>기령이는 이제 어떤 두 단어가 두라무리 효과를 발생시키는지 판별하고 싶다. 하지만 오랜 고민으로 지쳐 이를 판단할 기력이 남아있지 않다. 지친 기령이를 대신하여 이를 판별하는 프로그램을 작성해보자.</p>

### 입력 

 <p>첫째 줄에 단어의 길이 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>(<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mstyle><mjx-mspace style="width: 0.167em;"></mjx-mspace></mjx-mstyle><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>2</mn><mo>≤</mo><mi>N</mi><mo>≤</mo><mn>100</mn><mstyle scriptlevel="0"><mspace width="0.167em"></mspace></mstyle><mn>000</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$2 \le N \le 100\,000$</span></mjx-container>)이 주어진다.</p>

<p>둘째 줄과 셋째 줄에는 길이가 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>이고 알파벳 소문자로 이루어진 문자열이 주어진다.</p>

### 출력 

 <p>두 문자열이 조건을 만족한다면 <span style="color:#e74c3c;"><code>YES</code></span>, 만족하지 않는다면 <span style="color:#e74c3c;"><code>NO</code></span>를 출력한다.</p>

