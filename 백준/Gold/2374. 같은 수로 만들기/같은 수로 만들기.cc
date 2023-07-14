#include <bits/stdc++.h>

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second;
    return out;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    int A[n];
    for(int i = 0; i < n; i++) cin >> A[i];
    
    stack<int> s; ll ans = 0;
    s.push(A[0]);
    for(int i = 1; i < n; i++) {
        if(s.top() <= A[i]) {
            ans += A[i]-s.top();
            while(!s.empty() && s.top() <= A[i]) s.pop();
        }
        s.push(A[i]);
    }
    
    
    while(s.size() >= 2) {
        int t = s.top(); s.pop();
        ans += s.top()-t;
    }
    
    cout << ans;

    return 0;
}