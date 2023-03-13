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
#define MAX_N 100'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int parent[MAX_N+1];
ll w[MAX_N+1];

pll findRoot(int v) {
    if(v == parent[v]) return {v, w[v]};
    
    pii ret = findRoot(parent[v]);
    parent[v] = ret.first; w[v] += ret.second;
    
    ret.second = w[v]-w[parent[v]];
    return ret;
}

void unionSet(int a, int b, int d) {
    int r1 = findRoot(a).first; int r2 = findRoot(b).first;
    
    d += w[a]-w[b];
    if(r1 > r2) {swap(r1, r2); d *= -1;}
    parent[r2] = r1; w[r2] += d;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    while(cin >> N >> M) {
        if(!N && !M) break;
        
        for(int i = 0; i <= N; i++) {parent[i] = i; w[i] = 0;}
        
        while(M--) {
            char q; int a, b; cin >> q >> a >> b;
            if(q == '!') {
                int d; cin >> d;
                unionSet(a, b, d);
            }
            else {
                if(findRoot(a).first == findRoot(b).first) cout << w[b]-w[a];
                else cout << "UNKNOWN";
                
                cout << '\n';
            }
        }
    }

    return 0;
}