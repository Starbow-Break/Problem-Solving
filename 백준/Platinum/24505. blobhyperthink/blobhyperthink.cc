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
#define MOD 1'000'000'007

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

int segTree[12][1 << 18] = {0, };
int A[100'000];

void update(int i, int s, int e, int idx, int t, int v) {
    if(e < t || t < s) return;
    if(s == e) {
        segTree[i][idx] += v;
        segTree[i][idx] %= MOD;
        return;
    }
    
    int mid = s+e >> 1;
    update(i, s, mid, idx<<1, t, v);
    update(i, mid+1, e, idx<<1|1, t, v);
    segTree[i][idx] = (segTree[i][idx<<1]+segTree[i][idx<<1|1])%MOD;
}

int query(int i, int s, int e, int idx, int qs, int qe) {
    if(qe < s || e < qs) return 0;
    if(qs <= s && e <= qe) return segTree[i][idx];
    
    int mid = s+e >> 1;
    return (query(i, s, mid, idx<<1, qs, qe)+query(i, mid+1, e, idx<<1|1, qs, qe))%MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];
    
    for(int i = 0; i < N; i++) {
        update(1, 1, N, 1, A[i], 1);
        for(int j = 2; j <= 11; j++) {
            int t = query(j-1, 1, N, 1, 1, A[i]-1);
            update(j, 1, N, 1, A[i], t);
        }
    }
    
    ll ans = 0;
    for(int i = 1; i <= N; i++) {
        ans += query(11, 1, N, 1, i, i);
        ans %= MOD;
    }
    
    cout << ans;

    return 0;
}