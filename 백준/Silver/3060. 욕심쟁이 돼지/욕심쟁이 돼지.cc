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

int n;
int need[6], temp[6];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        cin >> n;
        for(int i = 0; i < 6; i++) cin >> need[i];
        
        int ans = 0;
        while(1) {
            ll t = 0; ans++;
            for(int i = 0; i < 6; i++) t += need[i];
            
            if(n < t) break;
            
            temp[0] = need[0]+need[3]+need[1]+need[5];
            temp[1] = need[1]+need[0]+need[2]+need[4];
            temp[2] = need[2]+need[1]+need[3]+need[5];
            temp[3] = need[3]+need[2]+need[4]+need[0];
            temp[4] = need[4]+need[3]+need[5]+need[1];
            temp[5] = need[5]+need[0]+need[4]+need[2];
            
            for(int i = 0; i < 6; i++) need[i] = temp[i];
        }
        
        cout << ans << '\n';
    }

    return 0;
}