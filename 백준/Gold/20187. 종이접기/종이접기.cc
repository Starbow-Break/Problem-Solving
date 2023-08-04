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

bool arr[256][256] = {false, };
int ans[256][256] = {0, };
vector<char> progress;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int k; cin >> k;
    int ra, ca, rb, cb;
    ra = 0, ca = 0; //왼쪽 위
    rb = (1<<k)-1, cb = (1<<k)-1; //오른쪽 아래
    
    repeat(2*k) {
        char c; cin >> c;
        progress.pb(c);
    }
    
    for(auto &c: progress) {
        switch(c) {
            case 'L':
                cb -= (cb-ca+1)/2;
                break;
            case 'R':
                ca += (cb-ca+1)/2;
                break;
            case 'U':
                rb -= (rb-ra+1)/2;
                break;
            case 'D':
                ra += (rb-ra+1)/2;
        }
    }
    
    int h; cin >> h;
    ans[ra][ca] = h;
    
    reverse(progress.begin(), progress.end());
    for(auto &c: progress) {
        switch(c) {
            case 'L':
                FOR(r, ra, rb+1) {
                    FOR(c, ca, cb+1) {
                        ans[r][2*cb+1-c] = ans[r][c]+1-2*(ans[r][c]%2);
                    }
                }
                cb += (cb-ca+1);
                break;
            case 'R':
                FOR(r, ra, rb+1) {
                    FOR(c, ca, cb+1) {
                        ans[r][2*ca-1-c] = ans[r][c]+1-2*(ans[r][c]%2);
                    }
                }
                ca -= (cb-ca+1);
                break;
            case 'U':
                FOR(r, ra, rb+1) {
                    FOR(c, ca, cb+1) {
                        ans[2*rb+1-r][c] = ans[r][c]+2*(1-ans[r][c]/2*2);
                    }
                }
                rb += (rb-ra+1);
                break;
            case 'D':
                FOR(r, ra, rb+1) {
                    FOR(c, ca, cb+1) {
                        ans[2*ra-1-r][c] = ans[r][c]+2*(1-ans[r][c]/2*2);
                    }
                }
                ra -= (rb-ra+1);
        }
    }
    
    FOR(r, 0, 1<<k) {
        FOR(c, 0, 1<<k) {
            cout << ans[r][c] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}