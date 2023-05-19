# [Gold III] Thread Knots - 17976 

[문제 링크](https://www.acmicpc.net/problem/17976) 

### 성능 요약

메모리: 3688 KB, 시간: 28 ms

### 분류

이분 탐색, 그리디 알고리즘, 매개 변수 탐색

### 문제 설명

<p>There are <em>n</em> threads on the x-axis. The length of the <em>i</em>-th thread, say <em>T<sub>i</sub></em>, is denoted by <em>l<sub>i</sub></em> and the location of its starting point by <em>x<sub>i</sub></em>, both being integers. We want to make a knot in each thread. The location of the knot must also be an integer. The knot can be made at any point in the thread and it is assumed that the length of the thread is not reduced by the knot. You can assume that no thread is totally contained by another, which means that there are no two thread <em>T<sub>i</sub></em> and <em>T<sub>j</sub></em> (<em>i</em> ≠ <em>j</em>) such that <em>x<sub>j</sub></em> ≤ <em>x<sub>i</sub></em> and <em>x<sub>i</sub></em>+<em>l<sub>i</sub></em> ≤ <em>x<sub>j</sub></em>+<em>l<sub>j</sub></em>.</p>

<p>We want to determine the location of the knot for each thread in order to make the distance between the closest two neighboring knots as big as possible.</p>

<p>For example, the figures below show the locations of the knots for six threads. The location of a knot is denoted by a point. All the threads actually lie on the x-axis, however, they are drawn separately to distinguish each other. In Figure I.1, the distance between the closest two knots is 20. However, if we make the knot for <em>T</em><sub>2</sub> at different location as shown in Figure I.2, the distance between the closest two knots becomes 25, which is what this problem requests. </p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/1a4d1dc4-61c4-40fd-b967-9bbd44f161c1/-/preview/" style="width: 516px; height: 136px;"></p>

<p style="text-align: center;">Figure I.1: An example of knots for 6 threads.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/974696fd-e6f2-4f37-b3d6-108be8dddd6d/-/preview/" style="width: 510px; height: 138px;"></p>

<p style="text-align: center;">Figure I.2: Another example with different location of knot for <em>T</em><sub>2</sub>.</p>

<p>Given information about the <em>n</em> threads, write a program that calculates the maximum distance between two closest knots.</p>

### 입력 

 <p>Your program is to read from standard input. The input starts with a line containing one integer, <em>n</em> (2 ≤ <em>n</em> ≤ 100,000), where <em>n</em> is the number of threads. In the following <em>n</em> lines, the <em>i</em>-th line contains two integers <em>x<sub>i</sub></em> (0 ≤ <em>x<sub>i</sub></em> ≤ 10<sup>9</sup>) and <em>l<sub>i</sub></em> (1 ≤ <em>l<sub>i</sub></em> ≤ 10<sup>9</sup>), where <em>x<sub>i</sub></em> and <em>l<sub>i</sub></em> denote the location of the starting point and the length of the <em>i</em>-th thread, respectively, You can assume that no thread is totally contained by another, which means that there are no two threads <em>T<sub>i</sub></em> and <em>T<sub>j</sub></em> (<em>i</em> ≠ <em>j</em>) such that <em>x<sub>j</sub></em> ≤ <em>x<sub>i</sub></em> and <em>x<sub>i</sub></em>+<em>l<sub>i</sub></em> ≤ <em>x<sub>j</sub></em>+<em>l<sub>j</sub></em>.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line. The line should contain an integer which is the maximum distance between two closest knots.</p>

