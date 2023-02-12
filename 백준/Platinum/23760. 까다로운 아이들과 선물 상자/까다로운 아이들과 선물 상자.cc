#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#define MAX_N 100'000
#define MAX_M 100'000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int N, M;
int c[MAX_N+1], w[MAX_N+1], b[MAX_N+1];

struct segmentTree {
    int sgTree[1 << 18];
    
    void init() {
        fill(sgTree, sgTree+(1<<18), 0);
    }
    
    void update(int l, int r, int idx, int t, int del) {
        if(r < t || t < l) return;
        
        if(l == r) {
            sgTree[idx] += del; return;
        }
        
        int mid = (l+r)>>1;
        update(l, mid, idx<<1, t, del); update(mid+1, r, (idx<<1)|1, t, del);
        sgTree[idx] = sgTree[idx<<1]+sgTree[(idx<<1)|1];
    }
    
    int query(int l, int r, int idx, int i, int j) {
        if(r < i || j < l) return 0;
        
        if(i <= l && r <= j) return sgTree[idx];
        
        int mid = (l+r)>>1;
        return query(l, mid, idx<<1, i, j)+query(mid+1, r, (idx<<1)|1, i, j);
    }
} segTree;

void buildTree() {
    segTree.init();
    
    for(int i = 1; i <= N; i++) {
        segTree.update(0, 100'000, 1, c[i], 1);
    }
}

int query(int b) {
    int i = 0; int j = 100'000;
    while(i <= j) {
        int mid = (i+j)>>1;
        
        int rank = segTree.query(0, 100'000, 1, mid, 100'000);
        
        if(rank >= b) i = mid+1;
        else j = mid-1;
    }
    
    return j;
}

void update(int c, int w) {
    segTree.update(0, 100'000, 1, c, -1);
    segTree.update(0, 100'000, 1, c-w, 1);
}

bool solve() {
    buildTree();
    
    for(int i = 1; i <= M; i++) {
        int c = query(b[i]);
        if(c < w[i]) return false;
        
        update(c, w[i]);
    }
    
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for(int i = 1; i <= N; i++) { cin >> c[i]; }
    for(int i = 1; i <= M; i++) { cin >> w[i]; }
    for(int i = 1; i <= M; i++) { cin >> b[i]; }
    
    cout << solve();

    return 0;
}