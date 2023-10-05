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
    int arr[100] = {0, };
    vector<int> blank;
    bool hasL = false;
    
    for(int i = 0; i < s.length(); i++) {
        char c = s[i];
        if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') arr[i] = 2;
        else if(c != '_') arr[i] = 1;
        else {
            blank.pb(i);
        }
        
        if(c == 'L') hasL = true;
    }
    
    ll ans = 0;
    if(hasL) {
        int sz = blank.size();
        for(int i = 0; i < 1<<sz; i++) {
            ll cur = 1;
            for(int j = 0; j < sz; j++) {
                arr[blank[j]] = ((i & 1<<j) > 0)+1;
                cur *= ((i & 1<<j) ? 5 : 21);
            }
            
            bool check = true;
            for(int i = 0; i < s.length()-2; i++) {
                if(arr[i] == arr[i+1] && arr[i+1] == arr[i+2]) check = false;
            }
            
            ans += check*cur;
        }
    }
    else {
        int sz = blank.size();
        for(int i = 0; i < 1<<sz; i++) {
            ll cur = 1, minus = 1;
            for(int j = 0; j < sz; j++) {
                arr[blank[j]] = ((i & 1<<j) > 0)+1;
                cur *= ((i & 1<<j) ? 5 : 21);
                minus *= ((i & 1<<j) ? 5 : 20);
            }
            
            bool check = true;
            for(int i = 0; i < s.length()-2; i++) {
                if(arr[i] == arr[i+1] && arr[i+1] == arr[i+2]) check = false;
            }
            
            ans += check*(cur-minus);
        }
    }
    
    cout << ans;
    
    return 0;
}