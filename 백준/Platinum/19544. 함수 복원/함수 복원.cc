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

const int MOD = 1'000'000'007;

int parent[501];
int sz[501];
bool isLeaf[501];
int inOrder[501] = {0, };

int findRoot(int v) {
    if(v == parent[v]) return v;
    parent[v] = findRoot(parent[v]);
    return parent[v];
}

void merge(int a, int b) {
    int ra = findRoot(a);
    int rb = findRoot(b);
    
    if(ra == rb) return;
    
    if(ra > rb); swap(ra, rb);
    parent[rb] = ra;
    sz[ra] += sz[rb];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    vector<string> state(N+1);
    vector<pii> vec;
    
    for(int i = 1; i <= N; i++) {
        parent[i] = i; sz[i] = 1; isLeaf[i] = true;
    }
    
    for(int i = 1; i <= N; i++) {
        string temp = "";
        int cnt = 0;
        for(int j = 1; j <= N; j++) {
            int c; cin >> c;
            cnt += c;
            temp += (char)('0' + c);
        }
        
        vec.pb({cnt, i});
        state[i] = temp;
    }
    
    sort(rall(vec));
    
    for(int i = 1; i < N; i++) {
        for(int j = i-1; j >= 0; j--) {
            if(state[vec[i].se] == state[vec[j].se]) {
                merge(vec[i].se, vec[j].se);
                continue;
            }
            
            bool check = true;
            for(int k = 0; k < N && check; k++) {
                if(state[vec[i].se][k] == '1' && state[vec[j].se][k] == '0') {
                    check = false;
                }
            }
            
            if(check) {
                if(isLeaf[vec[j].se]) {
                    inOrder[vec[i].se]++;
                    isLeaf[vec[j].se] = false;
                }
            }
        }
    }
    
    ll ans = 1;
    for(int i = 1; i <= N; i++) {
        if(isLeaf[i] && findRoot(i) == i && sz[i] > 1) {
            for(int j = 1; j <= sz[i]-1; j++) {
                ans *= j;
                ans %= MOD;
            }
            for(int j = 1; j <= inOrder[i]; j++) {
                ans *= sz[i];
                ans %= MOD;
            }
        }
    }
    
    cout << ans;
    
    return 0;
}