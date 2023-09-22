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
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using int128 = __int128_t;

string F[27]; // F(0)~F(26) 전처리
string l[101], r[101]; // l_25 ~ l_100, r_25 ~ r_100 전처리

ll dp[101];

vector<int> getFail(string &p) {
    vector<int> ret;
    ret.pb(0);
    
    int j = 0;
    for(int i = 1; i < p.length(); i++) {
        while(j > 0 && p[i] != p[j]) j = ret[j-1];
        if(p[i] == p[j]) j++;
        ret.pb(j);
    }
    
    return ret;
}

vector<int> kmp(string s, string p) {
    vector<int> ret;
    vector<int> fail = getFail(p);
    
    int j = 0;
    for(int i = 0; i < s.length(); i++) {
        while(j > 0 && s[i] != p[j]) j = fail[j-1];
        if(s[i] == p[j]) j++;
        if(j == p.length()) {
            ret.pb(i-j+1);
            j = fail[j-1];
        }
    }
    return ret;
}

ll solve(int n, string p) {
    if(dp[n] != -1) return dp[n];
    
    if(n <= 26) {
        vector<int> result = kmp(F[n], p);
        dp[n] = result.size();
    }
    else {
        int cnt = 0;
        vector<int> result = kmp(r[n-1]+l[n-2], p);
        for(auto &v: result) {
            cnt += (100001-p.length() <= v && v <= 99999);
        }
        dp[n] = solve(n-1, p)+solve(n-2, p)+cnt;
    }
    
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // F(0)~F(26) 전처리
    F[0] = "0"; F[1] = "1";
    for(int i = 2; i <= 26; i++) {
        F[i] = F[i-1]+F[i-2];
    }
    
    // l_25 ~ l_100, r_25 ~ r_100 전처리
    l[25] = l[26] = r[25] = r[26] = "";
    for(int i = 0; i < 100000; i++) {
        l[25] += F[25][i];
        l[26] += F[26][i];
        r[25] += F[25][F[25].length()-100000+i];
        r[26] += F[26][F[26].length()-100000+i];
    }
    for(int i = 27; i <= 100; i++) {
        l[i] = l[i-1]; r[i] = r[i-2];
    }
    
    int n; string p;
    int tc = 0;
    while(cin >> n >> p) {
        fill(dp, dp+101, -1);
        tc++;
        cout << "Case " << tc << ": " << solve(n, p) << '\n';
    }
    
    return 0;
}
