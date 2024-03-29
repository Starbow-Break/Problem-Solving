# [Diamond V] 그림 그리기 - 14707 

[문제 링크](https://www.acmicpc.net/problem/14707) 

### 성능 요약

메모리: 15048 KB, 시간: 300 ms

### 분류

중국인의 나머지 정리, 고속 푸리에 변환, 수학, 정수론

### 문제 설명

<p>상수는 N행 M열의 격자에 L가지 색으로 그림을 그린다. 1행에서 시작해서 N행까지, 같은 행에서는 1열에서 시작해서 M열까지 순서대로 칠하는데, 1번 색부터 시작해서 L번 색까지 순서대로 사용한 뒤 다시 1번 색부터 사용한다. i번째 행의 높이는 H<sub>i</sub>이고 j번째 열의 너비는 W<sub>j</sub>이다. 상수는 물감을 낭비하고 싶지 않기 때문에, 그림을 그리기 전에 각 색이 얼마나 필요한지가 궁금해졌다. 상수를 위해 각 색으로 칠할 넓이가 얼마나 되는 지 구해보자.</p>

### 입력 

 <p>첫 번째 줄에 N, M, L가 주어진다. (1 ≤ N, M, L ≤ 123,456)</p>

<p>두 번째 줄에 각 행의 높이를 나타내는 N개의 자연수 Hi가 공백을 사이에 두고 주어진다. H<sub>i</sub>의 합은 10<sup>9</sup>을 넘지 않는다. (1 ≤ i ≤ N)</p>

<p>세 번째 줄에 각 열의 너비를 나타내는 M개의 자연수 Wj가 공백을 사이에 두고 주어진다. W<sub>j</sub>의 합은 10<sup>9</sup>을 넘지 않는다. (1 ≤ j ≤ M)</p>

### 출력 

 <p>L줄에 걸쳐 k번째 줄에 k번 색으로 칠할 넓이를 출력한다.</p>

