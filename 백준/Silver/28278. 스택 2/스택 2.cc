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
    
    stack<int> s; int cnt = 0;
    int N; cin >> N;
    while(N--) {
        int q; cin >> q;
        if(q == 1) {
            int x; cin >> x;
            s.push(x);
            cnt++;
        }
        if(q == 2) {
            if(cnt == 0) cout << -1 << '\n';
            else {
                cout << s.top() << '\n';
                s.pop();
                cnt--;
            }
        }
        if(q == 3) {
            cout << cnt << '\n';
        }
        if(q == 4) {
            cout << (cnt == 0) << '\n';
        }
        if(q == 5) {
            if(cnt == 0) cout << -1 << '\n';
            else cout << s.top() << '\n';
        }
    }
    
    return 0;
}