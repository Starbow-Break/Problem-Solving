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

char arr[30][30];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for(int r = 0; r < 30; r++) {
        for(int c = 0; c < 30; c++) arr[r][c] = '.';
    }
    
    string s, t; cin >> s >> t;
    for(int i = 0; i < s.length(); i++) {
        for(int j = 0; j < t.length(); j++) {
            if(s[i] == t[j]) {
                for(int c = 0; c < s.length(); c++) {
                    arr[j][c] = s[c];
                }
                for(int r = 0; r < t.length(); r++) {
                    arr[r][i] = t[r];
                }
                
                for(int i = 0; i < t.length(); i++) {
                    for(int j = 0; j < s.length(); j++) {
                        cout << arr[i][j];
                    }
                    cout << '\n';
                }
                return 0;
            }
        }
    }
    
    return 0;
}