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

double p[4][700] = {0, }; // 확률
double dp[1001][700] = {0, };

int calcMoney(int dices) {
    int a = dices/100, b = dices%100/10, c = dices%10;
    if(1 <= a && a <= 6 && 1 <= b && b <= 6 && 1 <= c && c <= 6) {
        if(a == b && b == c) {
            return 10000+a*1000;
        }
        else if(a == b || a == c) {
            return 1000+a*100;
        }
        else if(b == c) {
            return 1000+b*100;
        }
        else {
            return max({a, b, c})*100;
        }
    }
    
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 1; i <= 6; i++) {
        p[1][100*i] = 1.0/6;
    }
    
    for(int i = 1; i < 3; i++) {
        for(int j = 0; j <= 666; j++) {
            if(p[i][j] == 0) continue;
                
            for(int k = 1; k <= 6; k++) {
                p[i+1][100*k+j/10] += p[i][j]/6;
            }
        }
    }
    
    for(int j = 0; j <= 666; j++) {
        dp[0][j] = calcMoney(j);
    }
    
    for(int i = 1; i <= N-3; i++) {
        for(int j = 0; j <= 666; j++) {
            double bef = calcMoney(j);
            double after = 0;
            
            if(bef > 0) {
                for(int k = 1; k <= 6; k++) {
                    after += dp[i-1][j/10+k*100]/6;
                }
                
                dp[i][j] += max(bef, after);
            }
        }
    }
    
    double ans = 0;
    
    for(int j = 0; j <= 666; j++) {
        ans += p[3][j]*dp[N-3][j];
    }
    
    cout << fixed << setprecision(12) << ans;
    
    return 0;
}
