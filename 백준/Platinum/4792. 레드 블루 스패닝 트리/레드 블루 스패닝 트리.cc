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
#define MAX 1'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

struct edge {
    int a, b, w;
    
    bool operator<(edge &e) {
        return w < e.w;
    }
};

vector<edge> blueOne;
vector<edge> redOne;

int parent[MAX+1]; int cnt = 0;

void init() {
    for(int i = 0; i <= MAX; i++) parent[i] = i;
    cnt = 0;
}

int findRoot(int v) {
    if(v == parent[v]) return v;
    
    parent[v] = findRoot(parent[v]);
    return parent[v];
}

bool sameSet(int v1, int v2) {
    int r1 = findRoot(v1);
    int r2 = findRoot(v2);
    
    return r1 == r2;
}

void unionSet(int v1, int v2) {
    int r1 = findRoot(v1);
    int r2 = findRoot(v2);
    
    if(r1 > r2) parent[r1] = r2;
    else parent[r2] = r1;
}

int solveRed(int n) {
    init();
    
    int ret = 0;
    for(auto &e: redOne) {
        if(cnt == n-1) break;
        if(!sameSet(e.a, e.b)) {
            ret += e.w; unionSet(e.a, e.b);
            cnt++;
        }
    }
    
    return ret;
}

int solveBlue(int n) {
    init();
    
    int ret = 0;
    for(auto &e: blueOne) {
        if(cnt == n-1) break;
        if(!sameSet(e.a, e.b)) {
            ret += e.w; unionSet(e.a, e.b);
            cnt++;
        }
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    while(1) {
        blueOne.clear(); redOne.clear();
        
        int n, m, k; cin >> n >> m >> k;
        if(!n && !m && !k) break;
        
        while(m--) {
            char c; int a, b; cin >> c >> a >> b;
            blueOne.push_back({a, b, c == 'B'});
            redOne.push_back({a, b, c == 'R'});
        }
        
        sort(blueOne.begin(), blueOne.end());
        sort(redOne.begin(), redOne.end());
        
        int maxV = (n-1)-solveRed(n);
        int minV = solveBlue(n);
        
        cout << (minV <= k && k <= maxV) << '\n';
    }

    return 0;
}