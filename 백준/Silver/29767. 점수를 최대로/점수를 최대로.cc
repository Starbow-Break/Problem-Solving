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

vector<ll> vec;

int main()
{
    int N, K; cin >> N >> K;
    for(int i = 0; i < N; i++) {
        int v; cin >> v;
        vec.pb(v);
        if(vec.size() > 1) {
            vec[vec.size()-1] += vec[vec.size()-2];
        }
    }
    
    sort(rall(vec));
    
    ll score = 0;
    
    for(int i = 0; i < K; i++) score += vec[i];
    
    cout << score;

    return 0;
}