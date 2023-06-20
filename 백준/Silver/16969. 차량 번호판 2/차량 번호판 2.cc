#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <map>
#include <cmath>
#include <iomanip>
#define MOD 1'000'000'009

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second;
    return out;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll ans = 1;
    string s; cin >> s;
    
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'c') {
            ans *= (i > 0 && s[i-1] == 'c' ? 25 : 26);
            ans %= MOD;
        }
        else {
            ans *= (i > 0 && s[i-1] == 'd' ? 9 : 10);
            ans %= MOD;
        }
    }
    
    cout << ans;
    
    return 0;
}