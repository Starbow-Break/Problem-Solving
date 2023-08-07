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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, K; cin >> N >> K;
    vector<int> vec;
    repeat(N) {
        int v; cin >> v;
        vec.pb(v);
    }
    
    int i = 0, j = 2'000'000;
    while(i <= j) {
        int mid = i+j >> 1;
        int sum = 0, cnt = 1;
        FOR(i, 0, N) {
            sum += vec[i];
            if(sum >= mid) {
                cnt++;
                sum = 0;
            }
        }
        if(sum > 0) {
            cnt--;
        }
        
        if(cnt >= K) i = mid+1;
        else j = mid-1;
    }
    
    cout << j;
    
    return 0;
}