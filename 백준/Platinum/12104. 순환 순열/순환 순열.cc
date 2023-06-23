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

ostream& operator<<(ostream &out, const pair<char, char> &p) {
    out << p.first << ' ' << p.second;
    return out;
}

//실패함수 구하기
vector<int> getFail(string &s) {
    vector<int> fail;
    int j = 0;
    fail.push_back(j);
    for(int i = 1; i < s.length(); i++) {
        while(j > 0 && s[j] != s[i]) j = fail[j-1];
        if(s[j] == s[i]) j++;
        fail.push_back(j);
    }
    return fail;
}

//KMP
int kmp(string &s, string &t) {
    vector<int> fail = getFail(t);
    int ret = 0;
    for(int i = 0, j = 0; i < s.length()-1; i++) {
        while(j > 0 && s[i] != t[j]) j = fail[j-1];
        if(s[i] == t[j]) j++;
        if(j == t.length()) {
            ret++; j = fail[j-1];
        }
    }
    return ret;
}

int solve(string &a, string &b) {
    string bb = b+b;
    return kmp(bb, a);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string a, b; cin >> a >> b;
    cout << solve(a, b);
    
    return 0;
}