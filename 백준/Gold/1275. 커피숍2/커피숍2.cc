#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int arr[100001];
ll segTree[270000];

void initTree(int l, int r, int idx) {
    if(l == r) {
        segTree[idx] = arr[l]; return;
    }
    
    int mid = (l+r)>>1;
    initTree(l, mid, idx<<1); initTree(mid+1, r, (idx<<1)|1);
    segTree[idx] = segTree[idx<<1] + segTree[(idx<<1)|1];
}

ll sum(int l, int r, int idx, int x, int y) {
    if(r < x || y < l) return 0;
    
    if(x <= l && r <= y) {
        return segTree[idx];
    }
    
    int mid = (l+r)>>1;
    ll L = sum(l, mid, idx<<1, x, y);
    ll R = sum(mid+1, r, (idx<<1)|1, x, y);
    return L+R;
}

void update(int l, int r, int idx, int a, int b) {
    if(r < a || a < l) return;
    
    if(l == r) {
        segTree[idx] = b;
        return;
    }
    
    int mid = (l+r)>>1;
    update(l, mid, idx<<1, a, b); 
    update(mid+1, r, (idx<<1)|1, a, b);
    segTree[idx] = segTree[idx<<1] + segTree[(idx<<1)|1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, Q; cin >> N >> Q;
    for(int i = 1; i <= N; i++) { cin >> arr[i]; }
    
    initTree(1, N, 1);
    
    while(Q--) {
        int x, y, a, b; cin >> x >> y >> a >> b;
        if(x > y) { int temp = x; x = y; y = temp; }
        cout << sum(1, N, 1, x, y) << '\n';
        update(1, N, 1, a, b);
    }

    return 0;
}