#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define pb push_back 
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define compress(vec) sort(all(vec)); vec.erase(unique(all(vec)), vec.end());

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using int128 = __int128_t;

const int MOD = 1'000'000'007;

int C[5001][5001] = {0, };
int dp[5001] = {0, };
int parent[5001], cnt;

int findRoot(int v) {
    if(v == parent[v]) return v;
    parent[v] = findRoot(parent[v]);
    return parent[v];
}

void merge(int a, int b) {
    int ra = findRoot(a);
    int rb = findRoot(b);
    
    if(ra == rb) return;
    
    if(ra > rb) swap(ra, rb);
    parent[rb] = ra;
    cnt--;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for(int i = 0; i <= 5000; i++) {
        for(int j = 0; j <= i; j++) {
            if(i == 0 || i == j) C[i][j] = 1;
            else C[i][j] = (C[i-1][j-1]+C[i-1][j])%MOD;
        }
    }
    
    dp[1] = 1;
    for(int i = 2; i <= 5000; i++) {
        dp[i] = 1;
        for(int j = 1; j < i; j++) {
            dp[i] += (1LL*C[i-1][j-1]*dp[i-j])%MOD;
            dp[i] %= MOD;
        }
    }
    
    int N, M; cin >> N >> M;
    cnt = N;
    for(int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    
    while(M--) {
        int a, b; cin >> a >> b;
        merge(a, b);
        cout << dp[cnt] << '\n';
    }
    
    return 0;
}
