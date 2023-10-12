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
    
    int N; cin >> N;
    int cnt[1001] = {0, };
    int sum = 0;
    
    repeat(N) {
        int v; cin >> v;
        cnt[v]++;
        sum += v;
    }
    
    int ans = 0, idx = 0;
    for(int i = 1; i <= N; i++) {
        if(cnt[i] && ans < i*cnt[i]+sum) {
            ans = i*cnt[i]+sum;
            idx = i;
        }
    }
    
    cout << ans << '\n';
    
    for(int i = 1; i < idx; i++) {
        while(cnt[i]) {
            cout << i << ' ';
            cnt[i]--;
        }
    }
    for(int i = N; i > idx; i--) {
        while(cnt[i]) {
            cout << i << ' ';
            cnt[i]--;
        }
    }
    while(cnt[idx]) {
        cout << idx << ' ';
        cnt[idx]--;
    }
    
    return 0;
}