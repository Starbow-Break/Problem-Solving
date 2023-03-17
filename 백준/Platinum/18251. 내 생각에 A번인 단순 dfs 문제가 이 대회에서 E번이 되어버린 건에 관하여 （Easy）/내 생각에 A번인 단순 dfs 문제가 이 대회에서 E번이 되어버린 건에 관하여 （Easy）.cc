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

const ll INF = 1'000'000'000'000'000'000;

struct node {
    ll l, r, maxV, sum;
};

int arr[270000], brr[270000];
node segTree[1 << 19];
vector<int> tree[20]; int dep = 0;
ll maxValue = -INF;

void initTree() {
    for(int i = 1; i < (1<<19); i++) segTree[i] = {0, 0, 0, 0};
}

void update(int i, int j, int idx, int t, int value) {
    if(j < t || t < i) return;
    
    if(i == j) {
        segTree[idx] = {value, value, value, value};
        return;
    }
    
    int mid = (i+j)>>1;
    update(i, mid, idx<<1, t, value); update(mid+1, j, (idx<<1)|1, t, value);
    
    segTree[idx].l = max(segTree[idx<<1].l, segTree[idx<<1].sum+segTree[(idx<<1)|1].l);
    
    segTree[idx].r = max(segTree[(idx<<1)|1].r, segTree[(idx<<1)|1].sum+segTree[idx<<1].r);
    
    segTree[idx].sum = segTree[idx<<1].sum+segTree[(idx<<1)|1].sum;
    
    segTree[idx].maxV = max(segTree[idx<<1].maxV, segTree[(idx<<1)|1].maxV);
    segTree[idx].maxV = max(segTree[idx].maxV, segTree[idx<<1].r+segTree[(idx<<1)|1].l);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
        maxValue = max(maxValue, (ll)arr[i]);
    }
    
    brr[(N+1)/2] = arr[1];
    int cnt = 2; int start = (N+1)/4; int w = (N+1)/2; int _cnt = 0;
    for(int i = 2; i <= N; i++) {
        if(_cnt == cnt) {
            cnt *= 2; start /= 2; w /= 2; _cnt = 0;
        }

        brr[start+_cnt*w] = arr[i];
        _cnt++;
    }
    
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < 20; j++) {
            if(i & (1<<j)) {
                tree[j].push_back(i);
                dep = max(dep, j); break;
            }
        }
    }
    
    if(maxValue < 0) cout << maxValue;
    else {
        ll ans = -INF;
        for(int i = 0; i <= dep; i++) {
            initTree();
            for(int j = i; j <= dep; j++) {
                for(auto &idx: tree[j]) {
                    update(1, N, 1, idx, brr[idx]);
                }
                ans = max(ans, segTree[1].maxV);
            }
        }
        
        cout << ans;
    }
    
    return 0;
}