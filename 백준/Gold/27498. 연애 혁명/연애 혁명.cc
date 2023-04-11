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
#define MAX_N 10'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

struct edge {
    int a, b, c;
    
    bool operator<(edge &e) {
        return c < e.c;
    }
};

int parent[MAX_N+1];
vector<edge> edges;

int findRoot(int v) {
    if(v == parent[v]) return v;
    
    parent[v] = findRoot(parent[v]);
    return parent[v];
}

bool isSame(int a, int b) {
    return findRoot(a) == findRoot(b);
}

void merge(int a, int b) {
    int ra = findRoot(a); int rb = findRoot(b);
    
    if(ra > rb) swap(ra, rb);
    parent[rb] = ra;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M; int ans = 0;
    for(int i = 1; i <= N; i++) { parent[i] = i; }
    
    while(M--) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        if(d) merge(a, b);
        else { edges.push_back({a, b, -c}); ans += c; }
    }
    
    sort(edges.begin(), edges.end());
    
    for(auto &e: edges) {
        if(!isSame(e.a, e.b)) {
            merge(e.a, e.b); ans += e.c;
        }
    }
    
    cout << ans;

    return 0;
}