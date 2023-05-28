#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <iomanip>
#define x first
#define y second

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

vector<pii> _prod, _cons, prod, cons; //생산자, 소비자
int opt[500'000]; ll dp[500'000];

bool cmp1(pii &a, pii &b) {
    if(a.y != b.y) return a.y < b.y;
    return a.x < b.x;
}

bool cmp2(pii &a, pii &b) {
    if(a.y != b.y) return a.y > b.y;
    return a.x > b.x;
}

//분할 정복
void dnc(int l, int r) {
    int mid = (l+r)/2;
    if(dp[mid] >= 0) return;
    
    dp[mid] = 0; opt[mid] = opt[l];
    for(int i = opt[l]; i <= opt[r]; i++) {
        if(prod[mid].x < cons[i].x && prod[mid].y < cons[i].y) {
            if(dp[mid] < 1LL*(cons[i].x-prod[mid].x)*(cons[i].y-prod[mid].y)) {
                dp[mid] = 1LL*(cons[i].x-prod[mid].x)*(cons[i].y-prod[mid].y);
                opt[mid] = i;
            }
        }
        else if(prod[mid].x >= cons[i].x) opt[mid] = i;
    }
    
    dnc(l, mid); dnc(mid, r);
}

void solve() {
    fill(dp, dp+500'000, -1);
    int sz = prod.size();
    
    //opt[0] 구하기
    opt[0] = 0, dp[0] = 0;
    for(int i = 0; i < cons.size(); i++) {
        if(prod[0].x < cons[i].x && prod[0].y < cons[i].y) {
            if(dp[0] < 1LL*(cons[i].x-prod[0].x)*(cons[i].y-prod[0].y)) {
                dp[0] = 1LL*(cons[i].x-prod[0].x)*(cons[i].y-prod[0].y);
                opt[0] = i;
            }
        }
        else if(prod[0].x >= cons[i].x) opt[0] = i;
    }
    
    //opt[sz-1] 구하기
    opt[sz-1] = 0, dp[sz-1] = 0;
    for(int i = 0; i < cons.size(); i++) {
        if(prod[sz-1].x < cons[i].x && prod[sz-1].y < cons[i].y) {
            if(dp[sz-1] < 1LL*(cons[i].x-prod[sz-1].x)*(cons[i].y-prod[sz-1].y)) {
                dp[sz-1] = 1LL*(cons[i].x-prod[sz-1].x)*(cons[i].y-prod[sz-1].y);
                opt[sz-1] = i;
            }
        }
        else if(prod[sz-1].x >= cons[i].x) opt[sz-1] = i;
    }
    
    //분할 정복
    dnc(0, sz-1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int m, n; cin >> m >> n;
    while(m--) {
        int p, d; cin >> p >> d;
        _prod.push_back({p, d});
    }
    while(n--) {
        int q, e; cin >> q >> e;
        _cons.push_back({q, e});
    }
    
    sort(_prod.begin(), _prod.end(), cmp1);
    sort(_cons.begin(), _cons.end(), cmp2);
    
    //답에 영향을 주지 않는 생산자는 전부 제거
    for(auto &p: _prod) {
        if(prod.empty() || prod.back().x > p.x) {
            prod.push_back(p);
        }
    }
    reverse(prod.begin(), prod.end());
    
    //답에 영향을 주지 않는 소비자는 전부 제거
    for(auto &c: _cons) {
        if(cons.empty() || cons.back().x < c.x) {
            cons.push_back(c);
        }
    }
    
    solve();
    
    ll ans = 0;
    for(int i = 0; i < prod.size(); i++) {
        ans = max(ans, dp[i]);
    }
    
    cout << ans;
    
    return 0;
}