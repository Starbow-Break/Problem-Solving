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

const double PI = 3.141592653589793;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second;
    return out;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s; cin >> s;
    string t = "quack";
    
    queue<int> q;
    int ans = 0;
    while(1) {
        while(!q.empty()) q.pop();
        
        bool check = false;
        for(int i = 0, j = 0; i < s.length(); i++) {
            if(s[i] == t[j]) {
                q.push(i); j++;
            }
            
            if(j == 5) {
                check = true;
                while(!q.empty()) {
                    s[q.front()] = '#';
                    q.pop();
                }
                j = 0;
            }
        }
        
        if(!check) break;
        ans++;
    }
    
    for(auto &c: s) {
        if(c != '#') {
            cout << -1; return 0;
        }
    }
    cout << ans;

    return 0;
}