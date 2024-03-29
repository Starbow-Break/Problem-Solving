# [Diamond III] 파이파이 - 27875 

[문제 링크](https://www.acmicpc.net/problem/27875) 

### 성능 요약

메모리: 2208 KB, 시간: 1536 ms

### 분류

수학, 분할 정복을 이용한 거듭제곱

### 문제 설명

<p>$\pi$로 나타내는 원주율은 원의 지름에 대한 둘레의 비율이다.</p>

<p>$\pi$의 값은 $3.1415926535897\cdots$와 같이 유리수가 아닌 무한소수이다.</p>

<p>그런데 $16$진법 세상에서의 $\pi$의 값은 $3.1415\cdots$가 아니다!</p>

<p>예를 들어, $16$진법 세상에서</p>

<p>$$\pi = 3 + \frac{2}{16^1} + \frac{4}{16^2} + \frac{3}{16^3} + \frac{15}{16^4} + \frac{6}{16^5}\cdots$$</p>

<p>이기 때문에, $3.243\mathrm{F}6\cdots$와 같이 나타낸다.</p>

<p>하지만 $\pi$의 소수점 아래 $n$번째 자리의 숫자를 구하는 것은 매우 쉬운 일이기 때문에 $\pi^2$의 소수점 아래 $n$번째 자리의 숫자를 구해야 한다.</p>

<p>양의 정수 $n$이 주어지면, $16$진법 세상에서 $\pi^2$의 소수점 아래 $n$번째 자리의 숫자를 구해보자.</p>

<p>단, $16$진법 세상에서는 $10$ 이상의 숫자의 경우, 다음과 같이 알파벳 대문자를 이용하여 숫자를 표시한다.</p>

<p style="text-align: center;"><code>A = 10</code>, <code>B = 11</code>, <code>C = 12</code>, <code>D = 13</code>, <code>E = 14</code>, <code>F = 15</code></p>

### 입력 

 <p>첫째 줄에 $n$이 주어진다. $(1\le n \le 314\,159)$</p>

### 출력 

 <p>첫째 줄에 $16$진법 세상에서 $\pi^2$의 소수점 아래 $n$번째 자리의 숫자를 출력한다.</p>

