#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORIter(value, vec) for(auto &value: vec)
#define pb push_back 
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define fill(vec, value) fill(all(vec), value);
#define fill2d(vec, value) FOR(subVec, vec) { fill(subVec, value) }
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
    ll candy[300'001] = {0, };
    FOR(i, 1, M+1) {
        cin >> candy[i];
        candy[i] += candy[i-1];
    }
    
    repeat(N) {
        ll v; cin >> v;
        int l = 0, r = M;
        while(l <= r) {
            int mid = (l+r) >> 1;
            
            if(candy[mid] < v) l = mid+1;
            else r = mid-1;
        }
        
        if(l > M) cout << "Go away!";
        else cout << l;
        cout << '\n';
    }
    
    return 0;
}