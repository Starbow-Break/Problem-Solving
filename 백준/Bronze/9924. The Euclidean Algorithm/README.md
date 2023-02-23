# [Bronze III] The Euclidean Algorithm - 9924 

[문제 링크](https://www.acmicpc.net/problem/9924) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

유클리드 호제법(euclidean), 구현(implementation), 수학(math), 정수론(number_theory)

### 문제 설명

<p>The famous Euclidean algorithm is found in Book VII of the <em>Elements</em>. The <em>Elements</em> was written in 300 B.C.~by the Greek mathematician Euclid. It is rumored that King Ptolemy, having looked through the <em>Elements</em>, hopefully asked Euclid if there were not a shorter way to geometry, to which Euclid severely answered: "In geometry there is no royal road!" Probably we should not blame the King for looking for short cuts, for there are thirteen books in the <em>Elements</em>\,! The books consist mainly of the mathematical knowledge amassed by Euclid, and possibly some discoveries of his own. The great achievement of Euclid is the beautifully systematic presentation of material as an organic whole. The <em>Elements</em> remained a standard work for over two thousand years. (see Episodes from the Early History of Mathematics, Asger Aaboe)</p>

<p>The modern Euclidean algorithm is often presented as</p>

<ol>
	<li>Let $A$ and $B$ be integers with $A > B \geq 0$.</li>
	<li>If $B = 0$, then the gcd is $A$ and the algorithm ends.</li>
	<li>Otherwise, find $q$ and $r$ such that \[ A = q B + r \mbox{ where } 0 \leq r < B \] Note that we have $0 \leq r < B < A$ and $\gcd(A,B) = \gcd(B,r)$. Replace $A$ by $B$, $B$ by $r$. Go to Step 2.</li>
</ol>

<p>But the original Euclidean algorithm uses subtraction instead of division. It is based on the observation that a common divisor of the positive integers $A$, $B$ is also a common divisor of the integers $\min(A,B)$, $\max(A,B)-\min(A,B)$. Thus the gcd of two positive integers can be found as</p>

<ol>
	<li>Let $A$ and $B$ be <strong>positive</strong> integers.</li>
	<li>If $A = B$ then the gcd is $B$ and the algorithm ends.</li>
	<li>Otherwise, replace $A$ by $\max(A,B)-\min(A,B)$, $B$ by $\min(A,B)$. Go to Step 2.</li>
</ol>

<p>For example, given $A = 24, B = 15$, the original Euclidean algorithm produces</p>

<ol>
	<li>$A = 24-15 = 9$, $B = 15$</li>
	<li>$A = 15-9 = 6$, $B = 9$</li>
	<li>$A = 9-6 = 3$, $B = 6$</li>
	<li>$A = 6-3 = 3$, $B = 3$</li>
</ol>

<p>That is, before finding $\gcd(24,15) = 3$, the original Euclidean algorithm has to execute Step 3 four times.</p>

### 입력 

 <p>The input consists of one line containing two positive integers (each not larger than 32767) separated by one or more spaces.</p>

### 출력 

 <p>The output consists of one line containing one integer.</p>

