# [Gold III] XCorr - 15976 

[문제 링크](https://www.acmicpc.net/problem/15976) 

### 성능 요약

메모리: 14440 KB, 시간: 152 ms

### 분류

이분 탐색(binary_search), 수학(math), 누적 합(prefix_sum)

### 문제 설명

<p>길이가 동일한 수열 $X=(x_0, x_1, \cdots, x_{n-1})$와 $Y=(y_0, y_1, \cdots, y_{n-1})$가 있다.</p>

<p>이 두 수열의 각 원소는 음이 아닌 정수이다. 다음은 $n=5$인 경우의 한 예이다.</p>

<p style="text-align: center;">\[X=(1,0,0,0,1)\]</p>

<p style="text-align: center;">\[Y=(0,5,2,0,1)\]</p>

<p>임의의 정수 $t$가 주어졌을 때 $XCorr(t)$는 다음과 같이 정의된다.</p>

<p style="text-align: center;">\[XCorr(t)=\displaystyle\sum_{i=0}^{n-1}{x_iy_{i+t}}\]</p>

<p style="text-align: center;">($i<0$이거나 $i\geq n$이면 $x_i=y_i=0$으로 간주한다.)</p>

<p>예를 들어 $t$가 $0, 1, -1$일 때, $XCorr(t)$값은 다음과 같이 계산된다.</p>

<p style="text-align: center;">\[XCorr(0) = x_0y_0 + x_1y_1 + \dots + x_{n-1}y_{n-1}\]</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/8e0de57f-6576-41af-bb75-a30cecfb2ac8/-/preview/" style="width: 233px; height: 111px;"></p>

<p style="text-align: center;">\[XCorr(1) = x_0y_1 + x_1y_2 + \dots + x_{n-1}y_n\]</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/3be4587f-07d4-40d7-8bfc-afa37891bd1d/-/preview/" style="width: 249px; height: 110px;"></p>

<p>회색 칸에 들어있는 부분은 계산결과에 영향을 주지 않음에 주의하라. $y_0$는 계산식에 포함되지 않고, $x_{n-1}$은 곱해지는 $y_n=0$ 이므로 계산 결과에 영향을 주지 않는다. 따라서 예시 수열 $X$와 $Y$에서 $XCorr(1)$은 다음과 같이 계산할 수 있다.</p>

<p style="text-align: center;">\[1\times5+0\times2+0\times0+0\times1=5\]</p>

<p style="text-align: center;">\[XCorr(-1) = x_0y_{-1} + x_1y_0 + \dots + x_{n-1}y_{n-2}\]</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/d0a276cf-34aa-4ae2-a923-13ccb4c81257/-/preview/" style="width: 249px; height: 109px;"></p>

<p>임의의 $t$값의 범위 $(a \le t \le b)$에 대해 $XCorr(t)$를 모두 구해서 더한 값 $S(a,b)$는 다음과 같이 정의된다.</p>

<p style="text-align: center;">\[S(a,b)=\displaystyle\sum_{a \le t \le b}{XCorr(t)}\]</p>

<p>수열 $X$,$Y$와 $t$의 범위 $a$, $b$가 주어졌을 때 $S(a,b)$를 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>표준 입력으로 다음 정보가 주어진다. 첫 번째 줄에는 수열 $X$에서 0이 아닌 정수의 개수 $N$이 주어진다.(수열의 길이 $n$이 아님). 다음 $N$개의 줄에는 수열 $X$의 각 양의 정수 $x_i$에 대해 인덱스 $i$ 와 $x_i$ 값이 인덱스의 오름차순으로 주어진다. 다음 줄부터는 수열 $Y$가 $X$와 동일한 방식으로 주어진다. ($Y$에서 0이 아닌 정수의 개수 $M$이 주어지고 다음 $M$개의 줄에는 수열 $Y$의 각 양의 정수 $y_i$에 대해 인덱스 $i$와 $y_i$ 값이 인덱스의 오름차순으로 주어진다.) 다음 줄에는 $t$의 범위의 최솟값인 정수 $a$가 주어지고, 그 다음 줄에는 $t$의 범위의 최댓값인 정수 $b$ ($a \le b$)가 주어진다. </p>

### 출력 

 <p>표준 출력으로 $S(a,b)=\displaystyle\sum_{a \leq t \leq b}{XCorr(t)}$ 값을 정수로 출력하라.</p>

