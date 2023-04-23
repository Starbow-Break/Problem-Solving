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
#define minV first
#define maxV second

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int parent[1001];
pii interval[1001];
int d[1000];

int findRoot(int v) {
    if(v == parent[v]) return v;
    
    parent[v] = findRoot(parent[v]);
    return parent[v];
}

void merge(int v1, int v2) {
    int r1 = findRoot(v1);
    int r2 = findRoot(v2);
    
    if(r1 > r2) swap(r1, r2);
    parent[r2] = r1;
    interval[r1] = {min(interval[r1].minV, interval[r2].minV), max(interval[r1].maxV, interval[r2].maxV)};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 1; i <= N; i++) { parent[i] = i; interval[i] = {i, i}; }
    for(int i = 1; i < N; i++) cin >> d[i];
    
    int v1, v2, ans = 0; cin >> v1 >> v2;
    while(findRoot(v1) != findRoot(v2)) {
        for(int i = 1; i < N; i++) {
            if(d[i] == 2) {
                d[i] = 0;
                merge(i, i+1);
                
                int r = findRoot(i);
                if(interval[r].minV-1 >= 1) d[interval[r].minV-1]--;
                if(interval[r].maxV < N) d[interval[r].maxV]--;
                
                ans += (interval[r].minV <= v1 && v1 <= interval[r].maxV);
                ans += (interval[r].minV <= v2 && v2 <= interval[r].maxV);
                
                if(findRoot(v1) == findRoot(v2)) break;
            }
        }
    }
    
    cout << ans;

    return 0;
}