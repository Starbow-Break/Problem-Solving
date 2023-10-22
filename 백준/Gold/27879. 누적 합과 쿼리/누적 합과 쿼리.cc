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

char A[1001][1001];
int dp1[4][1001][1001] = {0, }; //가로
int dp2[4][1001][1001] = {0, }; //세로

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= N; c++) cin >> A[r][c];
    }
    
    for(int r = 1; r <= N; r++) {
        for(int c = 2; c <= N; c++) {
            if(A[r][c-1] == 'a' && A[r][c] == 'a') {
                dp1[0][r][c]++;
            }
            if(A[r][c-1] == 'a' && A[r][c] == 'b') {
                dp1[1][r][c]++;
            }
            if(A[r][c-1] == 'b' && A[r][c] == 'a') {
                dp1[2][r][c]++;
            }
            if(A[r][c-1] == 'b' && A[r][c] == 'b') {
                dp1[3][r][c]++;
            }
        }
    }
    
    for(int k = 0; k < 4; k++) {
        for(int r = 0; r <= N; r++) {
            for(int c = 1; c <= N; c++) {
                dp1[k][r][c] += dp1[k][r][c-1];
            }
        }
    }

    for(int k = 0; k < 4; k++) {
        for(int r = 1; r <= N; r++) {
            for(int c = 0; c <= N; c++) {
                dp1[k][r][c] += dp1[k][r-1][c];
            }
        }
    }
    
    for(int r = 2; r <= N; r++) {
        for(int c = 1; c <= N; c++) {
            if(A[r-1][c] == 'a' && A[r][c] == 'a') {
                dp2[0][r][c]++;
            }
            if(A[r-1][c] == 'a' && A[r][c] == 'b') {
                dp2[1][r][c]++;
            }
            if(A[r-1][c] == 'b' && A[r][c] == 'a') {
                dp2[2][r][c]++;
            }
            if(A[r-1][c] == 'b' && A[r][c] == 'b') {
                dp2[3][r][c]++;
            }
        }
    }
    
    for(int k = 0; k < 4; k++) {
        for(int r = 0; r <= N; r++) {
            for(int c = 1; c <= N; c++) {
                dp2[k][r][c] += dp2[k][r][c-1];
            }
        }
    }
    
    for(int k = 0; k < 4; k++) {
        for(int r = 1; r <= N; r++) {
            for(int c = 0; c <= N; c++) {
                dp2[k][r][c] += dp2[k][r-1][c];
            }
        }
    }
    
    int Q; cin >> Q;
    while(Q--) {
        int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
        int k;
        string s; cin >> s;
        if(s == "aa") k = 0;
        if(s == "ab") k = 1;
        if(s == "ba") k = 2;
        if(s == "bb") k = 3;
        
        int ans = 0;
        ans += dp1[k][r2][c2]-dp1[k][r1-1][c2]-dp1[k][r2][c1]+dp1[k][r1-1][c1];
        ans += dp2[k][r2][c2]-dp2[k][r1][c2]-dp2[k][r2][c1-1]+dp2[k][r1][c1-1];
        
        cout << ans << '\n';
    }
    
    return 0;
}
