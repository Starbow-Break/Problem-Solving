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
    
    int N; cin >> N;
    string s; int cnt[26] = {0, }; int ans = 0;
    for(int i = 1; i <= N; i++) {
        if(i == 1) {
            cin >> s;
            for(int j = 0; j < s.length(); j++) { cnt[s[j]-'A']++; }
        }
        else {
            int cnt2[26] = {0, }; string t;
            cin >> t; int a = 0, b = 0; bool c = true;
            for(int j = 0; j < t.length(); j++) { cnt2[t[j]-'A']++; }
            for(int j = 0; j < 26; j++) {
                a += (cnt[j]-cnt2[j]); b += (cnt[j] != cnt2[j]);
                if(abs(cnt[j]-cnt2[j]) > 1) c = false;
            }
            
            if(c && ((a == -1 && b == 1) || (a == 1 && b == 1)
                || (a == 0 && b == 0) || (a == 0 && b == 2))) {
                    ans++;
                }
        }
    }
    
    cout << ans;

    return 0;
}