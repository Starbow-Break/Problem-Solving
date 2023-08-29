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
    int arr[1001][5];
    bool check[1001][1001] = {false, };
    
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < 5; j++) cin >> arr[i][j];
    }
    
    for(int i = 1; i <= N; i++) {
        for(int r = 1; r <= N; r++) {
            for(int c = 0; c < 5; c++) {
                if(arr[i][c] == arr[r][c]) check[i][r] = true;
            }
        }
    }
    
    int ans = 0, maxV = 0;
    for(int r = 1; r <= N; r++) {
        int cur = 0;
        for(int c = 1; c <= N; c++) {
            cur += check[r][c];
        }
        if(maxV < cur) {
            ans = r;
            maxV = cur;
        }
    }
    
    cout << ans;
    
    return 0;
}
