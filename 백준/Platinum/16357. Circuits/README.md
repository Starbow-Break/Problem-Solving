# [Platinum I] Circuits - 16357 

[문제 링크](https://www.acmicpc.net/problem/16357) 

### 성능 요약

메모리: 13684 KB, 시간: 268 ms

### 분류

값 / 좌표 압축(coordinate_compression), 자료 구조(data_structures), 느리게 갱신되는 세그먼트 트리(lazyprop), 세그먼트 트리(segtree), 스위핑(sweeping)

### 문제 설명

<p>There are a number of electronic circuits, such as CPU’s, ROM’s, RAM’s, to be printed in a single chip consisting of multiple layers. Due to some design restriction, there can be only two electrical wires that are horizontal segments. Your job is to find two horizontal wires that together connect as many circuits as possible so that the electric signals go through the circuits.</p>

<p>This problem can be stated formally as follows. There are <em>n</em> axis-aligned rectangles in the plane. Each of the rectangles represents a circuit to be printed in the chip. The rectangles may overlap each other. You are supposed to find two horizontal lines such that the total number of rectangles intersected by the two lines is maximized. We also say that a rectangle is intersected by a horizontal line if the line contains the top side or the bottom side of the rectangle. If a rectangle is intersected by both the lines, it is counted only once for the total number.</p>

<p>For example, let’s consider 5 rectangles shown in Figure A.1. Figure A.1(c) shows two horizontal lines (red dashed lines) that intersect all 5 rectangles while the two horizontal lines (red dashed lines) in Figure A.1(b) intersect 4 rectangles. </p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/cbca568c-783f-40c7-8f44-c72415245b24/-/crop/1224x426/0,0/-/preview/" style="width: 612px; height: 213px;"></p>

<p style="text-align: center;">Figure A.1: (a) 5 axis-aligned rectangles. (b) Two horizontal lines that intersect 4 rectangles. (c) Two horizontal lines that intersect 5 rectangles.</p>

<p>Given a set of axis-aligned rectangles, write a program to find two horizontal lines such that the total number of rectangles intersected by the two lines is maximized.</p>

### 입력 

 <p>Your program is to read from standard input. The first line contains a positive integer <em>n</em> representing the number of axis-aligned rectangles in the plane, where 3 ≤ <em>n</em> ≤ 100,000. It is followed by <em>n</em> lines, each contains four integers <em>u<sub>x</sub></em>, <em>u<sub>y</sub></em>, <em>v<sub>x</sub></em> and <em>v<sub>y</sub></em> (with <em>u<sub>x</sub></em> < <em>v<sub>x</sub></em> and <em>u<sub>y</sub></em> > <em>v<sub>y</sub></em>) representing the (x, y)-coordinates, (<em>u<sub>x</sub></em>, <em>u<sub>y</sub></em>), of the top-left corner and the (x, y)-coordinates, (<em>v<sub>x</sub></em>, <em>v<sub>y</sub></em>), of the bottom-right corner of an axisaligned rectangle, where −10,000,000 ≤ <em>u<sub>x</sub></em>, <em>u<sub>y</sub></em>, <em>v<sub>x</sub></em>, <em>v<sub>y</sub></em> ≤ 10,000,000.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line. The line should contain the maximum total number of rectangles that can be intersected by two horizontal lines.</p>

