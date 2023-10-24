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

int R, C;
char arr[750][751];
int dp1[750][750] = {0, }; //우상향
int dp2[750][750] = {0, }; //우하향
int dp3[750][750] = {0, }; //좌상향
int dp4[750][750] = {0, }; //좌하향

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> R >> C;
    for(int r = 0; r < R; r++) cin >> arr[r];
    
    //dp1 계산
    for(int r = 0; r < R; r++) {
        for(int c = 0; c < C; c++) {
            if(arr[r][c] == '1') {
                if(r-1 >= 0 && c+1 < C) {
                    dp1[r][c] = dp1[r-1][c+1]+1;
                }
                else dp1[r][c] = 1;
            }
            else dp1[r][c] = 0;
        }
    }
    
    //dp2 계산
    for(int r = R-1; r >= 0; r--) {
        for(int c = 0; c < C; c++) {
            if(arr[r][c] == '1') {
                if(r+1 < R && c+1 < C) {
                    dp2[r][c] = dp2[r+1][c+1]+1;
                }
                else dp2[r][c] = 1;
            }
            else dp2[r][c] = 0;
        }
    }
    
    //dp3 계산
    for(int r = 0; r < R; r++) {
        for(int c = 0; c < C; c++) {
            if(arr[r][c] == '1') {
                if(r-1 >= 0 && c-1 >= 0) {
                    dp3[r][c] = dp3[r-1][c-1]+1;
                }
                else dp3[r][c] = 1;
            }
            else dp3[r][c] = 0;
        }
    }
    
    //dp4 계산
    for(int r = R-1; r >= 0; r--) {
        for(int c = 0; c < C; c++) {
            if(arr[r][c] == '1') {
                if(r+1 < R && c-1 >= 0) {
                    dp4[r][c] = dp4[r+1][c-1]+1;
                }
                else dp4[r][c] = 1;
            }
            else dp4[r][c] = 0;
        }
    }
    
    // 다이아 찾기
    int ub = min((R+1)/2, (C+1)/2);
    for(int sz = ub; sz >= 1; sz--) {
        for(int r = sz-1; r <= R-1-sz+1; r++) {
            for(int c = sz-1; c <= C-1-sz+1; c++) {
                // 찾으면 사이즈 출력 후 종료
                if(dp1[r][c-sz+1] >= sz && dp2[r-sz+1][c] >= sz 
                && dp3[r+sz-1][c] >= sz && dp4[r][c+sz-1] >= sz ) {
                    cout << sz;
                    return 0;
                }
            }
        }
    }
    
    //못 찾으면 0 출력
    cout << 0;
    
    return 0;
}