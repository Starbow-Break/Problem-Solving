# [Platinum V] 앨범정리 - 20541 

[문제 링크](https://www.acmicpc.net/problem/20541) 

### 성능 요약

메모리: 12068 KB, 시간: 100 ms

### 분류

자료 구조, 해시를 사용한 집합과 맵, 구현, 문자열, 트리, 트리를 사용한 집합과 맵

### 문제 설명

<p dir="ltr">지혜는 컴퓨터에 있는 사진들을 정리하기 위해 앨범정리 프로그램을 만들었다. 지혜가 만든  앨범정리 프로그램은 기본적으로 "album" 앨범이 존재하며 "album" 앨범은 절대로 삭제할 수 없다. 프로그램을 실행시키면 "album" 앨범부터 시작하여 명령어들을 통해 앨범 삭제/추가, 사진 삭제/추가, 현재앨범 이동 등을 할 수 있다. 앨범정리 프로그램은 다음과 같은 명령어 들로 구성 되어 있다. 수행할 명령어의 개수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>이 주어질 때 각 명령어 수행 후 문자열 출력이 필요한 명령어에 대해서 문자열을 출력한다.</p>

<ol>
	<li>mkalb
	<ul>
		<li><strong>명령어 수행후</strong>: 현재 앨범에 속해있는 앨범 중 동일한 이름을 가진 앨범이 존재하여 앨범이 생성되지 않았으면 "duplicated album name"을 출력합니다. 그렇지 않다면 아무것도 출력하지 않습니다.</li>
		<li>mkalb <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D446 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>S</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$S$</span></mjx-container>
		<ul>
			<li>현재 앨범에 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D446 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>S</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$S$</span></mjx-container> 의 이름을 가진 앨범을 생성합니다.</li>
			<li>현재 앨범에 속해있는 앨범 중 동일한 이름을 가진 앨범이 존재하면 앨범을 생성하지 않습니다.</li>
		</ul>
		</li>
	</ul>
	</li>
	<li>rmalb
	<ul>
		<li><strong>명령어 수행후</strong>: 삭제된 앨범의 개수와 사진의 개수를 공백으로 구분하여 출력합니다.</li>
		<li>rmalb <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D446 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>S</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$S$</span></mjx-container>
		<ul>
			<li>현재 앨범에 속해있는 앨범 중 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D446 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>S</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$S$</span></mjx-container> 의 이름을 가진 앨범이 존재한다면, 해당 앨범을 삭제합니다.</li>
			<li>삭제된 앨범에 속한 모든 앨범과 사진들 또한 삭제됩니다.</li>
		</ul>
		</li>
		<li>rmalb -1
		<ul>
			<li>현재 앨범에 속해있는 앨범이 존재한다면, 이름이 사전순으로 가장 빠른 앨범을 삭제 합니다.</li>
			<li>삭제된 앨범에 속한 모든 앨범과 사진들 또한 삭제됩니다.</li>
		</ul>
		</li>
		<li>rmalb 0
		<ul>
			<li>현재 앨범에 속해있는 모든 앨범을 삭제 합니다.</li>
			<li>삭제된 앨범에 속한 모든 앨범과 사진들 또한 삭제됩니다.</li>
		</ul>
		</li>
		<li>rmalb 1
		<ul>
			<li>현재 앨범에 속해있는 앨범이 존재한다면, 이름이 사전순으로 가장 늦은 앨범을 삭제 합니다. </li>
			<li>삭제된 앨범에 속한 모든 앨범과 사진들 또한 삭제됩니다.</li>
		</ul>
		</li>
	</ul>
	</li>
	<li>insert
	<ul>
		<li><strong>명령어 수행후</strong>: 현재 앨범에 속해있는 사진 중에 동일한 이름을 가진 사진이 존재하여 사진이 삽입되지 않았으면 "duplicated photo name"을 출력합니다. 그렇지 않다면 아무것도 출력하지 않습니다.</li>
		<li>insert <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D446 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>S</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$S$</span></mjx-container>
		<ul>
			<li>현재 앨범에 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D446 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>S</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$S$</span></mjx-container> 의 이름을 가진 사진을 삽입합니다.</li>
			<li>현재 앨범에 속해있는 사진 중 동일한 이름을 가진 사진이 존재하면 사진을 삽입하지 않습니다.</li>
		</ul>
		</li>
	</ul>
	</li>
	<li>delete
	<ul>
		<li><strong>명령어 수행후</strong>: 삭제된 사진의 개수를 출력합니다.</li>
		<li>delete <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D446 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>S</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$S$</span></mjx-container>
		<ul>
			<li>현재 앨범에 속해있는 사진 중 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D446 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>S</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$S$</span></mjx-container> 의 이름을 가진 사진이 존재한다면, 해당 사진을 삭제합니다.</li>
		</ul>
		</li>
		<li>delete -1
		<ul>
			<li>현재 앨범에 속해있는 사진이 존재한다면, 이름이 사전순으로 가장 빠른 사진을 삭제 합니다.</li>
		</ul>
		</li>
		<li>delete 0
		<ul>
			<li>현재 앨범에 속해있는 모든 사진을 삭제합니다.</li>
		</ul>
		</li>
		<li>delete 1
		<ul>
			<li>현재 앨범에 속해있는 사진이 존재한다면, 이름이 사전순으로 가장 늦은 사진을 삭제 합니다. </li>
		</ul>
		</li>
	</ul>
	</li>
	<li>ca
	<ul>
		<li><strong>명령어 수행후</strong>: 현재 앨범 이름을 출력합니다.</li>
		<li>ca <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D446 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>S</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$S$</span></mjx-container>
		<ul>
			<li>현재 앨범에 속해있는 앨범 중 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D446 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>S</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$S$</span></mjx-container> 의 이름을 가진 앨범으로 이동합니다.</li>
			<li>현재 앨범에 속해있는 앨범 중 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D446 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>S</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$S$</span></mjx-container> 의 이름을 가진 앨범이 없다면 현재 앨범에 머무릅니다.</li>
		</ul>
		</li>
		<li>ca ..
		<ul>
			<li>현재 앨범의 상위 앨범으로 이동합니다.</li>
			<li>현재 앨범이 최상위 앨범인 "album" 앨범이라면 현재 앨범에 머무릅니다.</li>
		</ul>
		</li>
		<li>ca /
		<ul>
			<li>최상위 앨범인 "album" 앨범으로 이동합니다.</li>
		</ul>
		</li>
	</ul>
	</li>
</ol>

<p>"A가 B에 속해있다"라는 것은 A의 <strong>바로 하위</strong>에 B가 있다는 것을 의미합니다. 만약 A가 B에 속해있고, B가 C에 속해있는 경우, A는 C에 속해 있는 것이 아닙니다. </p>

### 입력 

 <p>첫째 줄에 수행할 명령어의 개수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>이 주어진다.</p>

<p>다음줄 부터 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>줄에 걸쳐 앨범정리 프로그램의 명령어가 주어진다.</p>

### 출력 

 <p>문제 본문에 나와있는 앨범정리 프로그램 명령어의 설명에 따라 적절한 문자열을 출력한다.</p>

