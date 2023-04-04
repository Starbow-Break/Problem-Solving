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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<pii> pt;
    
    int N; cin >> N;
    while(N--) {
        int x, y; cin >> x >> y;
        pt.push_back({y, x});
    }
    
    sort(pt.begin(), pt.end());
    
    ll ans = 0; int cur = 0;
    for(int i = 0; i < pt.size(); i++) {
        int v = 2'000'000'000;
        if(i > 0 && pt[i].first == pt[i-1].first) {
            v = min(v, pt[i].second-pt[i-1].second);
        }
        if(i < pt.size()-1 && pt[i].first == pt[i+1].first) {
            v = min(v, pt[i+1].second-pt[i].second);
        }
        
        ans += (v == 2'000'000'000 ? 0 : v);
    }
    
    cout << ans;

    return 0;
}