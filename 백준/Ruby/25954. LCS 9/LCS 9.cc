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
#define MAX 7000

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

ll solve(string &s, string &t) {
    int lenS = s.length(), lenT = t.length();
    //ih, iv 구하기
    for(int j = 0; j <= lenT; j++) ih[0][j] = j;
    for(int i = 0; i <= lenS; i++) iv[i][0] = 0;
    
    for(int i = 1; i <= lenS; i++) {
        for(int j = 1; j <= lenT; j++) {
            if(s[i-1] == t[j-1]) {
                ih[i][j] = iv[i][j-1];
                iv[i][j] = ih[i-1][j];
            }
            else {
                ih[i][j] = max(iv[i][j-1], ih[i-1][j]);
                iv[i][j] = min(iv[i][j-1], ih[i-1][j]);
            }
        }
    }
    
    ll ret = 0;
    for(int i = 1; i <= lenS; i++) {
        for(int r = 1; r <= lenT; r++) {
            ret += (lenT+1-r)*(r-ih[i][r]);
        }
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s, t; cin >> s >> t;
    cout << solve(s, t);

    return 0;
}