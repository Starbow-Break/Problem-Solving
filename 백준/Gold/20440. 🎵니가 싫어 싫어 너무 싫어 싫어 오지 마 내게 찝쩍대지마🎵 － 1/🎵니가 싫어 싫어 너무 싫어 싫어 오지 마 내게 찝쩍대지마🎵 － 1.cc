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

vector<pii> vec;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    while(N--) {
        int a, b; cin >> a >> b;
        vec.push_back({a, 1}); vec.push_back({b, 0});
    }
    
    sort(vec.begin(), vec.end());
    
    int s = 0, e = 0, maxCnt = 0, cnt = 0, idx = 0; bool flag = false;
    while(idx < vec.size()) {
        int t = vec[idx].first;
        if(maxCnt != cnt) flag = false;
        
        if(flag) e = t;
        
        while(idx < vec.size() && t == vec[idx].first) {
            if(vec[idx].second) cnt++;
            else cnt--;
            idx++;
        }
        
        if(maxCnt < cnt) { s = e = t; maxCnt = cnt; flag = true; }
    }
    
    cout << maxCnt << '\n' << s << ' '  << e;

    return 0;
}