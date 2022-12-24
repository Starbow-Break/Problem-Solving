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

bool check(string s) {
    stack<char> st;
    for(int i = 0; i < s.length(); i++) {
        if(!st.empty() && st.top() == s[i]) st.pop();
        else st.push(s[i]);
    }
    
    return st.empty();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    
    int ans = 0;
    while(N--) {
        string s; cin >> s;
        ans += check(s);
    }
    
    cout << ans;

    return 0;
}