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
    
    string s; cin >> s;
    string ans = "";
    
    string t = "UDP";
    
    int cnt[2] = {0, };
    for(auto &c: s) {
        switch(c) {
            case 'U':
            cnt[0]++;
            break;
            case 'D':
            cnt[1]++;
            break;
            case 'P':
            cnt[1]++;
            break;
            case 'C':
            cnt[0]++;
            break;
        }
    }
    
    if(cnt[0] > cnt[1]/2+(cnt[1]%2)) {
        ans += 'U';
    }
    if(cnt[1]) {
        ans += "DP";
    }
    
    cout << (ans == "" ? "C" : ans);
    
    return 0;
}
