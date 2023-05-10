# [Diamond V] LCM(i, j) - 11691 

[문제 링크](https://www.acmicpc.net/problem/11691) 

### 성능 요약

메모리: 7800 KB, 시간: 56 ms

### 분류

수학, 뫼비우스 반전 공식, 정수론

### 문제 설명

<p>재현이는 다음과 같은 소스를 작성했다.</p>

<pre class="brush:c++; toolbar:false;">long long mod = 1000000007;
long long all_pair_lcm(int n) {
    long long ans = 0;
    for (int i=1; i<=n-1; i++) {
        for (int j=i+1; j<=n; j++) {
            ans += lcm(i, j);
            ans %= mod;
        }
    }
    return ans;
}
</pre>

<p>n이 큰 경우에 위의 소스를 그대로 실행하면 시간초과가 난다.</p>

<p>n이 주어졌을 때, <code>all_pair_lcm(n)</code>을 리턴값을 출력하는 프로그램을 작성하시오.</p>

<p><code>lcm(i, j)</code>는 i와 j의 최소공배수를 구하는 함수이다.</p>

### 입력 

 <p>첫째 줄에 n이 주어진다. (1 ≤ n ≤ 10<sup>6</sup>)</p>

### 출력 

 <p>첫째 줄에 <code>all_pair_lcm(n)</code>을 리턴값을 출력한다.</p>

