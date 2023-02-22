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

int solve(string s) {
    bool check[26] = {false, };
    
    for(auto &c: s) {
        check[c-'A'] = true;
    }
    
    int ans = 0;
    for(int i = 0; i < 26; i++) ans += (i+65)*(1-check[i]);
    
    return ans;
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