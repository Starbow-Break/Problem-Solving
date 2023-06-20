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

struct homework {
    int a, t;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N; int score = 0;
    stack<homework> s;
    while(N--) {
        int q; cin >> q;
        if(q == 1) {
            int a, t; cin >> a >> t;
            s.push({a, t});
        }
        
        if(!s.empty()) {
            s.top().t--;
            if(s.top().t == 0) {
                score += s.top().a;
                s.pop();
            }
        }
    }
    
    cout << score;

    return 0;
}