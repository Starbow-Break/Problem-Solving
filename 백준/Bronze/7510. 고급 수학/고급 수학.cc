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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    for(int i = 1; i <= T; i++) {
        cout << "Scenario #" << i << ":" << '\n';
        
        ll len[3]; for(int j = 0; j < 3; j++) cin >> len[j];
        sort(len, len+3);
        
        if(len[0]+len[1] > len[2]) {
            cout << (len[0]*len[0]+len[1]*len[1]==len[2]*len[2] ? "yes" : "no") << '\n';
        }
        else cout << "no" << '\n';
        
        cout << '\n';
    }

    return 0;
}