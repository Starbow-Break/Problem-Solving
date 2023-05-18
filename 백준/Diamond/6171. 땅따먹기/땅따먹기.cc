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

vector<pii> temp, vec;
ll dp[50001];

bool cmp(pii &a, pii &b) {
    if(a.second != b.second) return a.second > b.second;
    return a.first > b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        int w, h; cin >> w >> h;
        temp.push_back({w, h});
    }
    
    sort(temp.begin(), temp.end(), cmp);
    
    int curW = 0;
    for(auto &p: temp) {
        if(p.first > curW) {
            vec.push_back(p); curW = vec.back().first;
        }
    }
    
    dp[0] = 0;
    deque<pair<pll, int>> dq;
    auto t = dq.begin();
    for(int i = 1; i <= vec.size(); i++) {
        ll a = vec[i-1].second; ll b = dp[i-1];
        
        while(!dq.empty()) {
            ll aa = dq.back().first.first;
            ll bb = dq.back().first.second;
            int pos = dq.back().second;
            
            ll x = ((b-bb)/(aa-a))+((b-bb)%(aa-a) > 0);
            
            if(x > pos) {
                dq.push_back({{a, b}, x});
                break;
            }
            
            if(t == dq.end()-1) t--;
            dq.pop_back();
        }
        if(dq.empty()) {
            dq.push_back({{a, b}, 0});
            t = dq.begin();
        }
        
        while(t != dq.end()-1 && vec[i-1].first >= (t+1)->second) t++;
        
        dp[i] = 1LL*(t->first).first*vec[i-1].first+(t->first).second;
    }
    
    cout << dp[vec.size()];

    return 0;
}