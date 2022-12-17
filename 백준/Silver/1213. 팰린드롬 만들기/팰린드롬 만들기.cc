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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int cnt[26] = {0, };
string s; int t;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> s; t = s.length()%2;
    for(int i = 0; i < s.length(); i++) {
        cnt[s[i]-'A']++;
    }
    
    for(int i = 0; i < 26; i++) {
        if(cnt[i]%2) { t--; }
    }
    
    if(t < 0) cout << "I'm Sorry Hansoo";
    else {
        string ans = ""; int c = -1;
        for(int i = 0; i < 26; i++) {
            if(cnt[i]%2) { c = i; cnt[i]--; }
            
            for(int j = 0; j < cnt[i]/2; j++) {
                ans += (char)(i+'A');
            }
            cnt[i] /= 2;
        }
        
        if(c != -1) ans += (char)(c+'A');
        
        for(int i = 25; i >= 0; i--) {
            for(int j = 0; j < cnt[i]; j++) {
                ans += (char)(i+'A');
            }
        }
        
        cout << ans;
    }

    return 0;
}