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
    bool operator()(pii &A, pii &B) {
        return A.first > B.first;
    }
};

const int INF = 2e9;
const int END = 101;

vector<int> pos[102];
vector<edge> edges[102];

int n, e;
int target, tIdx;

int period[102];
int arr[1000001][2] = {0, };

int gcd(int a, int b) {
    if(a < b) return gcd(b, a);
    if(b == 1) return 1;
    if(b == 0) return a;
    
    return gcd(b, a%b);
}

int extEuclid(int a, int b, int r1, int r2) {
    int g = gcd(a, b); int r = r2-r1;
    
    if(abs(r)%g) return -1;
    
    if(a < b) {
        int temp = a; a = b; b = temp;
        temp = r1; r1 = r2; r2 = temp;
        r = -r;
    }
    
    int A = a; int x1 = 1; int y1 = 0;
    int B = b; int x2 = 0; int y2 = 1;
    
    while(B != 0) {
        int C, x3, y3;
        int q = A/B;
        C = A%B; x3 = x1-q*x2; y3 = y1-q*y2;
        
        A = B; x1 = x2; y1 = y2;
        B = C; x2 = x3; y2 = y3;
    }
    
    x1 *= r/g; y1 *= r/g;
    if(x1 < 0) {
        int k = (b-1-x1)/b;
        x1 += k*b; x2 -= k*a;
    }
    if(x1 >= b) {
        int k = (x1-b)/b;
        x1 -= k*b; x2 += k*a;
    }
    
    return a*x1+r1;
}

int dijkstra(int s, int f) {
    if(f == -1) return -1;
    
    int d[102]; fill(d, d+102, INF);
    
    priority_queue<pii, vector<pii>, cmp> pq;
    
    d[s] = 0; pq.push({0, s});
    
    while(!pq.empty()) {
        int curD = pq.top().first; int cur = pq.top().second; pq.pop();
        if(curD > d[cur]) continue;
        
        if(cur == f) return curD;
        
        for(auto &e: edges[cur]) {
            int next = e.f; int w = e.w;
            
            int l = period[cur]*period[next]/gcd(period[cur],period[next]);
            int v = (curD/l+(curD%l > w))*l+w;
            
            if(d[next] > v) {
                d[next] = v; pq.push({v, next});
            }
        }
    }
    
    return ((d[f] == INF) ? -1 : d[f]);
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
                    edges[arr[p][0]].push_back({i, w});
                    edges[i].push_back({arr[p][0], w});
                }
            }
        }
    }
    
    edges[target].push_back({END, tIdx});
    period[END] = 1;
    
    /*for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << w[i][j] << " ";
        }
        cout << '\n';
    }*/
    
    int ans = dijkstra(1, END);
    
    cout << ans;

    return 0;
}