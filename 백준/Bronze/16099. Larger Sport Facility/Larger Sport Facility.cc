#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORIter(v, vec) for(auto &v, vec)
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
    
    while(N--) {
        ll wy, hy, wk, hk; cin >> wy >> hy >> wk >> hk;
        if(wy * hy == wk * hk) cout << "Tie";
        else {
            cout << (wy * hy > wk * hk ? "TelecomParisTech" : "Eurecom");
        }
        cout << '\n';
    }
    
    return 0;
}