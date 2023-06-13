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

bool check(string &s) {
    int cnt[26] = {0, };
    
    int i = 0;
    while(i < s.length()) {
        cnt[s[i]-'A']++; i++;
        
        if(cnt[s[i-1]-'A'] == 3) {
            if(i >= s.length() || s[i] != s[i-1]) return false;
            cnt[s[i-1]-'A'] = 0; i++;
        }
    }
    
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        string s; cin >> s;
        cout << (check(s) ? "OK" : "FAKE") << '\n';
    }
    
    return 0;
}