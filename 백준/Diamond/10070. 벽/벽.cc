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

const int INF = 1000000000;

struct node {
    int minH, maxH;
    int minLazy, maxLazy;
};

node segTree[1 << 22];

void init() {
    for(int i = 1; i < (1<<22); i++) {
        segTree[i] = {0, 0, -1, INF};
    }
}

void propagate(int i, int j, int idx) {
    if(i != j) {
        segTree[idx<<1].minLazy = max(segTree[idx].minLazy, segTree[idx<<1].minLazy);
        segTree[idx<<1].maxLazy = min(segTree[idx].maxLazy, segTree[idx<<1].maxLazy);
        segTree[(idx<<1)|1].minLazy 
            = max(segTree[idx].minLazy, segTree[(idx<<1)|1].minLazy);
        segTree[(idx<<1)|1].maxLazy 
            = min(segTree[idx].maxLazy, segTree[(idx<<1)|1].maxLazy);
            
        if(segTree[idx<<1].minLazy > segTree[idx<<1].maxLazy) {
            if(segTree[idx<<1].maxLazy < segTree[idx].minLazy) {
                segTree[idx<<1].maxLazy = segTree[idx<<1].minLazy;
            }
            if(segTree[idx<<1].minLazy > segTree[idx].maxLazy) {
                segTree[idx<<1].minLazy = segTree[idx<<1].maxLazy;
            }
        }
        if(segTree[(idx<<1)|1].minLazy > segTree[(idx<<1)|1].maxLazy) {
            if(segTree[(idx<<1)|1].maxLazy < segTree[idx].minLazy) {
                segTree[(idx<<1)|1].maxLazy = segTree[(idx<<1)|1].minLazy;
            }
            if(segTree[(idx<<1)|1].minLazy > segTree[idx].maxLazy) {
                segTree[(idx<<1)|1].minLazy = segTree[(idx<<1)|1].maxLazy;
            }
        }
    }
    
    segTree[idx].minH = max(segTree[idx].minH, segTree[idx].minLazy);
    segTree[idx].maxH = min(segTree[idx].maxH, segTree[idx].maxLazy);

    if(segTree[idx].minH > segTree[idx].maxH) {
        if(segTree[idx].maxLazy < segTree[idx].minH) {
            segTree[idx].minH = segTree[idx].maxH;
        }
        if(segTree[idx].minLazy > segTree[idx].maxH) {
            segTree[idx].maxH = segTree[idx].minH;
        }
    }
    
    segTree[idx].minLazy = -1; segTree[idx].maxLazy = INF;
}

node merge(int a, int b) {
    return {min(segTree[a].minH, segTree[b].minH), 
        max(segTree[a].maxH, segTree[b].maxH), 
        -1, INF};
}

void addQuery(int i, int j, int idx, int l, int r, int h) {
    propagate(i, j, idx);
    
    if(j < l || r < i) return;
    
    if(l <= i && j <= r) {
        if(segTree[idx].minLazy == -1) { segTree[idx].minLazy = h; }
        else { segTree[idx].minLazy = max(segTree[idx].minLazy, h); }
        
        if(segTree[idx].maxLazy != -1
            && segTree[idx].minLazy > segTree[idx].maxLazy) {
            
            segTree[idx].maxLazy = segTree[idx].minLazy;
        }
        
        propagate(i, j, idx);
        
        return;
    }
    
    int mid = (i+j)>>1;
    addQuery(i, mid, idx<<1, l, r, h); addQuery(mid+1, j, (idx<<1)|1, l, r, h);
    segTree[idx] = merge(idx<<1, (idx<<1)|1);
}

void removeQuery(int i, int j, int idx, int l, int r, int h) {
    propagate(i, j, idx);
    
    if(j < l || r < i) return;
    
    if(l <= i && j <= r) {
        if(segTree[idx].maxLazy == -1) { segTree[idx].maxLazy = h; }
        else { segTree[idx].maxLazy = min(segTree[idx].maxLazy, h); }
        
        if(segTree[idx].minLazy != -1
            && segTree[idx].minLazy > segTree[idx].maxLazy) {
            
            segTree[idx].minLazy = segTree[idx].maxLazy;
        }
        
        propagate(i, j, idx);
        
        return;
    }
    
    int mid = (i+j)>>1;
    removeQuery(i, mid, idx<<1, l, r, h); removeQuery(mid+1, j, (idx<<1)|1, l, r, h);
    segTree[idx] = merge(idx<<1, (idx<<1)|1);
}

int getHeight(int i, int j, int idx, int t) {
    propagate(i, j, idx);
    
    if(j < t || t < i) return -1;
    
    if(i == j) return segTree[idx].minH;
    
    int mid = (i+j)>>1;
    int a = getHeight(i, mid, idx<<1, t);
    int b = getHeight(mid+1, j, (idx<<1)|1, t);
    return max(a, b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    init();
    
    int n, k; cin >> n >> k;
    while(k--) {
        int op; cin >> op;
        
        int left, right, height;
        if(op == 1) {
            cin >> left >> right >> height;
            addQuery(0, n-1, 1, left, right, height);
        }
        else {
            cin >> left >> right >> height;
            removeQuery(0, n-1, 1, left, right, height);
        }
    }
    
    for(int i = 0; i < n; i++) {
        cout << getHeight(0, n-1, 1, i) << '\n';
    }

    return 0;
}