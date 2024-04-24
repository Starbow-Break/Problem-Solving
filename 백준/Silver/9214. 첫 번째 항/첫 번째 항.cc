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
    
    string t;
    int tc = 0;
    while(cin >> t) {
        if(t == "0") break;
        
        tc++;
        while(t.length()%2 == 0) {
            string temp = "";
            for(int i = 0; i < t.length(); i += 2) {
                char c = t[i+1];
                int cnt = t[i] - '0';
                while(cnt--) {
                    temp += c;
                }
            }
            
            if(t == temp) break;
            t = temp;
        }
        
        cout << "Test " << tc << ": ";
        cout << t << '\n';
    }
    
    return 0;
}