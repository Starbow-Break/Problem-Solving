#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <iomanip>
#define x first
#define y second
#define MOD 998'244'353

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

struct node {
    int l, r, maxV, len;
};

struct query {
    int l, r, w;
};

int N, Q; 
int h[100'001]; //높이
int invComp[100'001];
vector<int> vec;
vector<int> bars[100'001];
query queries[100'001];
int lo[100'001], hi[100'001];
node segTree[1 << 18];

void compress() {
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    for(int i = 1; i <= N; i++) {
        int ori = h[i];
        h[i] = lower_bound(vec.begin(), vec.end(), h[i])-vec.begin()+1;
        bars[h[i]].push_back(i); invComp[h[i]] = ori;
    }
}

node merge(node &a, node &b) {
    node ret;
    ret.l = (a.l == a.len ? a.l+b.l : a.l);
    ret.r = (b.r == b.len ? b.r+a.r : b.r);
    ret.maxV = max({ret.l, ret.r, a.maxV, b.maxV, a.r+b.l});
    ret.len = a.len+b.len;
    
    return ret;
}

void initTree(int l, int r, int idx) {
    if(l == r) {
        segTree[idx].l = segTree[idx].r = segTree[idx].maxV = 0;
        segTree[idx].len = 1;
        return;
    }
    
    int mid = l+r>>1;
    initTree(l, mid, idx<<1); initTree(mid+1, r, idx<<1|1);
    segTree[idx] = merge(segTree[idx<<1], segTree[idx<<1|1]);
}

void update(int l, int r, int idx, int t, int v) {
    if(r < t || t < l) return;
    if(l == r) {
        segTree[idx].l = segTree[idx].r = segTree[idx].maxV = v;
        return;
    }
    
    int mid = l+r>>1;
    update(l, mid, idx<<1, t, v); update(mid+1, r, idx<<1|1, t, v);
    segTree[idx] = merge(segTree[idx<<1], segTree[idx<<1|1]);
}

node query(int l, int r, int idx, int i, int j) {
    if(r < i || j < l) return {0, 0, 0, 0};
    if(i <= l && r <= j) return segTree[idx]; 
    
    int mid = l+r>>1;
    node a = query(l, mid, idx<<1, i, j);
    node b = query(mid+1, r, idx<<1|1, i, j);
    return merge(a, b);
}

vector<int> midV[100'001]; int temp[100'001];
void solve() {
    for(int i = 1; i <= Q; i++) midV[(lo[i]+hi[i])/2].push_back(i);
    
    bool flag;
    while(1) {
        flag = false;
        initTree(1, N, 1);
        
        for(int mid = N; mid >= 1; mid--) {
            for(auto &idx: bars[mid]) update(1, N, 1, idx, 1);
                
            if(midV[mid].size()) {
                flag = true;
                
                for(auto &q: midV[mid]) {
                    int maxW = query(1, N, 1, queries[q].l, queries[q].r).maxV;
                    if(queries[q].w <= maxW) lo[q] = mid+1;
                    else hi[q] = mid-1;
                    
                    temp[q] = (lo[q] <= hi[q] ? (lo[q]+hi[q])/2 : -1);
                }
            }
        }
        
        if(!flag) break;
        
        for(int i = 1; i <= N; i++) midV[i].clear();
        for(int i = 1; i <= Q; i++) {
            if(temp[i] != -1) midV[temp[i]].push_back(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> h[i]; vec.push_back(h[i]);
    }
    
    compress(); //높이 압축
    
    cin >> Q;
    for(int i = 1; i <= Q; i++) {
        int l, r, w; cin >> l >> r >> w;
        queries[i] = {l, r, w};
        lo[i] = 1; hi[i] = vec.size();
    }
    
    solve();
    
    for(int i = 1; i <= Q; i++) cout << invComp[hi[i]] << '\n';
    
    return 0;
}