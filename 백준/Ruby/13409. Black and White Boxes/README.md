# [Ruby IV] Black and White Boxes - 13409 

[문제 링크](https://www.acmicpc.net/problem/13409) 

### 성능 요약

메모리: 67632 KB, 시간: 1512 ms

### 분류

게임 이론, 하켄부시 게임, 중간에서 만나기

### 문제 설명

<p>Alice and Bob play the following game.</p>

<ol>
	<li>There are a number of straight piles of boxes. The boxes have the same size and are painted either black or white.</li>
	<li>Two players, namely Alice and Bob, take their turns alternately. Who to play first is decided by a fair random draw.</li>
	<li>In Alice’s turn, she selects a black box in one of the piles, and removes the box together with all the boxes above it, if any. If no black box to remove is left, she loses the game.</li>
	<li>In Bob’s turn, he selects a white box in one of the piles, and removes the box together with all the boxes above it, if any. If no white box to remove is left, he loses the game.</li>
</ol>

<p>Given an initial configuration of piles and who plays first, the game is a definite perfect information game. In such a game, one of the players has sure win provided he or she plays best. The draw for the first player, thus, essentially decides the winner.</p>

<p>In fact, this seemingly boring property is common with many popular games, such as chess. The chess game, however, is complicated enough to prevent thorough analyses, even by supercomputers, which leaves us rooms to enjoy playing.</p>

<p>This game of box piles, however, is not as complicated. The best plays may be more easily found. Thus, initial configurations should be fair, that is, giving both players chances to win. A configuration in which one player can always win, regardless of who plays first, is undesirable.</p>

<p>You are asked to arrange an initial configuration for this game by picking a number of piles from the given candidate set. As more complicated configuration makes the game more enjoyable, you are expected to find the configuration with the maximum number of boxes among fair ones.</p>

### 입력 

 <p>The input consists of a single test case, formatted as follows.</p>

<pre>n
p<sub>1</sub>
.
.
.
p<sub>n</sub></pre>

<p>A positive integer n (≤ 40) is the number of candidate piles. Each p<sub>i</sub> is a string of characters B and W, representing the i-th candidate pile. B and W mean black and white boxes, respectively. They appear in the order in the pile, from bottom to top. The number of boxes in a candidate pile does not exceed 40.</p>

### 출력 

 <p>Output in a line the maximum possible number of boxes in a fair initial configuration consisting of some of the candidate piles. If only the empty configuration is fair, output a zero.</p>

