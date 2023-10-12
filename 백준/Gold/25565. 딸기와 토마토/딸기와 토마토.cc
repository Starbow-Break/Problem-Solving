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

struct area {
    pii start, finish;
};

int arr[2001][2001];
int cnt[2001][2001] = {0, };
vector<area> areas;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M, K; cin >> N >> M >> K;
    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= M; c++) cin >> arr[r][c];
    }
    
    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= M; c++) {
            if(r+K-1 <= N && arr[r][c] && arr[r+K-1][c]) {
                areas.pb({{r, c}, {r+K-1, c}});
            }
            if(K > 1 && c+K-1 <= M && arr[r][c] && arr[r][c+K-1]) {
                areas.pb({{r, c}, {r, c+K-1}});
            }
        }
    }
    
    if(areas.size() == 1) areas.pb(areas[0]);
    else if(areas.size() >= 3) areas.clear();
    
    for(auto &a: areas) {
        pii s = a.start, f = a.finish;
        if(s.fi == f.fi) {
            for(int i = s.se; i <= f.se; i++) cnt[s.fi][i]++;
        }
        else if(s.se == f.se) {
            for(int i = s.fi; i <= f.fi; i++) cnt[i][s.se]++;
        }
    }
    
    vector<pii> ans;
    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= M; c++) {
            if(cnt[r][c] == 2) ans.pb({r, c});
        }
    }
    
    cout << ans.size() << '\n';
    for(auto &a: ans) cout << a.fi << ' ' << a.se << '\n';
    
    return 0;
}
