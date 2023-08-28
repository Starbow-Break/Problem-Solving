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
    int ans = 15*((N-1)/8);
    N %= 8;
    switch(N) {
        case 0:
        ans += 14;
        break;
        case 1:
        ans += 1;
        break;
        case 2:
        ans += 2;
        break;
        case 3:
        ans += 4;
        break;
        case 4:
        ans += 7;
        break;
        case 5:
        ans += 8;
        break;
        case 6:
        ans += 11;
        break;
        case 7:
        ans += 13;
    }
    
    cout << ans;
    
    return 0;
}