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

int A[100001], L[100001], R[100001]; ll sum[100001] = {0, };



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 1; i <= N; i++) cin >> A[i];
    
    stack<pii> s;
    s.push({A[1], 1});
    for(int i = 1; i <= N; i++) {
        while(!s.empty() && s.top().fi >  A[i]) {
            R[s.top().se] = i-1;
            s.pop();
        }
        s.push({A[i], i});
    }
    while(!s.empty()) {
        R[s.top().se] = N;
        s.pop();
    }
    
    s.push({A[N], N});
    for(int i = N-1; i >= 1; i--) {
        while(!s.empty() && s.top().fi > A[i]) {
            L[s.top().se] = i+1;
            s.pop();
        }
        s.push({A[i], i});
    }
    while(!s.empty()) {
        L[s.top().se] = 1;
        s.pop();
    }
    
    for(int i = 1; i <= N; i++) sum[i] = A[i]+sum[i-1];
    
    ll ans = 0;
    for(int i = 1; i <= N; i++) {
        ans = max(ans, 1LL*A[i]*(sum[R[i]]-sum[L[i]-1]));
    }
    
    cout << ans;
    
    return 0;
}