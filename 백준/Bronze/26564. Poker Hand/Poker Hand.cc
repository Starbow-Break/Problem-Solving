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

const double golden = (sqrt(5)+1)/2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int cnt[14];
    int T; cin >> T;
    while(T--) {
        fill(cnt, cnt+14, 0);
        
        string s;
        for(int i = 1; i <= 5; i++) {
            cin >> s;
            if('2' <= s[0] && s[0] <= '9') cnt[s[0]-'0']++;
            else {
                if(s[0] == 'A') cnt[1]++;
                if(s[0] == 'T') cnt[10]++;
                if(s[0] == 'J') cnt[11]++;
                if(s[0] == 'Q') cnt[12]++;
                if(s[0] == 'K') cnt[13]++;
            }
        }
        
        int ans = 0;
        for(int i = 1; i <= 13; i++) ans = max(ans, cnt[i]);
        
        cout << ans << '\n';
    }
    
    return 0;
}