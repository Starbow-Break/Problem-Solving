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

int gcd(int n, int m) {
    if(n < m) swap(n, m);
    if(m == 1) return 1;
    if(m == 0) return n;
    return gcd(m, n%m);
}

vector<int> getFail(string &s) {
    vector<int> fail; fail.push_back(0);
    int j = 0;
    for(int i = 1; i < s.length(); i++) {
        while(j != 0 && s[j] != s[i]) { j = fail[j-1]; }
        if(s[j] == s[i]) j++;
        fail.push_back(j);
    }
    return fail;
}

int solve(string &s, string &t) {
    string ss = s+s;
    vector<int> fail = getFail(t);
    
    int i = 0, j = 0, ret = 0;
    for(int i = 0, j = 0; i < ss.length()-1; i++) {
        while(j != 0 && ss[i] != t[j]) { j = fail[j-1]; }
        if(ss[i] == t[j]) j++;
        if(j == t.length()) { ret++; j = fail[j-1]; }
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    string s = "", t = "", ss;

    for(int i = 0; i < N; i++) {
        char c; cin >> c;
        t += c;
    }
    for(int i = 0; i < N; i++) {
        char c; cin >> c;
        s += c;
    }
    
    int cnt = solve(s, t);
    int g = gcd(cnt, s.length());
    
    cout << (cnt/g) << '/' << (s.length()/g);
    
    return 0;
}