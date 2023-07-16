#include <bits/stdc++.h>

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second;
    return out;
}

const int MAX = 1'000'000;
int knightHistory[300'001];

struct node {
    ll sum, finish;
};

struct segmentTree {
    node sgTree[1 << 21];
    
    segmentTree() {
        for(int i = 0; i < 1<<21; i++) {
            sgTree[i] = {0, 0};
        }
    }
    
    node merge(node l, node r) {
        node ret = {0, 0};
        ret.sum = l.sum+r.sum;
        ret.finish = max(r.finish, l.finish+r.sum);
        return ret;
    }
    
    void update(int s, int e, int idx, int t, ll sum, ll finish) {
        if(e < t || t < s) return;
        if(s == e) {
            sgTree[idx] = {sum, finish};
            return;
        }
        
        int mid = s+e>>1;
        update(s, mid, idx<<1, t, sum, finish); update(mid+1, e, idx<<1|1, t, sum, finish);
        sgTree[idx] = merge(sgTree[idx<<1], sgTree[idx<<1|1]);
    }
    
    node query(int s, int e, int idx, int i, int j) {
        if(e < i || j < s) return {0, 0};
        if(i <= s && e <= j) return sgTree[idx];
        
        int mid = s+e>>1;
        return merge(query(s, mid, idx<<1, i, j), query(mid+1, e, idx<<1|1, i, j));
    }
}segTree;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int q; cin >> q;
    for(int i = 1; i <= q; i++) {
        char c; cin >> c;
        if(c == '+') {
            int t, d; cin >> t >> d;
            knightHistory[i] = t;
            segTree.update(1, MAX, 1, t, d, t+d);
        }
        if(c == '-') {
            int j; cin >> j;
            int t = knightHistory[j];
            segTree.update(1, MAX, 1, t, 0, 0);
        }
        if(c == '?') {
            int t; cin >> t;
            cout << max(0LL, segTree.query(1, MAX, 1, 1, t).finish-t) << '\n';
        }
    }

    return 0;
}