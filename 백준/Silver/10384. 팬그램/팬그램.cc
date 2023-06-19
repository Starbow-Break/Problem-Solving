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

int cnt[26] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T; cin.ignore();
    for(int tc = 1; tc <= T; tc++) {
        cout << "Case " << tc << ": ";
        fill(cnt, cnt+26, 0);
        string s;
        getline(cin, s);
        for(auto &c: s) {
            if('A' <= c && c <= 'Z') cnt[c-'A']++;
            if('a' <= c && c <= 'z') cnt[c-'a']++;
        }
        
        int ans = 10000;
        for(int i = 0; i < 26; i++) ans = min(ans, cnt[i]);
        
        if(ans >= 3) cout << "Triple pangram!!!";
        else if(ans == 2) cout << "Double pangram!!";
        else if(ans == 1) cout << "Pangram!";
        else cout << "Not a pangram";
        cout << '\n';
    }

    return 0;
}