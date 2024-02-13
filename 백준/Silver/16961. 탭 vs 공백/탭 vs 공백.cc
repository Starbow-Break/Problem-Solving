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
    
    int cntT[367] = {0, }, cntS[367] = {0, };
    int N; cin >> N;
    int ans[5] = {0, };
    while(N--) {
        char c; int s, e; cin >> c >> s >> e;
        ans[4] = max(ans[4], e-s+1);
        if(c == 'T') {
            for(int i = s; i <= e; i++) cntT[i]++;
        } else {
            for(int i = s; i <= e; i++) cntS[i]++;
        }
    }
    
    for(int i = 1; i <= 366; i++) {
        ans[0] += (cntT[i] || cntS[i]);
        ans[1] = max(ans[1], cntT[i] + cntS[i]);
        ans[2] += ((cntT[i] == cntS[i]) && cntT[i]);
        ans[3] = max(ans[3], ((cntT[i] == cntS[i]) && cntT[i])*(cntT[i] + cntS[i]));
    }
    
    for(int i = 0; i <= 4; i++) cout << ans[i] << '\n';
    
    return 0;
}