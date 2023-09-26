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
    
    int N; cin >> N;
    vector<int> h;
    repeat(N) {
        int v; cin >> v;
        h.pb(v);
    }
    sort(all(h));
    
    int ans = 2e9;
    for(int k = 1; k < N; k++) {
        for(int l = 0; l < k; l++) {
            int sum = h[l]+h[k];
            int cur = 2e9;
            int i = 0, j = N-1;
            while(i < j) {
                if(i == l || i == k) { i++; continue; }
                if(j == l || j == k) { j--; continue; }
                cur = min(cur, abs(sum-(h[i]+h[j])));
                if(h[i]+h[j] < sum) i++;
                else j--;
            }
            ans = min(ans, cur);
        }
    }
    
    cout << ans;
    
    return 0;
}
