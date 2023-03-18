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
#define MAX_N 500'000
#define MAX_k 500'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int arr[MAX_N+1];
int checkMod[MAX_k] = {0, };
int segTree[1 << 20] = {0, };

void update(int l, int r, int idx, int t, int val) {
    if(r < t || t < l) return;
    
    if(l == r) {
        segTree[idx] = max(segTree[idx], val);
        return;
    }
    
    int mid = (l+r)>>1;
    update(l, mid, idx<<1, t, val); update(mid+1, r, (idx<<1)|1, t, val);
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
    
    int N, k, d; cin >> N >> k >> d;
    for(int i = 1; i <= N; i++) cin >> arr[i];
    
    for(int i = 1; i <= N; i++) {
        int maxBean = max(checkMod[arr[i]%k], query(1, 500'000, 1, max(1, arr[i]-d), min(arr[i]+d, 500'000)))+1;
        checkMod[arr[i]%k] = max(checkMod[arr[i]%k], maxBean);
        update(1, 500'000, 1, arr[i], maxBean);
    }
    
    cout << segTree[1];

    return 0;
}