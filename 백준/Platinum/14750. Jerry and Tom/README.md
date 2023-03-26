# [Platinum II] Jerry and Tom - 14750 

[문제 링크](https://www.acmicpc.net/problem/14750) 

### 성능 요약

메모리: 2892 KB, 시간: 52 ms

### 분류

기하학, 최대 유량, 선분 교차 판정

### 문제 설명

<p>Naughty mouse Jerry and his friend mice sometimes visit a vacant house to play the famous children game ‘hide and seek’ and also to adjust the length of their teeth by gnawing furniture and chairs left there. If we look down the house from the sky the boundary of it composes an orthogonal polygon parallel to the xy-axes as shown in the figure below. In other words, every wall of the house is either horizontal or vertical.</p>

<p>Tom, a threatening cat to them, sometimes appears in the house while they are enjoying the game. In that case Jerry and his friends should hide into the rat’s holes at the bottom on the walls. There are two rules which must be held for them to hide into the holes:</p>

<ol>
	<li>Each hole can afford at most k mice.</li>
	<li>Each mouse can enter the hole which can be seen by it. In other words, a mouse cannot enter the hole which is hidden by any wall. (That is, if the connecting line between a mouse and a hole intersects either any wall or any corner point of the house, the hole is considered hidden from the mouse.)</li>
</ol>

<p>For example, consider a situation where three mice and three holes are in the house as shown in Figure E.1. Each circle on the boundary denotes a hole. Assuming that k = 1, i.e., only one mouse is allowed to hide into each hole, with the situation shown in the left figure, when Tom appears all the three mice can hide. But for the case shown in the right figure it is impossible for all the mice to hide.</p>

<p style="text-align: center;"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/14750/1.png" style="height:125px; width:425px"></p>

<p style="text-align: center;">Figure E.1: Illustration to show two situations: 1. All mice can hide (left) and 2. They cannot (right)</p>

<p>You can assume:</p>

<ol>
	<li>Every mouse is strictly inside the house, which means that no mouse is on the wall</li>
	<li>Every hole is on the wall.</li>
	<li>No two holes locate at the same spot.</li>
	<li>No two mice locate at the same spot.</li>
</ol>

<p>Given a situation explained above, you are to write a program which determines whether all the mice can hide or not.</p>

### 입력 

 <p>Your program is to read from standard input. The input starts with a line containing four integers, n, k, h, and m, where n(1 ≤ n ≤ 1,000) is the number of the corner points of a house, k(1 ≤ k ≤ 5) the maximum number of mice each hole can afford, h(1 ≤ h ≤ 50) the number of holes, m(1 ≤ m ≤ k ∙ h) the number of mice. In each of the following n lines, each coordinate of the corner points of the house is given in counter clockwise order. Each point is represented by two integers separated by a single space, which are the x- coordinate and the y-coordinate of the point, respectively. Each coordinate is given as an integer between -10<sup>9</sup> and 10<sup>9</sup>, inclusively. In each of the following h lines, two integers x and y are given, which represent the coordinate (x, y) of each hole. In each of the following m lines, two integers x and y are given, which represent the coordinate (x, y) of each mouse.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line for the input. Print Possible if all the mice can hide into the rat’s holes holding the constraints explained above. Otherwise print Impossible.</p>

