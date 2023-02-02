# [Platinum III] Sky Tax - 13896 

[문제 링크](https://www.acmicpc.net/problem/13896) 

### 성능 요약

메모리: 18484 KB, 시간: 360 ms

### 분류

최소 공통 조상(lca), 트리(trees)

### 문제 설명

<p>New Bangkok is a newly built province of Thailand that is floating in the sky. In order for the province to be able to float, each city is supported by a spaceship. Because all spaceships are moving in same direction and velocity, the structure of the province stays still.</p>

<p>Cities are connected by sky ways. A sky way is a floating road connects two cities of New Bangkok together, so a citizen can commute from a city to another city by sky ways. With well urban planning, it is guaranteed that one can commute from any city to all other cities. Also, from a city to another city, there is only one simple route, i.e., no skyway that is used twice.</p>

<p>Because it is new, the province changes its capital city rapidly. This province also has a strange rule, this is, a city A must handle tax from a city B if a route from B to the capital city must pass through A. So it could be that a city have to handle taxes of many cities.</p>

<p>In this problem, we provide that structure of New Bangkok, an initial capital city, and number of queries. For each query, we ask you to either (1) move the capital city of the province to city R. or (2) given a city X, tell us how many cities that X has to handle taxes.</p>

### 입력 

 <p>The first line contains an integer T ≤ 10, number of test cases. Then for each test case:</p>

<p>The first line of the test case contains three integers 1 ≤ N ≤ 100 000, 1 ≤ Q ≤ 50 000, 1 ≤ R ≤ N, denote number of cities, number of queries, and an initial capital city in respective order.</p>

<p>Each of next N - 1 lines gives an information of a sky way. It contains two integers 1 ≤ A ≤ N and 1 ≤ B ≤ N, A ≠ B, there is a sky way connects A and B.</p>

<p>Each of next Q lines gives an information about query. It contains two integers 0 ≤ S ≤ 1 and 1 ≤ U ≤ N.</p>

<p>If S is 0, then it asks you to move the capital city to city U. Otherwise, it asks you to compute number of cities that U needs to handle taxes.</p>

### 출력 

 <p>You must print answer of test cases and queries in the order given in the input.</p>

<p>For test case I, you must start with a line containing "Case #I:" (without double quotes).</p>

<p>Then, for each query that needs an answer, print the answer in a line.</p>

