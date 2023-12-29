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

const ll INF = 1e18;

vector<int> edges[100'001];
ll dp_primary[100'001], dp_secondary[100'001];
ll color_primary[100'001], color_secondary[100'001];

void init(int sz) {
    fill(dp_primary+1, dp_primary+sz+1, INF);
    fill(dp_secondary+1, dp_secondary+sz+1, INF);
    fill(color_primary+1, color_primary+sz+1, -1);
    fill(color_secondary+1, color_secondary+sz+1, -1);
}

void dfs(int cur, int bef = -1) {
    bool is_leaf = true;
    map<int, ll> child_info;
    ll pri_sum = 0;
    
    for(auto &next: edges[cur]) {
        if(bef != next) {
            is_leaf = false;
            
            dfs(next, cur);
            pri_sum += dp_primary[next];
            
            auto t = child_info.find(color_primary[next]);
            if(t == child_info.end()) {
                child_info.insert({color_primary[next], dp_secondary[next]-dp_primary[next]});
            }
            else {
                t->second += dp_secondary[next]-dp_primary[next];
            }
        }
    }
    
    if(is_leaf) {
        dp_primary[cur] = 1; color_primary[cur] = 1;
        dp_secondary[cur] = 2, color_secondary[cur] = 2;
    }
    else {
        vector<pii> temp;
        for(auto &[root_color, delta]: child_info) {
            temp.pb({pri_sum+delta+root_color, root_color});
        }
        
        for(int color = 1, cnt = 0; cnt < 2; color++) {
            auto t = child_info.find(color);
            if(t == child_info.end()) {
                cnt++;
                temp.pb({color+pri_sum, color});
            }
        }
        
        sort(all(temp));
        
        dp_primary[cur] = temp[0].fi; color_primary[cur] = temp[0].se;
        dp_secondary[cur] = temp[1].fi; color_secondary[cur] = temp[1].se;
        
        // cout << dp_primary[cur] << ' ' << dp_secondary[cur] << ' ' << cur << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    
    if(N == 1) {
        cout << 1;
        return 0;
    }
    
    for(int i = 1; i <= N-1; i++) {
        int a, b; cin >> a >> b;
        edges[a].pb(b); edges[b].pb(a);
    }
    
    init(N);
    dfs(1);
    
    cout << dp_primary[1];
    
    return 0;
}
