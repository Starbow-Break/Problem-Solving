#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int segTree[1 << 18] = {0, };
int A[250001];

void update(int l, int r, int idx, int t, int delta) {
    if(r < t || t < l) return;
    
    if(l == r) {
        segTree[idx] += delta;
        return;
    }
    
    int mid = (l+r)>>1;
    update(l, mid, idx<<1, t, delta);
    update(mid+1, r, (idx<<1)|1, t, delta);
    segTree[idx] = segTree[idx<<1]+segTree[(idx<<1)|1];
}

int query(int l, int r, int idx, int i, int j) {
    if(r < i || j < l) return 0;
    
    if(i <= l && r <= j) {
        return segTree[idx];
    }
    
    int mid = (l+r)>>1;
    return query(l, mid, idx<<1, i, j)+query(mid+1, r, (idx<<1)|1, i, j);
}

int getMedian(int K) {
    int t = (K+1)/2;
    int i = 0; int j = 65536;
    while(i <= j) {
        int mid = (i+j)>>1;
        if(query(0, 65536, 1, 0, mid) < t) i = mid+1;
        else j = mid-1;
    }
    
    return i;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, K; cin >> N >> K;
    ll ans = 0;
    for(int i = 1; i <= N; i++) { cin >> A[i]; }
    
    for(int i = 1; i <= N; i++) {
        if(i < K) {
            update(0, 65536, 1, A[i], 1);
        }
        else {
            update(0, 65536, 1, A[i], 1);
            if(i > K) update(0, 65536, 1, A[i-K], -1);
            
            ans += getMedian(K);
        }
    }
    
    cout << ans;
    
    return 0;
}