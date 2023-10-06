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

int dp[1500][1500];

int solve(string &s, int l, int r) {
    if(dp[l][r] != -1) return dp[l][r];
    
    if(l > r) {
        dp[l][r] = 0;
        return 0;
    }
    
    int x = (r-l+1)%3;
    char eat;
    if(x == 1) eat = 'D';
    else if(x == 2) eat = 'L';
    else eat = 'B';
    
    if(s[l] == eat && s[r] == eat) {
        dp[l][r] = max(solve(s, l+1, r)+1, solve(s, l, r-1)+1);
    }
    else if(s[l] == eat) {
        dp[l][r] = solve(s, l+1, r)+1;
    }
    else if(s[r] == eat) {
        dp[l][r] = solve(s, l, r-1)+1;
    }
    else {
        dp[l][r] = 0;
    }
    
    return dp[l][r];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    string s; cin >> s;
    
    for(int r = 0; r < 3*N; r++) {
        fill(dp[r], dp[r]+3*N, -1);
    }
    
    cout << solve(s, 0, 3*N-1);
    
    return 0;
}
