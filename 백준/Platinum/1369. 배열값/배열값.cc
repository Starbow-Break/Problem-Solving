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

int arr1[1000][1000] = {0, }, arr2[1000][1000] = {0, };
int dp1[1000][1000] = {0, }, dp2[1000][1000] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++) {
            int v; cin >> v;
            
            if(v == 0) {
                arr1[r][c] = -1;
                arr2[r][c] = -1;
                continue;
            }
            
            int temp = v;
            while(temp % 2 == 0) {
                arr1[r][c]++;
                temp /= 2;
            }
            
            temp = v;
            while(temp % 5 == 0) {
                arr2[r][c]++;
                temp /= 5;
            }
        }
    }
    
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++) {
            dp1[r][c] = 1e9;
            if(arr1[r][c] == -1) continue;
            
            if(!r && !c) {
                dp1[r][c] = arr1[r][c];
            }
            else {
                if(r) dp1[r][c] = min(dp1[r][c], dp1[r-1][c]+arr1[r][c]);
                if(c) dp1[r][c] = min(dp1[r][c], dp1[r][c-1]+arr1[r][c]);
            }
        }
    }
    
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++) {
            dp2[r][c] = 1e9;
            if(arr1[r][c] == -1) continue;
            
            if(!r && !c) {
                dp2[r][c] = arr2[r][c];
            }
            else {
                if(r) dp2[r][c] = min(dp2[r][c], dp2[r-1][c]+arr2[r][c]);
                if(c) dp2[r][c] = min(dp2[r][c], dp2[r][c-1]+arr2[r][c]);
            }
        }
    }
    
    cout << min(dp1[N-1][N-1], dp2[N-1][N-1]);
    
    return 0;
}
