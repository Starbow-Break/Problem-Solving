# [Gold IV] 초콜릿과 나이트 게임 - 25794 

[문제 링크](https://www.acmicpc.net/problem/25794) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

많은 조건 분기(case_work), 구성적(constructive)

### 문제 설명

<p>코코는 체스를 좋아한다. 체스의 나이트의 움직임이 너무 단순하다고 생각한 코코는 "ㅋ나이트"라는 체스 말을 새로 만들었다. 나이트는 한 번 움직일 때 가로로 1칸, 세로로 2칸 움직이거나, 가로로 2칸, 세로로 1칸 움직일 수 있다. ㅋ나이트는 나이트의 확장판으로, 한 번에 가로로 $X$칸, 세로로 $Y$칸 움직이거나, 가로로 $Y$칸, 세로로 $X$칸 움직일 수 있다.</p>

<p>나이트 게임은 무한한 초콜릿 격자판에서 진행하는 1인용 게임이다. 매 턴마다 규칙에 맞게 나이트를 이동하고, 원래 나이트가 있던 칸의 초콜릿을 떼서 먹는다. 초콜릿이 없는 칸으로 나이트를 움직일 수는 없으며, 더 이상 나이트를 움직일 수 없게 되면 게임이 종료된다.</p>

<p>코코와 가위바위보를 해서 진 한별이에게 코코는 99% 초콜릿과 ㅋ나이트를 가져와서 나이트 게임을 시켰다. 99% 초콜릿을 잘 먹지 못하는 한별이를 위해, ㅋ나이트를 어떻게 움직이면 가장 빨리 게임을 끝낼 수 있는지 알려주자. ㅋ나이트는 $(0, 0)$에서 시작한다.</p>

### 입력 

 <p>ㅋ나이트의 이동 규칙을 나타내는 $X$와 $Y$의 값이 한 줄에 순서대로 주어진다.</p>

### 출력 

 <p>첫 줄에는 이동 횟수 $K$를 출력한다. 다음 $K$줄에는 ㅋ나이트를 옮길 좌표를 한 줄에 하나씩 순서대로 출력한다. 시작 위치인 $(0, 0)$은 출력하지 않는다.</p>

