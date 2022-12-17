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

int N; string s;
int value[26];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> s;
    for(int i = 0; i < N; i++) { cin >> value[i]; }
    
    stack<double> st;
    for(int i = 0; i < s.length(); i++) {
        if('A' <= s[i] && s[i] <= 'Z') {
            st.push(value[s[i]-'A']);
        }
        else if(s[i] == '+') {
            double x = st.top(); st.pop();
            double y = st.top(); st.pop();
            st.push(x+y);
        }
        else if(s[i] == '-') {
            double x = st.top(); st.pop();
            double y = st.top(); st.pop();
            st.push(y-x);
        }
        else if(s[i] == '*') {
            double x = st.top(); st.pop();
            double y = st.top(); st.pop();
            st.push(x*y);
        }
        else {
            double x = st.top(); st.pop();
            double y = st.top(); st.pop();
            st.push(y/x);
        }
    }
    
    cout << fixed; cout.precision(2);
    cout << st.top();

    return 0;
}