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

vector<pii> vec;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    while(N--) {
        int x, y; cin >> x >> y;
        vec.push_back({x, y});
    }
    
    sort(vec.begin(), vec.end());
    
    stack<int> s; int ans = 0;
    s.push(0);
    
    for(auto &p: vec) {
        int cur = p.second;
        
        while(s.top() > cur) {
            s.pop(); ans++;
        }
        
        if(s.top() != cur) s.push(cur);
    }
    
    while(s.top() > 0) {
        s.pop(); ans++;
    }
    
    cout << ans;

    return 0;
}