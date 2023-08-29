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
    
    ll k; cin >> k;
    vector<int> vec;
    
    while(k > 0) {
        vec.pb(k%10);
        k /= 10;
    }
    
    for(int i = 2; i < vec.size(); i++) {
        if(vec[i]-vec[i-1] != vec[i-1]-vec[i-2]) {
            cout << "흥칫뿡!! <(￣ ﹌ ￣)>" << '\n';
            return 0;
        }
    }
    
    cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
    
    return 0;
}