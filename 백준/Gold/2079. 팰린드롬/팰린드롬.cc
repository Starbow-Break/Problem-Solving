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

bool is_palindrome[2000][2000] = {false, };
int dp[2000][2000] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s; cin >> s;
    for(int k = 1; k <= s.length(); k++) {
        for(int i = 0; i <= s.length()-k; i++) {
            if(k <= 2) {
                is_palindrome[i][i+k-1] = s[i] == s[i+k-1];
            }
            else {
                is_palindrome[i][i+k-1] = (s[i] == s[i+k-1]) && is_palindrome[i+1][i+k-2];
            }
        }
    }
    
    int lenS = s.length();
    for(int k = 1; k <= lenS; k++) {
        for(int i = 0; i <= lenS-k; i++) {
            int l = i, r = i+k-1;
            dp[l][r] = 1'000'000'000;
            if(is_palindrome[l][r]) dp[l][r] = 1;
            else {
                for(int j = l; j < r; j++) {
                    if(is_palindrome[l][j])
                        dp[l][r] = min(dp[l][r], 1+dp[j+1][r]);
                }
            }
        }
    }
    
    cout << dp[0][s.length()-1];
    
    return 0;
}