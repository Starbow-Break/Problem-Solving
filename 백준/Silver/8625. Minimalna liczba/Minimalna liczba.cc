#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORIter(v, vec) for(auto &v: vec)
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
    
    ll N, k; cin >> N >> k;
    vector<ll> nums(N);
    
    FOR(i, 0, N) {
        cin >> nums[i];
    }
    
    sort(all(nums));
    
    for(ll ans = k, idx = 0;; ans += k) {
        while(idx < N && nums[idx] < ans) {
            idx++;
        }
        
        if(idx == N || nums[idx] != ans) {
            cout << ans;
            break;
        }
    }
    
    return 0;
}
