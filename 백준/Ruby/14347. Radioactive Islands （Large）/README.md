# [Ruby IV] Radioactive Islands (Large) - 14347 

[문제 링크](https://www.acmicpc.net/problem/14347) 

### 성능 요약

메모리: 2036 KB, 시간: 316 ms

### 분류

이분 탐색, 미적분학, 수학, 수치해석

### 문제 설명

<p>You are steering a boat from the coordinates (-10, <strong>A</strong>) to the coordinates (10, <strong>B</strong>). The coordinates are measured in kilometers, and your boat travels at a constant speed of 1 kilometer per hour. You have full control over the path the boat takes. We model the boat as a single point.</p>

<p>There are <strong>N</strong> islands in the area; we model them as single points. The i-th island is at the coordinates (0, <strong>C<sub>i</sub></strong>).</p>

<p>The area is radioactive, and you constantly receive 1 microsievert per hour of radiation from the general environment, no matter where you are. Moreover, the islands themselves are radioactive, and you constantly receive additional radiation at a rate of (D<sub>i</sub>)<sup>-2</sup>microsieverts per hour from the i-th island, where D<sub>i</sub> is your current distance (in kilometers) from the i-th island. (Formally: let D<sub>i</sub>(t) be your distance from the i-th island as a function of time t, and X be the total time your journey takes. Then the total radiation received from the i-th island is the definite integral from 0 to X of D<sub>i</sub>(t)<sup>-2</sup>.) You can get as close to an island as you would like, as long as you do not match its exact coordinates.</p>

<p>Find the minimum total radiation dose that you can receive if you plot your course optimally.</p>

<ul>
</ul>

### 입력 

 <p>The first line of the input gives the number of test cases, <strong>T</strong>; <strong>T</strong> test cases follow. Each test cases consists of two lines. The first line of a test case consists of three values: an integer <strong>N</strong>, and two floating-point numbers <strong>A</strong> and <strong>B</strong>, as described in the statement above. The second line of a test case consists of <strong>N</strong> floating-point numbers <strong>C<sub>i</sub></strong>; the i-th of these numbers gives the y coordinate of the i-th island.</p>

<p>All floating-point numbers are specified to exactly two decimal places.</p>

<h3>Limits</h3>

<ul>
	<li>-10.00 ≤ <strong>A</strong> ≤ 10.00.</li>
	<li>-10.00 ≤ <strong>B</strong> ≤ 10.00.</li>
	<li>-10.00 ≤ <strong>C<sub>i</sub></strong> ≤ 10.00, for all i.</li>
	<li><strong>C<sub>i</sub></strong> ≠ <strong>C<sub>j</sub></strong>, for all i ≠ j.</li>
	<li>1 ≤ <strong>T</strong> ≤ 50;</li>
	<li>1 ≤ <strong>N</strong> ≤ 2.</li>
</ul>

### 출력 

 <p>For each test case, output one line containing <code>Case #x: y</code>, where <code>x</code> is the test case number (starting from 1) and <code>y</code> is the minimum radiation dose (in microsieverts) received while completing the journey.</p>

<p><code>y</code> will be considered correct if it is within an absolute or relative error of 10<sup>-3</sup> of the correct answer. See the <a href="https://code.google.com/codejam/faq.html#5-9" target="_blank">FAQ</a> for an explanation of what that means, and what formats of real numbers we accept.</p>

