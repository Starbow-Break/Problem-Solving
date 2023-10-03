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

ll target[9] = {
    0, 0x1, 0x12, 0x123, 0x1234, 
    0x12345, 0x123456, 0x1234567, 0x12345678
};

int solve(ll start, int sz, int k) {
    set<ll> visited;
    queue<pll> q;
    q.push({start, 0}); visited.insert(start);
    
    while(!q.empty()) {
        ll cur = q.front().fi;
        int t = q.front().se;
        q.pop();
        
        if(cur == target[sz]) return t;
        
        int arr[sz];
        for(int i = sz-1; i >= 0; i--) {
            arr[i] = cur%16;
            cur /= 16;
        }
        
        for(int i = 0; i <= sz-k; i++) {
            ll nxt = 0;
            for(int j = 0; j < sz; j++) {
                if(i <= j && j < i+k) {
                    nxt = nxt*16+arr[2*i+k-1-j];
                }
                else nxt = nxt*16+arr[j];
            }
            
            if(visited.find(nxt) == visited.end()) {
                visited.insert(nxt);
                q.push({nxt, t+1});
            }
        }
    }
    
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, K; cin >> N >> K;
    ll cur = 0;
    for(int i = 0; i < N; i++) {
        int v; cin >> v;
        cur = 16*cur+v;
    }
    
    cout << solve(cur, N, K);
    
    return 0;
}
