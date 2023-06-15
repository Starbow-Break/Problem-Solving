#define private public
#include <bitset>
#undef private
#include <bits/stdc++.h>
#include <x86intrin.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int dp[1'001][1'001] = {0, };

string getLCS(string &s, string &t) {
    string ret = "";
    
    for(int a = 1; a <= s.length(); a++) {
        for(int b = 1; b <= t.length(); b++) {
            if(s[a-1] == t[b-1])
                dp[a][b] = dp[a-1][b-1]+1;
            else
                dp[a][b] = max(dp[a-1][b], dp[a][b-1]);
        }
    }
    
    int r = s.length(), c = t.length();
    while(r > 0 && c > 0) {
        if(s[r-1] == t[c-1]) {
            ret = s[r-1] + ret;
            r--; c--;
        }
        else {
            if(dp[r][c] == dp[r][c-1]) c--;
            else r--;
        }
    }
    
    return ret;
}

int main() {
    string s, t; cin >> s >> t;
    string lcs = getLCS(s, t);
    
    cout << lcs.length() << '\n' << lcs;
}