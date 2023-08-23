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

int l[10001], r[10001];
int arr[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 1; i <= N; i++) cin >> arr[i];
    
    fill(l, l+10001, 100000); fill(r, r+10001, 0);
    for(int i = 1; i <= N; i++) {
        l[arr[i]] = min(l[arr[i]], i);
        r[arr[i]] = max(r[arr[i]], i);
    }
    
    for(int i = 9999; i >= 1; i--) {
        l[i] = min(l[i], l[i+1]);
        r[i] = max(r[i], r[i+1]);
    }
    
    int ans = 0;
    for(int i = 1; i <= 10000; i++) {
        ans = max(ans, i*(r[i]-l[i]-1));
    }
    
    cout << ans;
    
    return 0;
}