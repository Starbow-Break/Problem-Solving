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
    
    int N, M, L; cin >> N >> M >> L;
    vector<int> vec;
    repeat(N) {
        int pos; cin >> pos;
        vec.pb(pos);
    }
    vec.pb(0);
    vec.pb(L);
    
    sort(all(vec));
    
    int i = 1, j = L;
    while(i <= j) {
        int mid = i+j >> 1;
        int cur = 0;
        FOR(i, 1, vec.size()) {
            cur += (vec[i]-vec[i-1]-1)/mid;
        }
        
        if(cur > M) i = mid+1;
        else j = mid-1;
    }
    
    cout << i;
    
    return 0;
}