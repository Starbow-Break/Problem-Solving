# [Diamond III] 파인애플 피자 - 20298 

[문제 링크](https://www.acmicpc.net/problem/20298) 

### 성능 요약

메모리: 7284 KB, 시간: 248 ms

### 분류

자료 구조(data_structures), KMP(kmp), 세그먼트 트리(segtree), 문자열(string)

### 문제 설명

<p>$N$개의 조각으로 이뤄진 파인애플 피자 한 판이 있다. 각 피자 조각의 파인애플 토핑의 개수는 시계 방향 순으로 $a_1, a_2, \cdots, a_N$개다. 파인애플 피자를 맛보기 위해 $K(\le N)$명의 손님이 줄을 서서 기다리고 있다. 당신은 첫 조각을 고른 후, 시계 방향 순으로 피자를 한 조각씩 떼어 줄을 선 순서대로 손님에게 제공한다. 예를 들어, $4$명의 손님에게 토핑 개수가 $a_{N-1}$개, $a_N$개, $a_1$개, $a_2$개인 피자 조각을 순서대로 나눠줄 수 있다.</p>

<p>각 손님의 나이는 줄을 선 순서대로 $b_1, b_2, \cdots, b_K$이다. 손님들은 자신보다 나이가 어린 사람보다 파인애플 토핑을 많이 받아야 하고 나이가 같은 사람과는 같은 개수의 파인애플 토핑을 받아야 한다. 그렇지 못한 경우 손님은 그 자리에서 밥상을 엎어버린다.</p>

<p>손님들이 밥상을 엎지 않도록 피자 조각을 고를 수 있는 방법은 몇 가지일까?</p>

### 입력 

 <p>첫째 줄에 피자 조각의 개수 $N$과 손님의 수 $K$가 공백으로 구분되어 주어진다. ($1 \leq K \leq N \leq 100\ 000$)</p>

<p>둘째 줄에 각 피자 조각의 파인애플 토핑의 개수를 나타내는 정수 $a_1, a_2, \cdots, a_N$가 공백으로 구분되어 주어진다. ($0 \leq a_i \leq 10^9$)</p>

<p>셋째 줄에 손님들의 나이를 나타내는 정수 $b_1, b_2, \cdots, b_K$가 공백으로 구분되어 주어진다. ($0 \leq b_i \leq 10^9$)</p>

### 출력 

 <p>손님들이 밥상을 엎지 않도록 피자 조각을 고를 수 있는 방법의 수를 출력한다.</p>

