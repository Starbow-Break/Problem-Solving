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

struct edge {
    int a, b, l;
    
    bool operator<(edge &e) {
        return l < e.l;
    }
};

vector<edge> edges;
int parent[50];

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    int total = 0;
    FOR(r, 0, N) {
        parent[r] = r;
        string s; cin >> s;
        FOR(c, 0, N) {
            if('a' <= s[c] && s[c] <= 'z') {
                edges.pb({r, c, s[c]-'a'+1});
                total += s[c]-'a'+1;
            }
            else if('A' <= s[c] && s[c] <= 'Z') {
                edges.pb({r, c, s[c]-'A'+27});
                total += s[c]-'A'+27;
            }
        }
    }
    
    sort(edges.begin(), edges.end());
    
    int cnt = 0, idx = 0, len = 0;
    while(cnt < N-1 && idx < edges.size()) {
        if(findRoot(edges[idx].a) == findRoot(edges[idx].b)) {
            idx++;
            continue;
        }
        merge(edges[idx].a, edges[idx].b);
        cnt++;
        len += edges[idx].l;
        idx++;
    }
    
    cout << (cnt < N-1 ? -1 : total-len);
    
    return 0;
}
