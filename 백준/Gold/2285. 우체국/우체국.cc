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

map<int, ll> mp; ll cur = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    while(N--) {
        int x; ll a; cin >> x >> a;
        cur -= a;
        
        auto t = mp.find(x);
        if(t == mp.end()) {
            mp.insert({x, a});
        }
        else {
            t->second += a;
        }
    }
    
    for(auto t = mp.begin(); t != mp.end(); t++) {
        cur += 2*(t->second);
        
        if(cur >= 0) { cout << (t->first); break; }
    }

    return 0;
}