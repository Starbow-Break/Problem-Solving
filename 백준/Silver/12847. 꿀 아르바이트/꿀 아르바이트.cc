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

ll sum[100'001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    sum[0] = 0;
    int n, m; cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
        cin >> sum[i]; sum[i] += sum[i-1];
    }
    
    ll ans = 0;
    for(int i = m; i <= n; i++) {
        ans = max(ans, sum[i]-sum[i-m]);
    }
    
    cout << ans;
    
    return 0;
}