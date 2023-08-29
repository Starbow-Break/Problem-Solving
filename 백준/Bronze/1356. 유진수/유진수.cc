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
    if(s.length() == 1) {
        cout << "NO";
        return 0;
    }
    
    for(int i = 0; i < s.length()-1; i++) {
        int left = 1, right = 1;
        for(int j = 0; j < s.length(); j++) {
            if(j <= i) {
                left *= s[j]-'0';
            }
            else {
                right *= s[j]-'0';
            }
        }
        
        if(left == right) {
            cout << "YES";
            return 0;
        }
    }
    
    cout << "NO";
    
    return 0;
}