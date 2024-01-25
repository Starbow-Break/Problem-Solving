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

int A[100'001];
vector<int> edges[100'001];
int cnt[100'001] = {0, };
int cntm[100'001] = {0, };

ll ans = 0;

void dfs(int cur) {
    int a = A[cur];
    ans += cntm[a];
    for(int i = 1; i <= sqrt(a); i++) {
        if(a%i == 0) {
            ans += cnt[i];
            if(i != a/i) ans += cnt[a/i];
        }
    }
    ans -= cnt[a];
    
    cnt[a]++;
    for(int i = 1; i <= sqrt(a); i++) {
        if(a%i == 0) {
            cntm[i]++;
            if(i != a/i) cntm[a/i]++;
        }
    }
    
    for(auto &c: edges[cur]) {
        dfs(c);
    }
    
    cnt[a]--;
    for(int i = 1; i <= sqrt(a); i++) {
        if(a%i == 0) {
            cntm[i]--;
            if(i != a/i) cntm[a/i]--;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 1; i <= N; i++) cin >> A[i];
    
    for(int i = 2; i <= N; i++) {
        int v; cin >> v;
        edges[v].pb(i);
    }
    
    dfs(1);
    
    cout << ans;
    
    return 0;
}
