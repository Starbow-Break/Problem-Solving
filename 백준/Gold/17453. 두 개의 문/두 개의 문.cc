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

bool check[201] = {false, };
vector<int> ans[201];

bitset<100> bs[101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M;
    vector<string> vec;
    
    for(int i = 0; i <= M; i++) {
        string s; cin >> s;
        for(int j = 0; j < N; j++) {
            bs[i][j] = (s[j] == '1');
        }
    }
    
    for(int s = 0; s < 1<<M; s++) {
        bitset<100> b = bs[0];
        for(int j = 1; j <= M; j++) {
            if(s & 1<<(j-1)) {
                b ^= bs[j];
            }
        }
        
        int t = 100;
        for(int i = 0; i < N; i++) {
            t += (b[i] ? 1 : -1);
        }
        
        if(!check[t]) {
            check[t] = true;
            for(int j = 1; j <= M; j++) {
                if(s & 1<<(j-1)) {
                    ans[t].pb(j);
                }
            }
        }
    }
    
    for(int i = 100-N; i <= 100+N; i++) {
        if(check[i]) {
            cout << ans[i].size() << ' ';
            for(auto &v: ans[i]) cout << v << ' ';
        }
        else cout << -1;
        cout << '\n';
    }
    
    return 0;
}
