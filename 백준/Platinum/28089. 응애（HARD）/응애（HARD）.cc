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

const int MAX_N = 2'000'000;

bool bit[MAX_N] = {false, };
bool temp[MAX_N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; ll K; cin >> N >> M >> K;
    while(M--) {
        int v; cin >> v;
        bit[v] = true;
    }
    
    ll w = 1;
    while(K) {
        if(K & 1) {
            int t = w % N;
            int i = t;
            int j = (N - t) % N;
            
            for(int k = 0; k < N; k++) {
                temp[k] = bit[i] ^ bit[j];
                i = (i+1) % N;
                j = (j+1) % N;
            }
            
            for(int k = 0; k < N; k++) {
                bit[k] = temp[k];
            }
        }
        
        K >>= 1;
        w <<= 1;
    }
    
    int ans = 0;
    for(int i = 0; i < N; i++) {
        ans += bit[i];
    }
    
    cout << ans;
    
    return 0;
}
