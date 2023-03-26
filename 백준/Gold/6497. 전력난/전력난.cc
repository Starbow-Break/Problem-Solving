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
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

struct edge {
    int x, y, z;
    
    bool operator<(edge &e) {
        return z < e.z;
    }
};

int parent[200'000];
vector<edge> edges;

void init(int m) {
    for(int i = 0; i < m; i++) parent[i] = i;
    edges.clear();
}

int findRoot(int v) {
    if(v == parent[v]) return v;
    
    parent[v] = findRoot(parent[v]);
    return parent[v];
}

void unionSet(int a, int b) {
    int ra = findRoot(a), rb = findRoot(b);
    
    if(ra > rb) swap(ra, rb);
    parent[rb] = ra;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int m, n;
    while(cin >> m >> n) {
        if(!m && !n) break;
        
        init(m);
        
        int ans = 0;
        
        while(n--) {
            int x, y, z; cin >> x >> y >> z;
            edges.push_back({x, y, z});
            ans += z;
        }
        
        sort(edges.begin(), edges.end());
        
        int cnt = 0;
        for(auto &e: edges) {
            if(cnt == m-1) break;
            
            if(findRoot(e.x) != findRoot(e.y)) {
                ans -= e.z;
                unionSet(e.x, e.y);
                cnt++;
            }
        }
        
        cout << ans << '\n';
    }

    return 0;
}