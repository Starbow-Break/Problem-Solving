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

const int INF = 1e9;

int sum[500'001] = {0, };
int segTree[1 << 20];

void initTree(int l, int r, int idx) {
    if(l == r) {
        segTree[idx] = sum[l];
        return;
    }
    
    int mid = (l+r) >> 1;
    initTree(l, mid, idx<<1); initTree(mid+1, r, idx<<1|1);
    segTree[idx] = min(segTree[idx<<1], segTree[idx<<1|1]);
}

int query(int l, int r, int idx, int i, int j) {
    if(r < i || j < l) return INF;
    
    if(i <= l && r <= j) return segTree[idx];
    
    int mid = (l+r) >> 1;
    return min(query(l, mid, idx<<1, i, j), query(mid+1, r, idx<<1|1, i, j));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    fill(segTree+1, segTree+(1<<20), INF);
    
    int N; cin >> N;
    string s; cin >> s;
    
    if(N%2) {
        for(int i = 1; i <= N; i++) {
            sum[i] = sum[i-1] + (s[i-1] == '(' ? 1 : -1);
        }
        
        initTree(1, N, 1);
        
        int i = 1, j = N-1;
        bool check = false;
        while(i <= j && !check) {
            if(sum[j]-sum[i-1] == 0 && query(1, N, 1, i, j) >= sum[i-1]) {
                check = true;
            }
            
            i++; j--;
        }
        
        i = 2; j = N;
        while(i <= j && !check) {
            if(sum[j]-sum[i-1] == 0 && query(1, N, 1, i, j) >= sum[i-1]) {
                check = true;
            }
            
            i++; j--;
        }
        
        cout << (check ? "jimin" : "junhui");
    }
    else {
        cout << "junhui";
    }
    
    return 0;
}