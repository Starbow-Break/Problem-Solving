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
    while(T--) {
        int K; cin >> K;
        vector<int> ans;
        while(K > 0) {
            ans.push_back(K%3);
            K /= 3;
        }
        
        reverse(ans.begin(), ans.end());
        for(auto &v: ans) cout << v << ' ';
        cout << '\n';
    }

    return 0;
}