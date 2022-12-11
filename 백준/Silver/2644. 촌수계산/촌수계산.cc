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

int parent[101];

int solve(int a, int b) {
    int r1, r2;
    int d1 = 0; int d2 = 0;
    
    int v = a;
    while(v != parent[v]) {
        d1++; v = parent[v];
    }
    r1 = v; v = b;
    while(v != parent[v]) {
        d2++; v = parent[v];
    }
    r2 = v;
    
    if(r1 != r2) return -1;
    
    int ret = 0;
    while(d1 < d2) { ret++; b = parent[b]; d2--; }
    while(d1 > d2) { ret++; a = parent[a]; d1--; }
    
    while(a != b) {
        if(a == b) return ret;
        
        ret += 2;
        a = parent[a]; b = parent[b];
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    int a, b; cin >> a >> b;
    
    for(int i = 1; i <= N; i++) { parent[i] = i; }
    
    int M; cin >> M;
    while(M--) {
        int p, c; cin >> p >> c;
        parent[c] = p;
    }
    
    cout << solve(a, b);

    return 0;
}