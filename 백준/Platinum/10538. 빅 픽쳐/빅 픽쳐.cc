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

const ll MOD = 999'999'999'999'989;

int hp, wp, hm, wm;
int128 weight[2000][2000] = {0, };

char p[2000][2001], m[2000][2001];
int128 targetHash = 0;

int128 sum[2000][2000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> hp >> wp >> hm >> wm;
    weight[0][0] = 1;
    
    //가중치 계산
    for(int i = 1; i < hm*wm; i++) {
        weight[i/wm][i%wm] = weight[(i-1)/wm][(i-1)%wm]*11%MOD;
    }
    
    for(int r = 0; r < hp; r++) cin >> p[r];
    for(int r = 0; r < hm; r++) cin >> m[r];
    
    //목표 hash 값 계산
    for(int r = 0; r < hp; r++) {
        for(int c = 0; c < wp; c++) {
            targetHash += weight[r][c]*(p[r][c] == 'o' ? 7 : 3);
            targetHash %= MOD;
        }
    }
    
    //hash 누적합 계산
    for(int r = 0; r < hm; r++) {
        for(int c = 0; c < wm; c++) {
            sum[r][c] = weight[r][c]*(m[r][c] == 'o' ? 7 : 3);
            sum[r][c] %= MOD;
        }
    }
    
    for(int r = 0; r < hm; r++) {
        for(int c = 1; c < wm; c++) {
            sum[r][c] += sum[r][c-1];
            sum[r][c] %= MOD;
        }
    }
    
    for(int c = 0; c < wm; c++) {
        for(int r = 1; r < hm; r++) {
            sum[r][c] += sum[r-1][c];
            sum[r][c] %= MOD;
        }
    }
    
    // 갯수 구하기
    int ans = 0;
    for(int r = 0; r <= hm-hp; r++) {
        for(int c = 0; c <= wm-wp; c++) {
            int128 pHash = weight[r][c]*targetHash%MOD;
            int128 mHash = sum[r+hp-1][c+wp-1];
            if(r-1 >= 0) mHash += MOD-sum[r-1][c+wp-1];
            if(c-1 >= 0) mHash += MOD-sum[r+hp-1][c-1];
            if(r-1 >= 0 && c-1 >= 0) mHash += sum[r-1][c-1];
            mHash %= MOD;
            ans += (pHash == mHash);
        }
    }
    
    cout << ans;
    
    return 0;
}
