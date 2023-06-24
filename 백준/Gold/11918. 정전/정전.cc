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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, L; cin >> N >> L;
    vector<pii> vec;
    while(N--) {
        int v; cin >> v;
        vec.push_back({v-L, 1});
        vec.push_back({v+L, 0});
    }
    
    sort(vec.begin(), vec.end());
    
    ll ans = 0, cnt = 0, idx = 0, bef = -2'100'000'000; bool flag = false;
    while(idx < vec.size()) {
        int cur = vec[idx].first;
        while(idx < vec.size() && vec[idx].first == cur) {
            if(vec[idx].second) cnt++;
            else cnt--;
            idx++;
        }
        
        if(cnt >= 2 && !flag) {
            flag = true; bef = cur;
        }
        if(cnt < 2 && flag) {
            ans += (0LL+cur-bef); flag = false;
        }
    }
    
    cout << ans;

    return 0;
}