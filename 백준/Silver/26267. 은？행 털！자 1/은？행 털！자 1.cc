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
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

map<int, ll> mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    while(N--) {
        int X, T, C; cin >> X >> T >> C;
        auto t = mp.find(X-T);
        
        if(t == mp.end()) mp.insert({X-T, C});
        else t->second += C;
    }
    
    ll ans = 0;
    for(auto &i: mp) {
        ans = max(ans, i.second);
    }
    
    cout << ans;

    return 0;
}