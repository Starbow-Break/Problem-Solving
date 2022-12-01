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
typedef pair<int, int> ii;
typedef pair<double, double> dd;

map<ll, int> mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    while(N--) {
        ll num; cin >> num;
        auto t = mp.find(num);
        if(t == mp.end()) mp.insert({num, 1});
        else (t->second)++;
    }
    
    ll ans; int maxCnt = 0;
    for(auto i = mp.begin(); i != mp.end(); i++) {
        if(maxCnt < i->second) {
            ans = i->first; maxCnt = i->second;
        }
    }
    
    cout << ans;

    return 0;
}
