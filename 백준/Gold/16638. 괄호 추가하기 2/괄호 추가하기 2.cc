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

int N;

stack<ll> st; stack<char> op;
ll calculate(string s, int status) {
    bool flag = false;
    
    for(int i = 0; i < N; i++) {
        if(i%2) {
            op.push(s[i]);
        }
        else {
            if((status & (1<<(i/2))) && !flag) {
                flag = true;
                status ^= (1<<(i/2));
                op.push('(');
            }
            
            st.push(s[i]-'0');
            if(!op.empty() && op.top() == '*') {
                op.pop();
                ll a = st.top(); st.pop();
                ll b = st.top(); st.pop();
                
                st.push(a*b);
            }
            
            if((status & (1<<(i/2))) && flag) {
                flag = false;
                status ^= (1<<(i/2));
                
                ll v = 0;
                while(1) {
                    ll w = st.top(); st.pop();
                    char c = op.top(); op.pop();
                    
                    if(c == '-') v += -w;
                    else v += w;
                    
                    if(c == '(') break;
                }
                
                if(!op.empty() && op.top() == '*') {
                    op.pop();
                    ll w = st.top(); st.pop();
                    v *= w;
                }
                
                st.push(v);
            }
        }
    }
    
    ll ans = 0;
    while(!op.empty()) {
        ll w = st.top(); st.pop();
        char c = op.top(); op.pop();
                    
        if(c == '-') ans += -w;
        else ans += w;
    }
    
    ans += st.top();
    
    return ans;
}

bool check(int status) {
    int cnt = 0;
    
    for(int i = 0; i < 10; i++) {
        if(status & (1<<i)) {
            cnt++;
        }
        else {
            if(cnt%2) return false;
            cnt = 0;
        }
    }
    
    return (cnt%2 == 0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s;
    cin >> N >> s;
    
    ll ans = (ll)(-1e18);
    for(int status = 0; status < (1<<(N+1)/2); status++) {
        if(check(status)) {
            ans = max(ans, calculate(s, status));
        }
    }
    
    cout << ans;

    return 0;
}