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
    
    int N; cin >> N;
    vector<string> words;
    
    for(int i = 0; i < N; i++) {
        string s; cin >> s;
        words.push_back(s);
    }
    
    bool check[N];
    fill(check, check+N, true);
    
    for(int i = 0; i < N; i++) {
        if(check[i]) {
            for(int j = i+1; j < N; j++) {
                if(words[i].length() == words[j].length()) {
                    for(int k = 0; k < words[i].length(); k++) {
                        bool ch = true;
                        for(int l = 0; l < words[i].length(); l++) {
                            
                            if(words[i][l] != words[j][(l+k)%words[i].length()]) {
                                ch = false;
                                break;
                            }
                        }
                        
                        if(ch) {
                            check[j] = false;
                            break;
                        }
                    }
                }
            }
        }
    }
    
    int ans = 0;
    for(int i = 0; i < N; i++) {
        ans += check[i];
    }
    cout << ans;
    
    return 0;
}
