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

int dp[100'001];
int sz[100'001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    
    if(N == 3) {
        cout << 2 << '\n';
        cout << 2 << ' ' << 1 << ' ' << 2 << '\n';
        cout << 2 << ' ' << 2 << ' ' << 3 << '\n';
        return 0;
    }
    
    dp[1] = 0; sz[1] = 0;
    dp[2] = 1; sz[2] = 1;
    dp[3] = 2; sz[3] = 2;
    
    for(int i = 4; i <= N; i++) {
        dp[i] = 1e9; sz[i] = 0;
        
        // 조각의 길이
        for(int j = 2; j <= sqrt(i); j++) {
            if(dp[i] > dp[j]+(i/j-(i%j == 0))) {
                dp[i] = dp[j]+(i/j-(i%j == 0));
                sz[i] = j;
            }
        }
        
        //조각 수
        for(int j = 2; j <= sqrt(i); j++) {
            int len = i/j+(i%j > 0);
            if(dp[i] > dp[len]+(i/len-(i%len == 0))) {
                dp[i] = dp[len]+(i/len-(i%len == 0));
                sz[i] = len;
            }
        }
    }
    
    cout << dp[N] << '\n';
    
    int cur = N;
    vector<int> vec; vec.pb(N);
    while(cur > 1) {
        int len = sz[cur];
        
        for(int i = len; i < cur; i += len) {
            int sum = 0;
            vector<int> press;
            for(auto &v: vec) {
                if(v > i) {
                    for(int j = len-1; j >= 0; j--) {
                        press.pb(sum+i-j);
                    }
                }
                sum += v;
            }
            
            cout << press.size() << ' ';
            for(auto &v: press) cout << v << ' ';
            cout << '\n';
        }
        
        cur = sz[cur];
        vector<int> temp;
        for(auto &v: vec) {
            while(v >= len) {
                temp.pb(len);
                v -= len;
            }
            if(v) temp.pb(v);
        }
        vec = temp;
    }
    
    return 0;
}