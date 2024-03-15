# [Platinum IV] Hidden Art - 30496 

[문제 링크](https://www.acmicpc.net/problem/30496) 

### 성능 요약

메모리: 4172 KB, 시간: 64 ms

### 분류

수학, 정수론

### 제출 일자

2024년 3월 15일 10:48:53

### 문제 설명

<p>You have recently moved to a new home, and you are almost done decorating it. However, you still feel like something is missing: you need some art on the wall! Since you have already spent most of your budget on the furniture, you decide to go to the cheapest art shop there is: the Budget Art Printing Company (BAPC).</p>

<p>At the BAPC, you can buy infinitely large sheets of paper on which a decoration is printed. Such a decoration consists of a rectangular pattern which is repeated in all directions. This pattern in turn consists of square pixels that are colored white, red, green or blue. After buying a sheet of paper, customers may then cut out a part of the sheet to create their very own artwork.</p>

<p>You have just found a pattern of pixels you like, but before you have it printed you decide to check whether it is possible to cut a <em>beautiful</em> artwork from it. You consider an artwork beautiful if it satisfies the following properties:</p>

<ul>
	<li>It is cut out along pixel boundaries.</li>
	<li>It is a square.</li>
	<li>The pixels in the four corners of the square have four different colors.</li>
</ul>

<p>Is there a beautiful artwork hidden in this infinite sheet printed with the selected pattern?</p>

<p>As an example, consider the first sample input, visualized in Figure H.1. In the infinitely repeated pattern, it is possible to find several beautiful artworks.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 378px; height: 235px;"></p>

<p style="text-align: center;">Figure H.1: Visualization of the first sample input. The pattern is shown repeated five times in the horizontal direction and two times in the vertical direction, but remember that it repeats indefinitely in all directions. The three bold outlined squares indicate some possible beautiful artworks.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with two integers <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c210E TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>h</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$h$</span></mjx-container> and <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D464 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>w</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$w$</span></mjx-container> (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c210E TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c34"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>≤</mo><mi>h</mi><mo>≤</mo><mn>4000</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1 \leq h \leq 4000$</span></mjx-container>, <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D464 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c35"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>≤</mo><mi>w</mi><mo>≤</mo><mn>50</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1 \leq w \leq 50$</span></mjx-container>), the height and width of the chosen pattern.</li>
	<li><mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"> <mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c210E TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>h</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$h$</span></mjx-container> lines, each with a string of <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D464 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>w</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$w$</span></mjx-container> characters <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D450 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>c</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$c$</span></mjx-container> ($c \in \{<code>w</code>, <code>r</code>, <code>g</code>, <code>b</code>\}$), describing the pattern.</li>
</ul>

### 출력 

 <p>If it is possible to cut out a beautiful artwork from the sheet with the selected pattern, output "<code>possible</code>", otherwise output "<code>impossible</code>".</p>

