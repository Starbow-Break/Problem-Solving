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
    
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        cout << "Case #" << tc << ": ";
        int v; cin >> v;
        if(v == 0) {
            cout << "INSOMNIA" << '\n';
        }
        else {
            int cur = v;
            bool check[10] = {false, };
            int cnt = 0;
            while(true) {
                int n = cur;
                while(n > 0) {
                    if(!check[n%10]) {
                        check[n%10] = true;
                        cnt++;
                    }
                    n /= 10;
                }
                
                if(cnt == 10) {
                    cout << cur << '\n';
                    break;
                }
                
                cur += v;
            }
        }
    }
    
    return 0;
}
