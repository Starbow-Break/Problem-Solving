# [Platinum I] 직사각형 - 7626 

[문제 링크](https://www.acmicpc.net/problem/7626) 

### 성능 요약

메모리: 26060 KB, 시간: 552 ms

### 분류

값 / 좌표 압축(coordinate_compression), 자료 구조(data_structures), 세그먼트 트리(segtree), 스위핑(sweeping)

### 문제 설명

<p>축에 평행한 직사각형 N개가 평면 위에 있다. 이 직사각형들이 차지하는 전체 면적을 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 양의 정수 N이 주어진다. (1 ≤ N ≤ 200,000) 다음 N개 줄에는 공백으로 나누어진 네 값 "x<sub>1</sub>, x<sub>2</sub>, y<sub>1</sub>, y<sub>2</sub>"가 주어진다. 이 값은 직사각형 [x<sub>1</sub>,x<sub>2</sub>] × [y<sub>1</sub>,y<sub>2</sub>]를 나타낸다. 모든 좌표는 0보다 크거나 같고, 10<sup>9</sup>보다 작거나 같으며, 각각의 직사각형은 x<sub>1</sub> < x<sub>2</sub>, y<sub>1</sub> < y<sub>2</sub>를 만족한다.</p>

### 출력 

 <p>첫째 줄에 주어진 직사각형 N개가 차지하는 전체 면적을 출력한다. 한 구역이 여러 개의 직사각형으로 덮어져 있는 경우에도 한 번으로 센다.</p>

