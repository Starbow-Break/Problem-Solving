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

int x = 0, y = 0, d = 0;

void reset() {
    x = y = d = 0;
}

int solve(string command) {
    reset();
    
    int minX = 0, maxX = 0;
    int minY = 0, maxY = 0;
    
    for(auto &c: command) {
        if(c == 'L') d = (d+1)%4;
        else if(c == 'R') d = (d+3)%4;
        else {
            int _d = d+(c == 'B' ? 2 : 0); _d %= 4;
            int dx = (_d%2)*(_d == 1 ? -1 : 1);
            int dy = ((_d+1)%2)*(_d == 2 ? -1 : 1);
            
            x += dx; y += dy;
            minX = min(minX, x); maxX = max(maxX, x);
            minY = min(minY, y); maxY = max(maxY, y);
        }
    }
    
    return (maxX-minX)*(maxY-minY);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        string s; cin >> s;
        cout << solve(s) << '\n';
    }

    return 0;
}