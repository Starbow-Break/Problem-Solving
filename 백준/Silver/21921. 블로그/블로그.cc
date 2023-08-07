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
    
    int N, X; cin >> N >> X;
    int sum[250001];
    sum[0] = 0;
    for(int i = 1; i <= N; i++) {
        cin >> sum[i];
        sum[i] += sum[i-1];
    }
    
    int maxV = sum[X]-sum[0], cnt = 1;
    for(int i = X+1; i <= N; i++) {
        if(maxV < sum[i]-sum[i-X]) {
            maxV = sum[i]-sum[i-X];
            cnt = 1;
        }
        else if(maxV == sum[i]-sum[i-X]) {
            cnt++;
        }
    }
    
    if(maxV == 0) cout << "SAD";
    else {
        cout << maxV << '\n' << cnt;
    }
    
    return 0;
}