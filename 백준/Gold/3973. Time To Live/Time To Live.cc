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

int N;
vector<int> edges[100'000];
int maxL[100'000], maxR[100'000];
int numChild[100'000] = {0, };

void dfs(int cur, int bef = -1) {
    bool isLeaf = true;
    
    int m1 = 0, m2 = 0;
    for(auto &next: edges[cur]) {
        if(next != bef) {
            isLeaf = false;
            numChild[cur]++;
            dfs(next, cur);
            
            if(m1 < maxL[next] + 1) {
                m2 = m1;
                m1 = maxL[next] + 1;
            }
            else if(m2 < maxL[next] + 1) {
                m2 = maxL[next] + 1;
            }
        }
    }
    
    if(isLeaf) {
        maxR[cur] = maxL[cur] = 0;
    }
    else {
        maxL[cur] = m1;
        
        if(numChild[cur] == 1) {
            maxR[cur] = m1;
        }
        else {
            maxR[cur] = m1 + m2;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int c; cin >> c;
    while(c--) {
        cin >> N;
        
        for(int i = 0; i < N; i++) edges[i].clear();
        
        for(int i = 0; i < N-1; i++) {
            int p, q; cin >> p >> q;
            edges[p].pb(q); edges[q].pb(p);
        }
        
        for(int i = 0; i < N; i++) {
            maxR[i] = 0; maxL[i] = 0; numChild[i] = 0;
        }
        
        dfs(0);
        
        int ans = 0;
        for(int i = 0; i < N; i++) {
            if(i == 0 || numChild[i] >= 2) {
                ans = max(ans, maxR[i]);
            }
        }
        
        cout << (ans+1)/2 << '\n';
    }
    
    return 0;
}
