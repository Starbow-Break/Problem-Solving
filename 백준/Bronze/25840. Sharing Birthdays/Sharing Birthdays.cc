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

int cnt[13][32] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        string s; cin >> s;
        int m = (s[0]-'0')*10+(s[1]-'0');
        int d = (s[3]-'0')*10+(s[4]-'0');
        
        cnt[m][d]++;
    }
    
    int ans = 0;
    for(int m = 1; m <= 12; m++) {
        for(int d = 1; d <= 31; d++) {
            ans += (cnt[m][d] > 0);
        }
    }
    
    cout << ans;

    return 0;
}
