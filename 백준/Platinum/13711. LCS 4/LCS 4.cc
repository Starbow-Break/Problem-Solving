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

int idx[100001];
int segTree[1 << 18] = {0, };

int query(int l, int r, int index, int i, int j) {
    if(r < i || j < l) return 0;
    if(i <= l && r <= j) return segTree[index];
    
    int mid = (l+r) >> 1;
    return max(query(l, mid, index<<1, i, j), query(mid+1, r, index<<1|1, i, j));
}

void update(int l, int r, int index, int t, int v) {
    if(r < t || t < l) return;
    if(l == r) {
        segTree[index] = v;
        return;
    }
    
    int mid = (l+r) >> 1;
    update(l, mid, index<<1, t, v), update(mid+1, r, index<<1|1, t, v);
    segTree[index] = max(segTree[index << 1], segTree[index << 1 | 1]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        int v; cin >> v;
        idx[v] = i;
    }
    
    for(int i = 1; i <= N; i++) {
        int v; cin >> v;
        update(1, N, 1, idx[v], query(1, N, 1, 1, idx[v]-1)+1);
    }
    
    cout << segTree[1];

    return 0;
}