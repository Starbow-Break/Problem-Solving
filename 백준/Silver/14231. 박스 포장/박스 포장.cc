#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second << '\n';
    return out;
}

int dp[5000] = {0, };
int sz[5000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> sz[i];
    
    dp[0] = 1;
    for(int i = 1; i < n; i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if(sz[j] < sz[i]) dp[i] = max(dp[i], dp[j]+1);
        }
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++) ans = max(ans, dp[i]);
    cout << ans;

    return 0;
}