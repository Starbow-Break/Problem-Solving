#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#define MAX_N 100'000
#define MAX_M 100'000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

vector<int> edges[MAX_N+1];
int segTree[1 << 18] = {0, };
int in[MAX_N+1], out[MAX_N+1];

int ord = 0; bool visited[MAX_N+1] = {false, };
void dfs(int cur = 1) {
    ord++; in[cur] = ord;
    visited[cur] = true;
    
    for(auto &next: edges[cur]) {
        if(!visited[next]) dfs(next);
    }
    
    out[cur] = ord;
}

void update(int l, int r, int idx, int i, int w) {
    if(r < i || i < l) return;
    
    if(l == r) {
        segTree[idx] += w; return;
    }
    
    int mid = (l+r) >> 1;
    update(l, mid, idx<<1, i, w); update(mid+1, r, (idx<<1)|1, i, w);
    segTree[idx] = segTree[idx<<1]+segTree[(idx<<1)|1];
}

int query(int l, int r, int idx, int i, int j) {
    if(r < i || j < l) return 0;
    
    if(i <= l && r <= j) return segTree[idx];
    
    int mid = (l+r)>>1;
    return query(l, mid, idx<<1, i, j)+query(mid+1, r, (idx<<1)|1, i, j);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int v; cin >> v;
        if(v != -1) edges[v].push_back(i);
    }
    
    dfs();
    
    while(m--) {
        int q; cin >> q;
        if(q == 1) {
            int i, w; cin >> i >> w;
            update(1, n, 1, in[i], w);
        }
        else {
            int i; cin >> i;
            cout << query(1, n, 1, in[i], out[i]) << '\n';
        }
    }

    return 0;
}