#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define pb push_back 
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define compress(vec) sort(all(vec)); vec.erase(unique(all(vec)), vec.end());

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using int128 = __int128_t;

int secondTop(stack<int> &s) {
    int a = s.top(); s.pop();
    int ret = s.top();
    s.push(a);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; string st;
    cin >> N >> st;
    
    stack<int> s;
    for(int i = 0; i < N; i++) {
        if(st[i] == '(') s.push(1);
        else {
            if(s.size() >= 1 && s.top() == 1) {
                s.pop();
                s.push(2);
            }
            else if(s.size() >= 2 && secondTop(s) == 1) {
                int t = s.top(); s.pop();
                s.pop();
                s.push(t+2);
            }
            else s.push(-1);
            
            while(s.size() >= 2 && s.top() > 1 && secondTop(s) > 1) {
                int a = s.top(); s.pop();
                s.top() += a;
            }
        }
    }
    
    int ans = 0;
    while(!s.empty()) {
        if(s.top() >= 2) {
            ans = max(ans, s.top());
        }
        s.pop();
    }
    
    cout << ans;
    
    return 0;
}
