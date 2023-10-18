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

int N, Q; 
vector<int> edges[200001];
bool include_cycle[200001] = {false, };
int parent[200001];

int findRoot(int v) {
    if(v == parent[v]) return v;
    parent[v] = findRoot(parent[v]);
    return parent[v];
}

void merge(int a, int b) {
    int ra = findRoot(a);
    int rb = findRoot(b);
    if(ra > rb) swap(ra, rb);
    parent[rb] = ra;
}

stack<int> stk; bool check = false; int t = -1;
bool visited[200001] = {false, };
bool findCycle(int cur = 1, int bef = -1) {
    stk.push(cur);
    visited[cur] = true;
    for(auto &next: edges[cur]) {
        if(next != bef) {
            if(!visited[next]) {
                if(findCycle(next, cur)) return true;
            }
            else {
                t = next;
                return true;
            }
        }
    }
    
    stk.pop();
    return false;
}

bool _visited[200001] = {false, };
void dfs(int cur, int start) {
    _visited[cur] = true;
    for(auto &next: edges[cur]) {
        if(!_visited[next] && !include_cycle[next]) {
            merge(start, next);
            dfs(next, start);
        }
    }
}

void findTree() {
    for(int i = 1; i <= N; i++) {
        if(include_cycle[i]) dfs(i, i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> Q;
    repeat(N) {
        int u, v; cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    
    for(int i = 1; i <= N; i++) parent[i] = i;
    
    findCycle();
    
    while(true) {
        int cur = stk.top(); stk.pop();
        include_cycle[cur] = true;
        if(cur == t) break;
    }
    
    findTree();
    
    while(Q--) {
        int a, b; cin >> a >> b;
        cout << 1+(findRoot(a) != findRoot(b)) << '\n';
    }
    
    return 0;
}