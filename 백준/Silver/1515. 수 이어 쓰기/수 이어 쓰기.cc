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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s; cin >> s;
    int ans = 0, idx = 0;
    
    stack<int> st;
    while(idx < s.length()) {
        ans++;
        
        int temp = ans;
        while(temp) {
            st.push(temp%10);
            temp /= 10;
        }
        
        while(!st.empty()) {
            int v = st.top(); st.pop();
            if(idx < s.length() && s[idx] == '0'+v) {
                idx++;
            }
        }
    }
    
    cout << ans;
    
    return 0;
}