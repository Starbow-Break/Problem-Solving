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
#define MAX_N 50'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int N, M;
vector<pii> dataSet;
int year[MAX_N+1], rain[MAX_N+1];
int segTree[1 << 17];

void buildTree(int l, int r, int idx) {
    if(l == r) {
        segTree[idx] = rain[l]; return;
    }
    
    int mid = (l+r)>>1;
    buildTree(l, mid, idx<<1); buildTree(mid+1, r, (idx<<1)|1);
    segTree[idx] = max(segTree[idx<<1], segTree[(idx<<1)|1]);
}

int query(int l, int r, int idx, int i, int j) {
    if(r < i || j < l) return 0;
    
    if(i <= l && r <= j) return segTree[idx];
    
    int mid = (l+r)>>1;
    return max(query(l, mid, idx<<1, i, j), query(mid+1, r, (idx<<1)|1, i, j));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 1; i <= N; i++) {
        int y, r; cin >> y >> r;
        year[i] = y; rain[i] = r;
    }
    
    buildTree(1, N, 1);
    
    cin >> M;
    while(M--) {
        int y, x; cin >> y >> x;
        
        int i = lower_bound(year+1, year+N+1, y)-year;
        int j = lower_bound(year+1, year+N+1, x)-year;
        
        bool cy = i <= N && year[i] == y;
        bool cx = j <= N && year[j] == x;
        
        int t;
        if(cy) t = query(1, N, 1, i+1, j-1);
        else t = query(1, N, 1, i, j-1);
            
        if(!cy && !cx) cout << "maybe";
        else if(cy && cx) {
            if(rain[i] >= rain[j] && t < rain[j]) {
                if(j-i == x-y) cout << "true";
                else cout << "maybe";
            }
            else cout << "false";
        }
        else if(cy) {
            if(rain[i] <= t) cout << "false";
            else cout << "maybe";
        }
        else {
            if(t < rain[j]) cout << "maybe";
            else cout << "false";
        }
        
        cout << '\n';
    }

    return 0;
}