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

int left_child[100'001];
int right_child[100'001];

int in_order(int cur) {
    int ret = 0;
    if(left_child[cur] != -1) ret += in_order(left_child[cur])+2;
    if(right_child[cur] != -1) ret += in_order(right_child[cur])+2;
    return ret;
}

int solve() {
    int i = in_order(1);
    
    int r = 1;
    while(right_child[r] != -1) {
        r = right_child[r]; i--;
    }
    
    return i;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    repeat(N) {
        int v, l, r; cin >> v >> l >> r;
        left_child[v] = l;
        right_child[v] = r;
    }
    
    cout << solve();
    
    return 0;
}