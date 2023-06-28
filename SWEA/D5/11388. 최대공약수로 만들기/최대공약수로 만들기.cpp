#include<iostream>

using namespace std;

const int MOD = 1'000'000'007;
int g[1001][1001] = {0, };
int dp[500][1001];

int gcd(int n, int m) {
    if(g[n][m]) return g[n][m];
    if(n < m) return gcd(m, n);
    if(m == 0) return n;
    if(m == 1) return 1;
    return gcd(m, n%m);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
    cin >> T;
    for(int i = 0; i <= 1000; i++) {
        for(int j = 0; j <= 1000; j++) {
            g[i][j] = gcd(i, j);
        }
    }
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cout << '#' << test_case << ' ';
        int N, G; cin >> N >> G;
        int A[N];
        for(int i = 0; i < N; i++) cin >> A[i];
        
        for(int i = 0; i < N; i++) {
       		for(int j = 0; j <= 1000; j++) dp[i][j] = 0;
        }
        dp[0][A[0]] = 1;
        for(int i = 1; i < N; i++) {
            dp[i][A[i]] = 1;
       		for(int j = 1; j <= 1000; j++) {
                dp[i][g[j][A[i]]] += dp[i-1][j];
                dp[i][g[j][A[i]]] %= MOD;
                dp[i][j] += dp[i-1][j];
                dp[i][j] %= MOD;
            }
        }
        cout << dp[N-1][G] << '\n';
	}
	return 0;
}