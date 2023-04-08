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
#define INF 1'000'000'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

struct node {
    int minV, maxV, lazy;
};

node segTree[1 << 24];

void initTree() {
    for(int i = 1; i < (1<<24); i++) segTree[i] = {0, 0, 0};
}

void propagate(int l, int r, int idx) {
    int lazy = segTree[idx].lazy;
    
    if(l != r) {
        segTree[idx<<1].lazy += lazy;
        segTree[idx<<1|1].lazy += lazy;
    }
    
    segTree[idx].maxV += lazy; segTree[idx].minV += lazy;
    segTree[idx].lazy = 0;
}

node merge(node &l, node &r) {
    return {min(l.minV, r.minV), max(l.maxV, r.maxV), 0};
}

void update(int l, int r, int idx, int a, int b, int del) {
    propagate(l, r, idx);
    
    if(r < a || b < l) return;
    
    if(a <= l && r <= b) {
        segTree[idx].lazy += del;
        propagate(l, r, idx);
        return;
    }
    
    int mid = (l+r)>>1;
    update(l, mid, idx<<1, a, b, del); update(mid+1, r, idx<<1|1, a, b, del);
    segTree[idx] = merge(segTree[idx<<1], segTree[idx<<1|1]);
}

int minQuery(int l, int r, int idx, int a, int b) {
    propagate(l, r, idx);
    
    if(r < a || b < l) return INF;
    
    if(a <= l && r <= b) return segTree[idx].minV;
    
    int mid = (l+r)>>1;
    return min(minQuery(l, mid, idx<<1, a, b), minQuery(mid+1, r, idx<<1|1, a, b));
}

int maxQuery(int l, int r, int idx, int a, int b) {
    propagate(l, r, idx);
    
    if(r < a || b < l) return 0;
    
    if(a <= l && r <= b) return segTree[idx].maxV;
    
    int mid = (l+r)>>1;
    return max(maxQuery(l, mid, idx<<1, a, b), maxQuery(mid+1, r, idx<<1|1, a, b));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int C, N, O; cin >> C >> N >> O;
    
    initTree();
    
    while(O--) {
        string q; cin >> q;
        
        if(q == "change") {
            int x, s; cin >> x >> s;
            
            int del;
            if(s > 0) del = min(s, N-maxQuery(0, C-1, 1, x, x));
            else del = max(s, -minQuery(0, C-1, 1, x, x));
            
            cout << del << '\n'; update(0, C-1, 1, x, x, del);
        }
        else if(q == "groupchange") {
            int a, b, s; cin >> a >> b >> s;
            
            int del;
            if(s > 0) del = min(s, N-maxQuery(0, C-1, 1, a, b));
            else del = max(s, -minQuery(0, C-1, 1, a, b));
            
            cout << del << '\n'; update(0, C-1, 1, a, b, del);
        }
        else {
            int x; cin >> x;
            cout << maxQuery(0, C-1, 1, x, x) << '\n';
        }
    }

    return 0;
}