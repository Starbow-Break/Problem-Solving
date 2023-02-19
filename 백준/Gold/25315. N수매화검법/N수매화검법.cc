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
#define MAX_N 2500

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

bool meet[MAX_N+1][MAX_N+1] = {false, };
int w[MAX_N+1]; ll tw[MAX_N+1] = {0, };
pair<pii, pii> line[MAX_N+1];

const ll INF = 1'000'000'001;

ll ccw(pii a, pii b) {
    return 1LL*a.first*b.second-1LL*a.second*b.first;
}

bool areMeet(int a, int b) {
    pii a1 = line[a].first; pii a2 = line[a].second;
    pii b1 = line[b].first; pii b2 = line[b].second;
    
    ll c0 = ccw({b1.first-a1.first, b1.second-a1.second}, 
        {b2.first-a1.first, b2.second-a1.second});
    ll c1 = ccw({b1.first-a2.first, b1.second-a2.second}, 
        {b2.first-a2.first, b2.second-a2.second});
    ll c2 = ccw({a1.first-b1.first, a1.second-b1.second}, 
        {a2.first-b1.first, a2.second-b1.second});
    ll c3 = ccw({a1.first-b2.first, a1.second-b2.second}, 
        {a2.first-b2.first, a2.second-b2.second});
        
    if(c0) c0 /= abs(c0); if(c1) c1 /= abs(c1);
    if(c2) c2 /= abs(c2); if(c3) c3 /= abs(c3);
        
    return c0*c1 < 0 && c2*c3 < 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        int x1, y1, x2, y2, ww; cin >> x1 >> y1 >> x2 >> y2 >> ww;
        line[i] = {{x1, y1}, {x2, y2}}; w[i] = ww; tw[i] = ww;
    }
    
    for(int i = 1; i <= N; i++) {
        for(int j = i+1; j <= N; j++) {
            if(areMeet(i, j)) {
                meet[i][j] = true; meet[j][i] = true;
                tw[i] += w[i]; tw[j] += w[j]; 
            }
        }
    }
    
    ll ans = 0; int cnt = 0;
    while(cnt < N) {
        int idx = 1;
        for(int i = 2; i <= N; i++) {
            if(w[idx] > w[i]) idx = i;
        }
        
        ans += tw[idx]; w[idx] = INF;
        for(int i = 1; i <= N; i++) {
            if(meet[i][idx]) {
                meet[i][idx] = false; meet[idx][i] = false;
                tw[i] -= w[i];
            }
        }
        
        cnt++;
    }
    
    cout << ans;

    return 0;
}