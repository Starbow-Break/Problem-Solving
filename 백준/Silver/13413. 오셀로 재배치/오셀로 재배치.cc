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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        string s, t; cin >> s >> t;
        int numS = 0, numT = 0, cnt = 0;
        for(int i = 0; i < N; i++) {
            if(s[i] == 'W') numS++;
            if(t[i] == 'W') numT++;
            if(s[i] != t[i]) cnt++;
        }
        
        cout << abs(numS-numT)+(cnt-abs(numS-numT))/2 << '\n';
    }

    return 0;
}