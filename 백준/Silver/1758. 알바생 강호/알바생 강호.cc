#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<int> tip;
    
    int N; cin >> N;
    while(N--) {
        int v; cin >> v;
        tip.push_back(v);
    }
    
    sort(tip.rbegin(), tip.rend());
    
    ll ans = 0;
    for(int i = 0; i < tip.size(); i++) {
        if(tip[i]-i > 0) ans += tip[i]-i;
    }
    
    cout << ans;

    return 0;
}