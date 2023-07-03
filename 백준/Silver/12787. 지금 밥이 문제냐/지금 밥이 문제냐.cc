#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second << '\n';
    return out;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        int q; cin >> q;
        if(q == 1) {
            string s; cin >> s;
            int t = 0; ull ans = 0;
            for(auto &c: s) {
                if(c == '.') {
                    ans <<= 8;
                    ans += t; t = 0;
                }
                else {
                    t *= 10; t += c-'0';
                }
            }
            ans <<= 8; ans += t;
            cout << ans;
        }
        else {
            ull v; cin >> v;
            int ipv8[8];
            for(int i = 0; i < 8; i++) {
                ipv8[i] = v%256;
                v /= 256;
            }
            for(int i = 7; i >= 0; i--) {
                cout << ipv8[i];
                if(i > 0) cout << '.';
            }
        }
        cout << '\n';
    }

    return 0;
}