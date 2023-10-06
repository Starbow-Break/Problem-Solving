#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define pb push_back 
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define compress(vec) sort(all(vec)); vec.erase(unique(all(vec)), vec.end());

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using int128 = __int128_t;

struct node {
    int value, cnt, num;
};

struct cmp {
    bool operator()(node &a, node &b) {
        return a.value < b.value;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M;
    vector<int> A(M), B(M);
    
    for(int i = 0; i < M; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];
    
    priority_queue<node, vector<node>, cmp> pq;
    
    for(int i = 0; i < M; i++) {
        if(100-A[i] >= B[i]) {
            pq.push({B[i], (100-A[i])/B[i], i});
        }
        else {
            if(100-A[i] > 0) pq.push({100-A[i], 1, i});
        }
    }
    
    N *= 24;
    while(N > 0 && !pq.empty()) {
        node cur = pq.top(); pq.pop();
        A[cur.num] += cur.value*min(N, cur.cnt);
        N -= min(N, cur.cnt);
        
        if(100-A[cur.num] > 0) {
            pq.push({100-A[cur.num], 1, cur.num});
        }
    }
    
    int ans = 0;
    for(auto &a: A) ans += a;
    cout << ans;
    
    return 0;
}
