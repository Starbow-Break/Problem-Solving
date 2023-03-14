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

string s[2]; int cnt[26][2] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for(int i = 0; i < 2; i++) {
        cin >> s[i];
        for(int j = 0; j < s[i].length(); j++) cnt[s[i][j]-'a'][i]++;
    }
    
    int ans = 0;
    for(int i = 0; i < 26; i++) {
        ans += abs(cnt[i][0]-cnt[i][1]);
    }
    
    cout << ans;
    
    return 0;
}