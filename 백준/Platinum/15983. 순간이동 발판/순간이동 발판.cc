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

struct edge {
    int f, w;
};

struct cmp {
    bool operator()(pll &A, pll &B) {
        return A.first > B.first;
    }
};

const ll INF = (ll)1e10;

vector<int> pos[101];
vector<edge> edges[101];

int n, e;
int target = -1, tIdx;

int w[101][101];
int meet[101][101];

int period[101];
int arr[1000001][2] = {0, };

ll gcd(ll a, ll b) {
    if(a < b) return gcd(b, a);
    if(b == 1) return 1;
    if(b == 0) return a;
    
    return gcd(b, a%b);
}

int extEuclid(ll a, ll b, ll r1, ll r2) {
    ll g = gcd(a, b); ll r = r2-r1;
    
    if(abs(r)%g) return -1;
    
    if(a < b) {
        int temp = a; a = b; b = temp;
        temp = r1; r1 = r2; r2 = temp;
        r = -r;
    }
    
    ll A = a, x1 = 1, y1 = 0;
    ll B = b, x2 = 0, y2 = 1;
    
    while(B != 0) {
        ll C, x3, y3;
        ll q = A/B;
        C = A%B; x3 = x1-q*x2; y3 = y1-q*y2;
        
        A = B; x1 = x2; y1 = y2;
        B = C; x2 = x3; y2 = y3;
    }
    
    x1 *= r/g; y1 *= r/g;
    if(x1 < 0) {
        ll k = (b-1-x1)/b;
        x1 += k*b; x2 -= k*a;
    }
    if(x1 >= b) {
        ll k = (x1-b)/b;
        x1 -= k*b; x2 += k*a;
    }
    
    return a*x1+r1;
}

ll dijkstra(int s, int f) {
    if(f == -1) return -1;
    
    ll d[101]; fill(d, d+101, INF);
    ll dd[4000]; fill(dd, dd+4000, INF);
    
    priority_queue<pll, vector<pll>, cmp> pq;
    
    d[s] = 0; pq.push({0, s});
    
    while(!pq.empty()) {
        ll curD = pq.top().first; ll cur = pq.top().second; pq.pop();
        if(curD > d[cur]) continue;
        
        for(auto &e: edges[cur]) {
            ll next = e.f; ll w = e.w;
            
            ll l = period[cur]*period[next]/gcd(period[cur],period[next]);
            
            ll v = (curD/l+(curD%l > w))*l+w;
            
            if(next != f && d[next] > v) {
                d[next] = v; pq.push({v, next});
            }
            if(next == f && dd[meet[cur][next]] > v) {
                dd[meet[cur][next]] = v;
            }
        }
    }
    
    ll ret = INF;
    for(int i = 0; i < period[f]; i++) {
        if(dd[i] == INF) continue;
        
        ret = min(ret, dd[i]+(tIdx-i+period[f])%period[f]);
    }
    
    return ((ret == INF) ? -1 : ret);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> e;
    for(int i = 1; i <= n; i++) {
        cin >> period[i];
        for(int j = 0; j < period[i]; j++) {
            int p; cin >> p;
            if(p == e) {target = i; tIdx = j;}
            
            pos[i].push_back(p);
            
            if(arr[p][0] == 0) {
                arr[p][0] = i; arr[p][1] = j;
            }
            else {
                int w = extEuclid(period[arr[p][0]], period[i], arr[p][1], j);
                
                if(w != -1) {
                    meet[arr[p][0]][i] = j; meet[i][arr[p][0]] = arr[p][1];
                    edges[arr[p][0]].push_back({i, w}); edges[i].push_back({arr[p][0], w});
                }
            }
        }
    }
    
    int ans;
    if(target == 1) ans = tIdx;
    else ans = dijkstra(1, target);
    
    cout << ans;

    return 0;
}