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
    
    int T; cin >> T;
    if(T == 1) {
        ll A, B; cin >> A >> B;
        string s = "";
        
        ll temp = A+B;
        while(temp > 0) {
            s = (char)('a'+temp%26)+s;
            temp /= 26;
        }
        
        while(s.length() < 13) {
            s = 'a'+s;
        }
        
        cout << s;
    }
    else {
        string s; cin >> s;
        ll sum = 0;
        for(int i = 0; i < 13; i++) {
            sum = sum*26+(s[i]-'a');
        }
        cout << sum;
    }
    
    return 0;
}