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

int N;
char arr[2][51];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> arr[0] >> arr[1];
    
    int ans = N*2;
    
    if(arr[0][0] == '.') {
        int c = 0, cur = 0;
        for(int i = 0; i < N; i++) {
            cur++;
            if(i+1 < N && arr[c][i+1] == '#') {
                c = 1-c; cur++;
            }
        }
        ans = min(ans, cur);
    }
    if(arr[1][0] == '.') {
        int c = 1, cur = 0;
        for(int i = 0; i < N; i++) {
            cur++;
            if(i+1 < N && arr[c][i+1] == '#') {
                c = 1-c; cur++;
            }
        }
        ans = min(ans, cur);
    }
    
    ans = 2*N-ans;
    for(int i = 0; i < N; i++) {
        ans -= (arr[0][i] == '#');
        ans -= (arr[1][i] == '#');
    }
    
    cout << ans;
    
    return 0;
}