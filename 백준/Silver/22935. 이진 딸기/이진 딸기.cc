#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define push_back pb
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
    
    int T; cin >> T;
    while(T--) {
        int v; cin >> v;
        int r = (v%28 ? v%28 : 28);
        if(r >= 15) r = 30-r;
        
        cout << (r/8 ? "딸기" : "V");
        r %= 8;
        cout << (r/4 ? "딸기" : "V");
        r %= 4;
        cout << (r/2 ? "딸기" : "V");
        r %= 2;
        cout << (r ? "딸기" : "V");
        cout << '\n';
    }
    
    return 0;
}