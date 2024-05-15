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
    
    char flag[6][10];
    for(int i = 0; i < 6; i++) cin >> flag[i];
    
    int ans = 54;
    
    int cur = 0;
    int cnt[3][26] = {0, };
    for(int i = 0; i < 6; i += 2) {
        for(int j = 0; j < 18; j++) {
            cnt[i/2][flag[i+j/9][j%9] - 'A']++;
        }
    }
    
    for(int a = 0; a < 26; a++) {
        for(int b = 0; b < 26; b++) {
            for(int c = 0; c < 26; c++) {
                if(a == b || b == c) continue;
                ans = min(ans, 54-(cnt[0][a]+cnt[1][b]+cnt[2][c]));
            }
        }
    }
    
    cur = 0;
    for(int i = 0; i < 3; i++) fill(cnt[i], cnt[i]+26, 0);
    for(int i = 0; i < 9; i+= 3) {
        for(int j = 0; j < 18; j++) {
            cnt[i/3][flag[j%6][i+j/6] - 'A']++;
        }
    }
    
    for(int a = 0; a < 26; a++) {
        for(int b = 0; b < 26; b++) {
            for(int c = 0; c < 26; c++) {
                if(a == b || b == c) continue;
                ans = min(ans, 54-(cnt[0][a]+cnt[1][b]+cnt[2][c]));
            }
        }
    }
    
    cout << ans;
    
    return 0;
}