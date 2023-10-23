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

int minLeft[100000]; // minLeft[i] = P[0]~P[i]에서 연속 구간의 최소 합
int maxLeft[100000]; // maxLeft[i] = P[0]~P[i]에서 연속 구간의 최대 합
int minRight[100000]; // minRight[i] = P[i]~P[N]에서 연속 구간의 최소 합
int maxRight[100000]; // maxRight[i] = P[i]~P[N]에서 연속 구간의 최대 합
//----------------------------------------------------------------------------
int _minLeft[100000]; // _minLeft[i] = P[0]~P[i]에서 P[i]를 포함하는 연속 구간의 최소 합
int _maxLeft[100000]; // _maxLeft[i] = P[0]~P[i]에서 P[i]를 포함하는 연속 구간의 최대 합
int _minRight[100000]; // _minRight[i] = P[i]~P[N]에서 P[i]를 포함하는 연속 구간의 최소 합
int _maxRight[100000]; // _maxRight[i] = P[i]~P[N]에서 P[i]를 포함하는 연속 구간의 최대 합

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    vector<int> P(N);
    for(int i = 0; i < N; i++) cin >> P[i];
    
    for(int i = 0; i < N; i++) {
        if(i == 0) {
            minLeft[i] = maxLeft[i] = _minLeft[i] = _maxLeft[i] = P[i];
        }
        else {
            _minLeft[i] = min(P[i], P[i]+_minLeft[i-1]);
            _maxLeft[i] = max(P[i], P[i]+_maxLeft[i-1]);
            minLeft[i] = min(minLeft[i-1], _minLeft[i]);
            maxLeft[i] = max(maxLeft[i-1], _maxLeft[i]);
        }
    }
    
    for(int i = N-1; i >= 0; i--) {
        if(i == N-1) {
            minRight[i] = maxRight[i] = _minRight[i] = _maxRight[i] = P[i];
        }
        else {
            _minRight[i] = min(P[i], P[i]+_minRight[i+1]);
            _maxRight[i] = max(P[i], P[i]+_maxRight[i+1]);
            minRight[i] = min(minRight[i+1], _minRight[i]);
            maxRight[i] = max(maxRight[i+1], _maxRight[i]);
        }
    }
    
    ll ans = -1e18;
    for(int i = 0; i < N-1; i++) {
        ans = max({ans, 1LL*minLeft[i]*minRight[i+1], 1LL*maxLeft[i]*maxRight[i+1]});
    }
    cout << ans;
    
    return 0;
}
