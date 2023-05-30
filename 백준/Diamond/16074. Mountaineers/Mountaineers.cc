#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <map>
#include <cmath>
#include <iomanip>

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second;
    return out;
}

int parent[250'001], lo[100'001], hi[100'001], height[501][501];
pii queries[100'001];
vector<int> pos[1'000'001], mlist[1'000'001];

void init() {
    for(int i = 1; i <= 250'000; i++) parent[i] = i;
}

int findRoot(int v) {
    if(v == parent[v]) return v;
    
    parent[v] = findRoot(parent[v]);
    return parent[v];
}

void merge(int a, int b) {
    int ra = findRoot(a), rb = findRoot(b);
    if(ra > rb) swap(ra, rb);
    parent[rb] = ra;
}

bool sameSet(int a, int b) {
    return findRoot(a) == findRoot(b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m, q; cin >> n >> m >> q;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> height[i][j];
            pos[height[i][j]].push_back(m*(i-1)+j);
        }
    }
    
    for(int i = 1; i <= q; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        queries[i] = {m*(x1-1)+y1, m*(x2-1)+y2};
    }
    
    for(int i = 1; i <= q; i++) { lo[i] = 1; hi[i] = 1'000'000; }
    
    while(1) {
        bool flag = false;
        init();
        
        for(int i = 1; i <= q; i++) {
            if(lo[i] <= hi[i]) mlist[(lo[i]+hi[i])/2].push_back(i);
        }
        
        for(int mid = 1; mid <= 1'000'000; mid++) {
            for(auto &v: pos[mid]) {
                int r = (v-1)/m+1, c = (v-1)%m+1;
                if(r > 1 && height[r-1][c] <= mid) merge(v, v-m);
                if(r < n && height[r+1][c] <= mid) merge(v, v+m);
                if(c > 1 && height[r][c-1] <= mid) merge(v, v-1);
                if(c < m && height[r][c+1] <= mid) merge(v, v+1);
            }
            
            if(!mlist[mid].empty()) {
                flag = true;
                
                for(auto &i: mlist[mid]) {
                    if(sameSet(queries[i].first, queries[i].second)) hi[i] = mid-1;
                    else lo[i] = mid+1;
                }
            }
        }
        
        for(int i = 1; i <= 1'000'000; i++) mlist[i].clear();
        if(!flag) break;
    }
    
    for(int i = 1; i <= q; i++) {
        int x = queries[i].first;
        cout << (x == queries[i].second ? height[(x-1)/m+1][(x-1)%m+1] : lo[i]) << '\n';
    }

    return 0;
}