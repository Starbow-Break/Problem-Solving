# [Diamond III] Fibonacci Sums - 7964 

[문제 링크](https://www.acmicpc.net/problem/7964) 

### 성능 요약

메모리: 5928 KB, 시간: 184 ms

### 분류

애드 혹, 구현, 수학, 정수론

### 문제 설명

<p>Fibonacci numbers are an integer sequence defined in the following way: Fib<sub>0</sub>=1, Fib<sub>1</sub>=1, Fib<sub>i</sub>=Fib<sub>i-2</sub>+Fib<sub>i-1</sub> (for i ≥ 2). The first few numbers in this sequence are: (1,1,2,3,5,8,…).</p>

<p>The great computer scientist Byteazar is constructing an unusual computer, in which numbers are represented in Fibonacci system i.e. a bit string (b<sub>1</sub>,b<sub>2</sub>,…,b<sub>n</sub>) denotes the number b<sub>1</sub>⋅Fib<sub>1</sub>+b<sub>2</sub>⋅Fib<sub>2</sub>+…+b<sub>n</sub>⋅Fib<sub>n</sub>. (Note that we do not use Fib<sub>0</sub>.) Unfortunately, such a representation is ambiguous i.e. the same number can have different representations. The number 42, for instance, can be written as: (0,0,0,0,1,0,0,1),(0,0,0,0,1,1,1,0) or (1,1,0,1,0,1,1). For this very reason, Byteazar has limited himself to only using representations satisfying the following conditions:</p>

<ul>
	<li>if n > 1, then b<sub>n</sub>=1, i.e. the representation of a number does not contain leading zeros.</li>
	<li>if b<sub>i</sub>=1, then b<sub>i+1</sub>=0 (for i=1,…,n-1), i.e. the representation of a number does not contain two (or more) consecutive ones.</li>
</ul>

<p>The construction of the computer has proved more demanding than Byteazar supposed. He has difficulties implementing addition. Help him!</p>

<p>Write a programme which:</p>

<ul>
	<li>reads from the standard input the representations of two positive integers,</li>
	<li>calculates and writes to the standard output the representation of their sum.</li>
</ul>

### 입력 

 <p>The input contains the Fibonacci representations (satisfying the aforementioned conditions) of two positive integers x and y - one in the first, the other in the second line. Each of these representations is in the form of a sequence of non-negative integers, separated by single spaces. The first number in the line denotes the length of the representation n, 1 ≤ n ≤ 1,000,000. It is followed by n zeros and/or ones.</p>

### 출력 

 <p>In the first and only line of the output your programme should write the Fibonacci representation (satisfying the aforementioned conditions) of the sum x+y. The representation should be in the form of a sequence of non-negative integers, separated by single spaces, as it has been described in the Input section. The first number in the line denotes the length of the representation n, 1 ≤ n ≤ 1,000,000. It is followed by n zeros and/or ones.</p>

