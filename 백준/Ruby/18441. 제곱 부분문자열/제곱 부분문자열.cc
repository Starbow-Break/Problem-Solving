#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <map>
#include <cmath>
#include <iomanip>
#define MAX 3000

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second;
    return out;
}

int ih[MAX+1][MAX+1], iv[MAX+1][MAX+1];
int dp[MAX+1][MAX+1] = {0, };

//s[..i], s[i..]의 LCS 구하기
string getLCS(string &s, int i) {
    int len = s.length();
    for(int a = 1; a <= i; a++) {
        for(int b = i+1; b <= len; b++) {
            if(s[a-1] == s[b-1]) dp[a][b] = dp[a-1][b-1]+1;
            else dp[a][b] = max(dp[a-1][b], dp[a][b-1]);
        }
    }
    
    string ret = "";
    int r = i, c = len;
    while(dp[r][c] > 0) {
        if(s[r-1] == s[c-1]) {
            ret = s[r-1]+ret;
            r--; c--;
        }
        else {
            if(dp[r-1][c] == dp[r][c]) r--;
            else c--;
        }
    }
    
    for(int a = 1; a <= i; a++) {
        fill(dp[a]+i+1, dp[a]+len+1, 0);
    }
    
    return ret;
}

//ALCS 알고리즘 (여기서는 C[(0, i), (i, N)]을 구해서 해당 값이 최대인 i를 구한다.)
int alcs(string &s) {
    int len = s.length();
    //ih, iv 구하기
    for(int i = 0; i <= len; i++) {
        ih[0][i] = i; iv[i][0] = 0;
    }
    for(int i = 1; i <= len; i++) {
        for(int j = 1; j <= len; j++) {
            if(s[i-1] == s[j-1]) {
                ih[i][j] = iv[i][j-1]; iv[i][j] = ih[i-1][j];
            }
            else {
                ih[i][j] = max(iv[i][j-1], ih[i-1][j]);
                iv[i][j] = min(iv[i][j-1], ih[i-1][j]);
            }
        }
    }
    
    int maxV = 0, ret = 1;
    for(int i = 1; i < len; i++) {
        int cur = 0;
        for(int j = i+1; j <= len; j++) {
            cur += (ih[i][j] <= i);
        }
        if(maxV < cur) {
            maxV = cur; ret = i;
        }
    }
    
    return ret;
}

//제곱 부분문자열 구하기
string solve(string &s) {
    int idx = alcs(s);
    string lcs = getLCS(s, idx);
    return lcs+lcs;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        string s; cin >> s;
        string ans = solve(s);
        cout << "Case #" << tc << ": " << ans.length() << '\n';
        if(ans != "") cout << ans << '\n';
    }

    return 0;
}