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

ll dp[11];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    string s; cin >> s;
    
    dp[0] = 0;
    dp[1] = 26;
    for(int i = 2; i <= 10; i++) {
        dp[i] = (dp[i-1]+1)*26;
    }
    
    ll ans = 0; string t;
    for(int i = 0; i < N; i++) {
        int c = s[i]-'a';
        ans += c*(dp[N-i-1]+1);
        
        t += s[i];
        ans++;
        if(t == s) break;
    }
    
    cout << ans;
    
    return 0;
}