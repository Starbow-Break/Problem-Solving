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
    
    int N; string s; cin >> N >> s;
    
    string ans = ""; int idx = 0;
    while(idx < s.length()) {
        if(idx < s.length()-1 && s[idx] == s[idx+1]) {
            ans += s[idx]-'a'+'A'; ans += s[idx]-'a'+'A';
            idx += 2;
        }
        else {
            ans += s[idx]; idx++;
        }
    }
    
    cout << ans;
    
    return 0;
}