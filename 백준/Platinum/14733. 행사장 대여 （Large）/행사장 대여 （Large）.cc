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

struct node {
    int y, x1, x2; bool isAdd;
    
    bool operator<(node &n) {
        return y < n.y;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int delta[200'001] = {0, }; int offset = 100'000;
    int N; cin >> N;
    
    vector<node> nodes;
    while(N--) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        nodes.pb({y1, x1, x2, true});
        nodes.pb({y2, x1, x2, false});
    }
    
    sort(all(nodes));
    
    // y축을 다라 스위핑
    int idx = 0; ll ans = 0;
    while(idx < nodes.size()) {
        int curY = nodes[idx].y;
        while(idx < nodes.size() && nodes[idx].y == curY) {
            if(nodes[idx].isAdd) {
                delta[nodes[idx].x1+offset]++;
                delta[nodes[idx].x2+offset]--;
            }
            else {
                delta[nodes[idx].x1+offset]--;
                delta[nodes[idx].x2+offset]++;
            }
            idx++;
        }
        
        // x축을 따라 스위핑
        int len = 0, weight = 0;
        for(int x = -100'000; x <= 100'000; x++) {
            weight += delta[x+offset];
            if(weight > 0) len++;
        }
        
        if(len > 0) {
            int nextY = nodes[idx].y;
            ans += 1LL*len*(nextY-curY);
        }
    }
    
    cout << ans;
    
    return 0;
}