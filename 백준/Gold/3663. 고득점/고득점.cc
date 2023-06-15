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

const int INF = 1'000'000'000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        string s; cin >> s; int len = s.length();
        int ans = INF, cur = 0, cnt = 0;
        for(int i = 0; i < len; i++) {
            cur += min((26+'A'-s[i])%26, (26+s[i]-'A')%26);
            cur++;
            
            if(i != 0 && s[i] == 'A') cnt++;
            else cnt = 0;
        }
        cur -= (1+cnt);
        ans = min(ans, cur);
        
        cur = 0, cnt = 0;
        cur += min((26+'A'-s[0])%26, (26+s[0]-'A')%26); cur++;
        for(int i = len-1; i >= 1; i--) {
            cur += min((26+'A'-s[i])%26, (26+s[i]-'A')%26);
            cur++;
            
            if(s[i] == 'A') cnt++;
            else cnt = 0;
        }
        cur -= (1+cnt);
        ans = min(ans, cur);
        
        for(int k = 1; k <= len-1; k++) {
            cur = 0, cnt = 0;
            for(int i = 0; i <= k; i++) {
                cur += min((26+'A'-s[i])%26, (26+s[i]-'A')%26);
                cur++;
                
                if(i != 0 && s[i] == 'A') cnt++;
                else cnt = 0;
            }
            cur--; cur += (k+1); cnt += k;
            for(int i = len-1; i > k; i--) {
                cur += min((26+'A'-s[i])%26, (26+s[i]-'A')%26);
                cur++;
                
                if(s[i] == 'A') cnt++;
                else cnt = 0;
            }
            cur -= (1+cnt);
            ans = min(ans, cur);
            
            cur = 0, cnt = 0;
            cur += min((26+'A'-s[0])%26, (26+s[0]-'A')%26); cur++;
            for(int i = len-1; i >= k; i--) {
                cur += min((26+'A'-s[i])%26, (26+s[i]-'A')%26);
                cur++;
                
                if(s[i] == 'A') cnt++;
                else cnt = 0;
            }
            cur--; cur += (len-k+1); cnt += (len-k);
            for(int i = 1; i < k; i++) {
                cur += min((26+'A'-s[i])%26, (26+s[i]-'A')%26);
                cur++;
                
                if(s[i] == 'A') cnt++;
                else cnt = 0;
            }
            cur -= (1+cnt);
            ans = min(ans, cur);
        }
        
        cout << ans << '\n';
    }

    return 0;
}