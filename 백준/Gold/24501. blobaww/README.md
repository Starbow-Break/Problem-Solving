# [Gold IV] blobaww - 24501 

[문제 링크](https://www.acmicpc.net/problem/24501) 

### 성능 요약

메모리: 221748 KB, 시간: 364 ms

### 분류

다이나믹 프로그래밍(dp), 누적 합(prefix_sum)

### 문제 설명

<p>블롭 세계에는 이러한 전설이 있다.</p>

<blockquote>
<p>100년 전, 천재 인간 채완이는 에너지를 글자 세 개로 저장할 수 있고, 자신이 원하는 형태로 바꿔 쓸 수 있는 "ENERGY SYNERGY MATRIX"를 개발하였다. 이후 블롭 세계의 블롭들은 에너지를 원하는 형태로 자유롭게 쓸 수 있게 되었고, 블롭 세계는 에너지 기술에서 엄청난 발전을 이룩하게 되었다.</p>
</blockquote>

<p>$ESM$을 오늘 알게 된 블롭 주환이는 이 전설을 듣고 놀라 자신이 구경하던 ENERGY SYNERGY MATRIX를 살펴보았다.</p>

<p style="text-align: center;"><img alt="" src=""><img alt="" src="https://upload.acmicpc.net/5935104c-92f4-47f7-825e-97c8c9b2f1ad/-/preview/"></p>

<p>"ENERGY SYNERGY MATRIX"는 문자 <code>E</code>, <code>S</code>, <code>M</code>으로 구성된 $N×M$ 크기의 2차원 행렬이다. 이를 줄여서 $ESM$이라고 하자.</p>

<p>주환이는 $ESM$을 켜려고 한다. $ESM$은 $ESM_{x1, y1} =$ <code>E</code>, $ESM_{x2, y2} =$ <code>S</code>, $ESM_{x3, y3} =$ <code>M</code> ($1 \leq x1 \leq x2 \leq x3 \leq N, 1 \leq y1 \leq y2 \leq y3 \leq M$)인 임의의 세 칸 $(x1, y1)$, $(x2, y2)$, $(x3, y3)$을 차례로 누르면 켜진다.</p>

<p>주환이는 $ESM$을 켤 수 있는 경우의 수가 궁금해졌다. 주환이를 도와 경우의 수를 구해 주자.</p>

<p>경우의 수가 커질 수 있으므로 $10^9+7$로 나눈 나머지를 출력한다.</p>

### 입력 

 <p>첫째 줄에 $N$과 $M$이 공백으로 구분되어 주어진다.</p>

<p>다음 $N$개의 줄에 걸쳐, 각 줄마다 $M$개의 문자가 공백 없이 주어진다.</p>

### 출력 

 <p>주환이가 조건에 맞게 고를 수 있는 경우의 수를 $10^9+7$로 나눈 나머지를 출력한다.</p>

