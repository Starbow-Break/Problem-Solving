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

struct node {
    int root, size, qNum;
};

int check[250'001] = {0, };
node rt[250'001];
vector<int> edges[250'001];
int parent[250'001];
bool visited[250'001] = {0, };

void dfs(int v = 1) {
    visited[v] = true;
    
    for(auto &next: edges[v]) {
        if(!visited[next]) {
            parent[next] = v;
            dfs(next);
        }
    }
}

int getRoot(int v, int q) {
    int r = (q == rt[v].qNum ? rt[v].root : v);
    
    if(r == v) rt[v].root = v;
    else rt[v].root = getRoot(r, q);
    
    return rt[v].root;
}

int getSize(int v, int q) {
    int r = (q == rt[v].qNum ? getRoot(v, q) : v);
    rt[r].size = (q == rt[r].qNum ? rt[r].size : 1);
    return rt[r].size;
}

void merge(int v1, int v2, int q) {
    int r1 = (q == rt[v1].qNum ? getRoot(v1, q) : v1);
    int r2 = (q == rt[v2].qNum ? getRoot(v2, q) : v2);
    
    if(r1 > r2) swap(r1, r2);
    
    int sz1 = getSize(r1, q); int sz2 = getSize(r2, q);
    rt[r2].root = r1; rt[r2].qNum = q;
    rt[r1].root = r1; rt[r1].size = sz1+sz2; rt[r1].qNum = q;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 1; i < N; i++) {
        int a, b; cin >> a >> b;
        edges[a].push_back(b); edges[b].push_back(a);
    }
    
    parent[1] = -1; dfs();
    
    for(int i = 1; i <= N; i++) { rt[i] = {i, 1, 0}; }
    
    int Q; cin >> Q;
    for(int q = 1; q <= Q; q++) {
        ll ans = 0;
        int K; cin >> K;
        vector<int> s;
        
        while(K--) {
            int v; cin >> v;
            check[v] = q;
            s.push_back(v);
        }
        
        for(auto &v: s) {
            if(parent[v] != -1 && check[parent[v]] == q) {
                int sz = getSize(v, q);
                int szP = getSize(parent[v], q);
                
                //cout << sz << ' ' << szP << '\n';
                
                ans -= 1LL*sz*(sz-1)/2;
                ans -= 1LL*szP*(szP-1)/2;
                ans += 1LL*(sz+szP)*(sz+szP-1)/2;
                
                merge(v, parent[v], q);
            }
        }
        
        cout << ans << '\n';
    }

    return 0;
}