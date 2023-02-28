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
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

struct medal {
    int g, s, b;
    
    bool operator>(medal &m) {
        if(g != m.g) return g > m.g;
        if(s != m.s) return s > m.s;
        return b > m.b;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        int g1, s1, b1, g2, s2, b2; cin >> g1 >> s1 >> b1 >> g2 >> s2 >> b2;
        
        bool win[2];
        medal m1 = {g1, s1, b1}, m2 = {g2, s2, b2};
        
        win[0] = (g1+s1+b1) > (g2+s2+b2);
        win[1] = m1 > m2;
        
        cout << g1 << ' ' << s1 << ' ' << b1 << ' ';
        cout << g2 << ' ' << s2 << ' ' << b2 << '\n';
        
        if(win[0] && win[1]) cout << "both";
        else if(win[0]) cout << "count";
        else if(win[1]) cout << "color";
        else cout << "none";
        
        cout << '\n' << '\n';
    }
    
    return 0;
}