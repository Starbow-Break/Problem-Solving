#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s, t;
    getline(cin, s); getline(cin, t);
    
    int ans = 0; int idx = 0;
    int ls = s.length(); int lt = t.length();
    while(idx <= ls-lt) {
        int i;
        for(i = 0; i < t.length(); i++) {
            if(s[i+idx] != t[i]) break;
        }
        
        if(i == t.length()) {
            idx += t.length();
            ans++;
        }
        else idx++;
    }
    
    cout << ans;

    return 0;
}