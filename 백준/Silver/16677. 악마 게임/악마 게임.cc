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

double calc(string &ori, string &s, int g) {
    int idx = 0;
    for(int i = 0; i < s.length() && idx < ori.length(); i++) {
        if(ori[idx] == s[i]) idx++;
    }
    
    return (idx == ori.length() ? (double)g/(s.length()-ori.length()) : -1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    double maxG = 0; string ans = "No Jam";
    string ori; cin >> ori;
    int T; cin >> T;
    while(T--) {
        string s; int g; cin >> s >> g;
        double cur = calc(ori, s, g);
        if(maxG < cur) {
            ans = s; maxG = cur;
        }
    }
    
    cout << ans;

    return 0;
}