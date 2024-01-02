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

int arr[6] = {'a', 'i', 'y', 'e', 'o', 'u'};
int brr[20] = {
    'b', 'k', 'x', 'z', 'n', 'h', 
    'd', 'c', 'w', 'g', 'p', 'v', 
    'j', 'q', 't', 's', 'r', 'l', 
    'm', 'f'
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s;
    while(getline(cin, s)) {
        string ans = "";
        for(auto &c: s) {
            if('A' <= c && c <= 'Z') {
                char cc = c-'A'+'a';
                if(cc == 'a' || cc == 'i' || cc == 'y' || cc == 'e' || cc == 'o' || cc == 'u') {
                    for(int i = 0; i < 6; i++) {
                        if(arr[i] == cc) {
                            ans += arr[(i+3)%6]-'a'+'A';
                        }
                    }
                }
                else {
                    for(int i = 0; i < 20; i++) {
                        if(brr[i] == cc) {
                            ans += brr[(i+10)%20]-'a'+'A';
                        }
                    }
                }
            }
            else if('a' <= c && c <= 'z') {
                if(c == 'a' || c == 'i' || c == 'y' || c == 'e' || c == 'o' || c == 'u') {
                    for(int i = 0; i < 6; i++) {
                        if(arr[i] == c) {
                            ans += arr[(i+3)%6];
                        }
                    }
                }
                else {
                    for(int i = 0; i < 20; i++) {
                        if(brr[i] == c) {
                            ans += brr[(i+10)%20];
                        }
                    }
                }
            }
            else {
                ans += c;
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}
