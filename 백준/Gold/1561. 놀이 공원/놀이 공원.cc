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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M;
    
    vector<int> vec;
    repeat(M) {
        int v; cin >> v;
        vec.pb(v);
    }
    
    ll i = 0, j = 8e14;
    while(i <= j) {
        ll mid = i+j >> 1;
        ll cnt = 0;
        for(auto &t: vec) {
            cnt += mid/t+1;
        }
        
        if(cnt >= N) j = mid-1;
        else i = mid+1;
    }
    
    vector<int> ans;
    for(int k = 1; k <= M; k++) {
        if(i%vec[k-1] == 0) {
            ans.pb(k);
        }
    }
    
    ll sum = 0;
    for(int k = 1; k <= M; k++) {
        sum += i/vec[k-1]+1;
    }
    
    while(sum > N) {
        sum--;
        ans.erase(ans.end()-1);
    }
    
    cout << ans.back();
    
    return 0;
}
