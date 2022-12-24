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

bool solve(string s) {
    stack<int> st;
    
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'P') st.push(1);
        else {
            if(i != s.length()-1 && s[i+1] == 'P') {
                if(st.size() < 2) return false;
                st.pop(); st.pop();
            }
            else return false;
        }
    }
    
    return (st.size() == 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s; cin >> s;
    
    cout << (solve(s) ? "PPAP" : "NP");

    return 0;
}