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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s; cin >> s;
    stack<int> st;
    
    ll ans = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(') st.push(i);
        else {
            int t = st.top(); st.pop();
            if(t+1 == i) ans += st.size();
            else ans++;
        }
    }
    
    cout << ans;

    return 0;
}