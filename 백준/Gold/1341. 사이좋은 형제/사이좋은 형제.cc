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

ll arr[60];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    arr[0] = 1;
    for(int i = 1; i < 60; i++) {
        arr[i] = (arr[i-1]+1)*2-1;
    }
    
    ll a, b; cin >> a >> b;
    for(int i = 0; i < 60; i++) {
        if(arr[i]%b == 0) {
            a *= (arr[i]/b);
            vector<bool> ans;
            for(int j = 0; j <= i; j++) {
                ans.pb(a%2); a /= 2;
            }
            reverse(all(ans));
            for(int j = 0; j <= i; j++) {
                cout << (ans[j] ? '*' : '-');
            }
            return 0;
        }
    }
    
    cout << -1;
    
    return 0;
}