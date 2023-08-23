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

vector<pii> roads;
bool used[2500] = {false, };
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
    
    int N, M; cin >> N >> M;
    char arr[50][50];
    for(int i = 0; i < N; i++) cin >> arr[i];
    
    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            if(arr[i][j] == 'Y') roads.pb({i, j});
        }
    }
    
    sort(roads.begin(), roads.end());
    
    vector<pii> ans;
    for(int i = 0; i < N; i++) parent[i] = i;
    
    int cnt = 0, idx = 0;
    while(cnt < N-1 && idx < roads.size()) {
        if(findRoot(roads[idx].fi) != findRoot(roads[idx].se)) {
            cnt++;
            used[idx] = true;
            ans.pb(roads[idx]);
            merge(roads[idx].fi, roads[idx].se);
        }
        idx++;
    }
    
    if(cnt != N-1) {
        cout << -1;
        return 0;
    }
    
    for(int i = 0; i < roads.size() && cnt < M; i++) {
        if(!used[i]) {ans.pb(roads[i]); cnt++;}
    }
    
    if(cnt != M) {
        cout << -1;
        return 0;
    }

    int order[51] = {0, };
    for(auto &r: ans) {
        order[r.fi]++;
        order[r.se]++;
    }
    
    for(int i = 0; i < N; i++) cout << order[i] << ' ';
    
    return 0;
}
